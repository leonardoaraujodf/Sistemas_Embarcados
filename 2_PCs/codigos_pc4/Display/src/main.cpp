#include <iostream>
#include "Display.h"
#include <stdio.h>
using namespace std;

int main(){

	Display display;
	display.Setup();
	display.Print("To com sono!!!!");

	char entrada[50];
	cout << "Digite \"sair\" para sair do programa." << endl;
	while(1){
		scanf ("%[^\n]%*c", entrada);
		if(strncmp(entrada,"sair",4) == 0){
			break;
		}
		else{
			display.Print(entrada);
		}
	}

	cout << "Saindo do programa." << endl;

	return 0;
}
