Para todas as questões, compile-as com o gcc e execute-as via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

```C
int main()
{
	FILE *fp;
	fp = fopen("ola_mundo.txt","w");
	if (!fp)
	{
		printf("Erro na abertura do arquivo. Fim do programa.");
		exit(1);
	}
	fputs("Ola mundo!!!\n", fp);
	fclose(fp);
	return 0;
}
```

2. Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Digite a sua idade: 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```
- Codigo criado:

```C
int main()
{
	char nome[50];
	int idade;
	FILE *fp;
	printf("Digite o seu nome: ");
	gets(nome);
	printf("Digite a sua idade: ");
	scanf("%d",&idade);
	fp = fopen("Eu.txt","w");
	if(!fp)
	{
		printf("Erro na abertura do arquivo. Fim do programa.");
		exit(1);
	}
	fprintf(fp,"Nome: %s\nIdade: %d anos\n",nome,idade);
	fclose(fp);
	return(0);
}
```

3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```
```C
#include<stdio.h>
#include<stdlib.h>

int main(int arc, char *argv[])
{
	FILE *fp;
	fp = fopen("Eu.txt","w");
	if(!fp)
	{
		printf("Erro na abertura do arquivo. Fim do programa.");
		exit(1);
	}
	fprintf(fp,"Nome: %s\nIdade: %d\n",argv[1],atoi(argv[2]));
	fclose(fp);
	return(0);
}
```


4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

```C
int Tam_arq_text(char *nome_arquivo)
{
	FILE *fp;
	fp = fopen(nome_arquivo,"r");
	if(!fp)
	{
		printf("Erro ao abrir arquivo. Fim do programa.");
		exit(1);
	}
	int caracteres=0;
	while(getc(fp)!= EOF)
		caracteres++;
	fclose(fp);
	return caracteres-1;
}
```

5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `void le_arq_texto(char *nome_arquivo, char *conteúdo);` Repare que o conteúdo do arquivo é armazenado no vetor `conteudo[]`. Ou seja, ele é passado por referência. Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.

```C
void le_arq_texto(char *nome_arquivo, char *conteudo)
{
	/*Recebe o nome do arquivo e um vetor em que será retornado o conteúdo do arquivo.*/
	int tamanho_arquivo = Tam_arq_text(nome_arquivo);
	conteudo = (char*)malloc(tamanho_arquivo*sizeof(char));
	FILE *fp;
	fp = fopen(nome_arquivo,"r");
	if(!fp)
	{
		printf("Erro ao abrir o arquivo. Fim do programa.");
		exit(1);
	}
	if(fgets(conteudo,sizeof(char)*tamanho_arquivo,fp)!=NULL);
	{
		puts(conteudo);
	}
	fclose(fp);
	free(conteudo);
}

```

6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```
```C
#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main (int argc, char *argv[])
{
	char *p;
	le_arq_texto(argv[1],p);
	return 0;
}
```


7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```
```C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	/*
	 *argv[0] -> busca_e_conta
	 *argv[1] -> string que deseja-se verificar
	 *argv[2] -> arquivo que sera verificado
	 */
	FILE *fp;
	fp = fopen(argv[2],"r");
	if(!fp)
	{
		printf("Erro ao abrir o arquivo. Fim do programa.");
		exit(1);
	}
	int ocorrencias=0;
	char s[20]={0};
	while((fscanf(fp,"%s",s))!= EOF)
	{
		printf("%s\n",s);
		if(strcmp(s,argv[1]) == 0)
		{
			ocorrencias++;
		}
	}
	printf("'%s' ocorre %d vezes no arquivo '%s'.\n",argv[1],ocorrencias,argv[2]);
	fclose(fp);
	return 0;
}

```
