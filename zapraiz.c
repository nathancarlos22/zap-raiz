#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <winsock.h>
#include <locale.h>
#include "includes/print.h"
#include "includes/func.h"
#include "includes/contas.h"

/****
 * Título: [ZapRaiz]
 * Autor: [Nathan Carlos, Denilson Pedro]
 * Data de Criação: [16/04/2019]
 * Última alteração: [01/05/2019]
 * Descrição Geral: [É um chat que tem como funcionalidades conversas em grupo e conversas individuais com contatos]
 * ****/
/* print.h,contas.h e func.h*/

int main (int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	
	int n=0, log;
	
	if (strcmp(argv[1], "client") == 0) {
		system("cls");
		menu_inicial_client();
		
		while(scanf("%d", &n), n != 3){
			system("cls");
			menu_inicial_client();
			switch (n) {
				case 1:
					system("cls");
					criar_conta();
					system("cls");
					menu_inicial_client();
					break;
				case 2:
					system("cls");
					log=autentication();
					
					if(log==2) {
						logado_client();
					}
					
					system("cls");
					menu_inicial_client();
					break;
				case 3:
					psaiu();
					break;
			}
		}
		
	}
	
	
	else if (strcmp(argv[1], "servidor") == 0) {
		system("cls");
		menu_inicial_servidor();
		
		while(scanf("%d", &n), n != 3){
			system("cls");
			menu_inicial_servidor();
			switch (n) {
				case 1:
					system("cls");
					criar_conta();
					system("cls");
					menu_inicial_servidor();
					break;
				case 2:
					system("cls");
					log=autentication();
					
					if(log==2) {
						logado_servidor();
					}
					
					system("cls");
					menu_inicial_servidor();
					break;
				case 3:
					psaiu();
					break;
			}
		}
	}
	
	
	else {
		printf("\nArgumento(s) inválido(s)\n");
		system("pause");	
	}
}
