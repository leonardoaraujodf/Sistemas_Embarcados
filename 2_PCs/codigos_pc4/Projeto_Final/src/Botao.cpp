/*
 * Botao.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: pi
 */

#include "Botao.h"

void GPIO_Setup(int num) {
	//Funcao que recebe o numero da GPIO a ser criada como entrada
	//e retorna o descritor de arquivo do arquivo value da GPIO criada.
	int fd;
	char str[50];
	fd = open("/sys/class/gpio/export", O_WRONLY);
	if (fd == -1) {
		cout << "Erro ao abrir /sys/class/gpio/export" << endl;
	} else {
		sprintf(str, "%d", num);
		if (write(fd, str, 2) != 2) {
			cout << "Erro: Nao foi possivel criar a GPIO " << num << endl;
		} else {
			close(fd); //fechar o arquivo export
			sprintf(str, "/sys/class/gpio/gpio%d/direction", num);
			int gpio_direction;
			gpio_direction = open(str, O_WRONLY);
			if (gpio_direction == -1) {
				cout << "Erro ao abrir o arquivo " << str << endl;
			} else {
				if (write(gpio_direction, "in", 2) != 2) {
					cout << "Erro ao definir direcao para GPIO " << num << endl;
				} else {
					close(gpio_direction);
					//int gpio_value;
					//sprintf(str, "/sys/class/gpio/gpio%d/value", num);
					//gpio_value = open(str, O_RDONLY);
					//if (gpio_value == -1) {
					//	cout << "Erro ao abrir " << str << endl;
					//} else {
					cout << "GPIO " << num << " configurada como entrada."
							<< endl;
					//			<< endl;
					//	return gpio_value;
				}
			}

		}
	}
}

void *Verifica_Navegar(void *d) {
	struct Decisao *decisao;
	decisao = (struct Decisao*) d;
	while (1) {
		while (GPIO_get(decisao->GPIO[0]))
			;
		usleep(150000);
		decisao->navegar = 0;
		while (GPIO_get(decisao->GPIO[0]) == 0)
			;
		usleep(150000);
		decisao->navegar = 1;
	}
	return NULL;

}

void *Verifica_Selecao(void *d) {
	struct Decisao *decisao;
	decisao = (struct Decisao*) d;
	while (1) {
		while (GPIO_get(decisao->GPIO[1]))
			;
		usleep(100000);
		decisao->selecionar = 0;
		while (GPIO_get(decisao->GPIO[1]) == 0)
			;
		usleep(100000);
		decisao->selecionar = 1;
	}
	return NULL;

}

void *Verifica_Voltar(void *d) {
	struct Decisao *decisao;
	decisao = (struct Decisao*) d;
	while (1) {
		while (GPIO_get(decisao->GPIO[2]))
			;
		usleep(150000);
		decisao->voltar = 0;
		while (GPIO_get(decisao->GPIO[2]) == 0)
			;
		usleep(150000);
		decisao->voltar = 1;
	}
	return NULL;

}

int GPIO_get(int GPIOnum) {
	int fd,iValue;
	char cValue[1],str[50];
	sprintf(str,"/sys/class/gpio/gpio%d/value",GPIOnum);
	fd = open(str,O_RDONLY);
	if(fd == -1){
		cout << "Erro ao abrir " << str << endl;
	}
	read(fd, cValue, 1);
	iValue = atoi(cValue);
	close(fd);
	return iValue;

}

void Configurar_Botoes(Decisao *decisao) {
	GPIO_Setup(decisao->GPIO[0]);
	GPIO_Setup(decisao->GPIO[1]);
	GPIO_Setup(decisao->GPIO[2]);

//criando as tres threads dos botoes
	pthread_create(&(decisao->thread_id[0]), NULL, &Verifica_Navegar, decisao);
	pthread_create(&(decisao->thread_id[1]), NULL, &Verifica_Selecao, decisao);
	pthread_create(&(decisao->thread_id[2]), NULL, &Verifica_Voltar, decisao);
	decisao->opcao_atual = 0;
	decisao->opcao_anterior = 1;
}

void GPIO_free(Decisao *decisao) {
//cancelando as threads
	pthread_cancel(decisao->thread_id[0]);
	pthread_cancel(decisao->thread_id[1]);
	pthread_cancel(decisao->thread_id[2]);

//excluindo as GPIOs usando unexport

	int fd;
	char str[50];
	fd = open("/sys/class/gpio/unexport", O_WRONLY);
	if (fd == -1) {
		cout << "Nao foi possivel abrir o arquivo /sys/class/gpio/unexport"
				<< endl;
	} else {
		sprintf(str, "%d", decisao->GPIO[0]);
		write(fd, str, 2);
		sprintf(str, "%d", decisao->GPIO[1]);
		write(fd, str, 2);
		sprintf(str, "%d", decisao->GPIO[2]);
		write(fd, str, 2);
		close(fd);
	}
}

