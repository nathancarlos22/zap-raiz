/****
 * Título: [ZapRaiz]
 * Autor: [Nathan Carlos, Denilson Pedro]
 * Data de Criação: [16/04/2019]
 * Última alteração: [01/05/2019]
 * Descrição Geral: [Esse módulo é responsavel por gerenciar toda a parte de contas como fazer login, 
 		criar conta,remover conta, editar conta  e junto com a funcão preecher_struct que tem a finalidade
 		de preencher a struct com os dados do usuário. ]
 * ****/
/* print.h,contas.h e func.h*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <winsock.h>
#include <locale.h>
#include "print.h"

typedef struct {
	char nome[50];
	char user[50];
	char passw[50];
	char porta[50];

}contas;

int s=0;
char Gnome[30], Guser[30], Gsenha[30], Gporta[30];
contas pessoas[20];

void preencher_struct(contas pessoas[20]) {
	s=0;
	FILE *arq;
	arq=fopen("contas.txt", "r");
	
	char array[50][50], aux[50];
	int i, j, r=0, k;
	
	while(fgets(array[s], 50, arq) != NULL) {
		s++;
	}
	//printf("%s", array);


	for(i=0; i<s; i++) {
		for(j=0; j<50; j++) {
			if(array[i][j]!=':') {
				aux[r]=array[i][j];
				r++;
			}
			if(array[i][j]==':') {
				aux[r]='\0';
				break;
			}
		}
		strcpy(pessoas[i].nome, aux); //colocando dentro da estrutura o nome 
		r=0;
	}

	//pegando os users
	r=0;
	for(i=0; i<strlen(aux); i++) { //zerando a array aux
		aux[i]=' ';
	}
	int len;
	for(i=0; i<s; i++) {
		len=strlen(array[i]);
		for(j=0; j<len; j++) {
			if(array[i][j]==':') { //depois do caractere ':' pega oS NOMES
				for(k=j+1; k<len-1; k++)
					if(array[i][k] != ' ') { //ate ' espaço '
						aux[r]=array[i][k];
						r++;

					}
					else{
						aux[r]='\0';
						break;
					}
			}
		}
		strcpy(pessoas[i].user, aux);
		r=0;
	}
	char aux2[50];

	//pegando os ips
	for(i=0; i<s; i++) {
		len=strlen(array[i]);
		for(j=0; j<len; j++) {
			if(array[i][j]==' ') { //depois do caractere ' espaço '
				for(k=j+1; k<len; k++)
					if(array[i][k] != '/') { //vai ate o caractere '/' e pega os ips
						aux2[r]=array[i][k];
						r++;

					}
					else{
						aux2[r]='\0'; //colocando '\0' para indicar o final do array
						break;
					}
			}
		}
		strcpy(pessoas[i].passw, aux2); //colocando dentro da estrutura a senha
		r=0;
	}
	fclose(arq);
}

void pegar_porta_conta(contas pessoas[20]) {
	
	s=0;
	
	
	FILE *arq;
	arq=fopen("contas.txt", "r");
	
	char array[50], aux[50];
	int i, j, r=0, k;
	
	while(fgets(array, 50, arq) != NULL) {
		//printf("%s\n", array);
		
		for(i=0; i<strlen(array); i++) {
			if(array[i]=='/') {
				for(j=i+1; j<strlen(array); j++) {
					if(array[j] != '\n') {
						aux[r]=array[j];
						r++;
					}
					else {
						aux[r]='\0';
						break;
					}
					
				}
			}
			r=0;
		}
		strcpy(pessoas[s].porta, aux);
		s++;
	}
	fclose(arq);
}



int autentication () {
	char usuario[20], senha[20];
	printf("\nDigite seu usuario: ");
	scanf("%s", usuario);
	
	printf("\nDigite sua senha: ");
	scanf("%s", senha);
	
	char users[20];
	char pass[50];
	int i, j;

	FILE *arq;
	arq=fopen("contas.txt", "r"); if(arq == NULL) printf("Nao foi possivel abrir o arquivo contas.txt\n") ;

	char array[50][50], aux[50];
	
	preencher_struct(pessoas);
	
	int logado;
	
	int c;
	 for (c=0;c<s;c++)
   {
       if ((strcmp(usuario, pessoas[c].user) != 0) || (strcmp(senha, pessoas[c].passw)!=0))
       {
           logado = 1; //login e/ou senha incorretos
       }
       else if(strcmp(usuario, pessoas[c].user)==0)
       {
           if (strcmp(senha, pessoas[c].passw)==0)
           {
        		setbuf(stdin, NULL);
				fflush(stdin);
            	logado = 2; //logado com sucesso
            	strcpy(Gnome, pessoas[c].nome);
            	strcpy(Guser, pessoas[c].user);
            	strcpy(Gsenha, pessoas[c].passw);
            	break;
           }

       }
   }

   if(logado !=2)
   {
   		printf("LOGIN OU SENHA INCORRETOS\n");
   		system("pause");
   		s=0;
   }

   else if(logado ==2)
   {
   		printf("LOGADO COM SUCESSO!\n");
   		system("Pause");
   }
   fclose(arq);
	return logado;
}

void criar_conta () {
	
	preencher_struct(pessoas);
	pegar_porta_conta(pessoas);
	
	char nome[20], login[20], senha[20], porta[20];
	

    printf("\nDigite seu NOME: ");
    scanf("%s", nome);
	
	
	printf("\nDigite seu LOGIN: ");
    scanf("%s", login);
    
    
    printf("\nDigite sua SENHA: ");
    scanf("%s", senha);
    
    printf("\nDigite a sua PORTA: ");
	scanf("%s", porta);
		
	int i, flag=0;
	
	for(i=0; i<s; i++) {
		if(strcmp(login, pessoas[i].user)==0) {
			flag=1;
			system("cls");
			printf("\nLogin já existente!\n");
			system("pause");
			break;
		}
	}
	
	FILE *arq;
	
	if(flag==0) {
		arq = fopen("contas.txt","a");
		setbuf(stdin, NULL);
		
		fprintf(arq, "%s:%s %s/%s\n", nome, login, senha, porta);
		system("cls");
		printf("\nConta criada!\n");
		system("pause");
    	fclose(arq);
    	preencher_struct(pessoas); 
    	pegar_porta_conta(pessoas);
	}
}

void excluir_conta(){
	
	char aux[100];
	char palavra[40];
	char caractere[20][100];
	int i;
	
	preencher_struct(pessoas);
	pegar_porta_conta(pessoas);
	
	if(s<=0) {
		system("cls");
		printf("\nLista de contas vazia!\n");
		system("pause");
	}
	else {
		
	
	for(i=0; i<s; i++) { //printando contas
		printf("Nome: %s Login: %s Senha: %s\n", pessoas[i].nome, pessoas[i].user, pessoas[i].passw);
	}
	
	printf("Digite o nome do usuário que  deseja remover!\n");
	scanf("%s",palavra);
	system("cls");
	
	int flag=0;			
	for(i=0; i<s; i++) {
		if(strcmp(palavra, pessoas[i].nome)==0){
			flag=1;
			pessoas[i].nome[0]='\0';
			pessoas[i].user[0]='\0';
			pessoas[i].passw[0]='\0';
			pessoas[i].porta[0]='\0';
			printf("\nConta excluida\n");
			system("pause");
			break;
		}
	}
	if(flag==0) {
		printf("\nConta não encontrada\n");
		system("pause");
	}
	FILE *arq;
	arq=fopen("contas.txt", "w");
	
	for(i=0; i<s; i++) {
		if(pessoas[i].nome[0] !='\0')
			fprintf(arq, "%s:%s %s/%s\n", pessoas[i].nome, pessoas[i].user, pessoas[i].passw, pessoas[i].porta);
	}
	
	preencher_struct(pessoas);
	pegar_porta_conta(pessoas);
	fclose(arq);
	}
}

void editar_conta(){
	preencher_struct(pessoas);
	pegar_porta_conta(pessoas);
	
	char nome[20];
	
	int i;
	
	if(s<=0) {
		system("cls");
		printf("\nLista de contas vazia!\n");
		system("pause");
	}
	
	else {
		
	
	for(i=0; i<s; i++) { //printando contas
		printf("Nome: %s Login: %s Senha: %s Porta: %s\n", pessoas[i].nome, pessoas[i].user, pessoas[i].passw, pessoas[i].porta);
	}
	printf("\nDigite o NOME da pessoa que deseja alterar: ");
	scanf("%s", nome);
	
	int flag1=0, flag=0;
	char nwnome[20], nwlogin[20], nwsenha[20], nwporta[20];
	
	for(i=0; i<s; i++) {
		if(strcmp(nome, pessoas[i].nome)==0){
			flag1=1;
		} 
	}
	if(flag1==1){
		printf("\nDigite o NOVO NOME: ");
		scanf("%s", nwnome);			
			
		printf("\nDigite o NOVO LOGIN: ");
		scanf("%s", nwlogin);
			
		printf("\nDigite o NOVA SENHA: ");
		scanf("%s", nwsenha);
	
		printf("\nDigite a NOVA PORTA");
		scanf("%s", nwporta);
	
		for(i=0; i<s; i++) { //comparando oq ele digitou com oq ta na struct
			
			if(strcmp(nwlogin, pessoas[i].user) ==0) {
				flag=1;
				system("cls");
				printf("\nLogin já cadastrado\n");
				system("pause");
				break;
			}
		}
		
		if(flag==0) { //alterando a struct para o novo nome
			for(i=0; i<s; i++) { //comparando oq ele digitou com oq ta na struct
				if(strcmp(nome, pessoas[i].nome) ==0) {
					strcpy(pessoas[i].nome, nwnome);
					strcpy(pessoas[i].user, nwlogin);
					strcpy(pessoas[i].passw, nwsenha);
					strcpy(pessoas[i].porta, nwporta);
				}
			}
			system("cls");
			printf("\nLogin alterado!\n");
			system("pause");
		}
	}
	else {
		system("cls");
		printf("\nConta não encontrada!\n");
		system("pause");
	}
	
	FILE *arq;
	arq=fopen("contas.txt", "w");
	
	for(i=0; i<s; i++) { //colocando dentro do arquivo o login alterado
		fprintf(arq, "%s:%s %s/%s\n", pessoas[i].nome, pessoas[i].user, pessoas[i].passw, pessoas[i].porta);
	}
	fclose(arq);

  	preencher_struct(pessoas);
  	pegar_porta_conta(pessoas);
	}
}
	

void gerenciar_conta() {
	
	int o;
	while(o != 4) {
		system("cls");
		menu_gerenciar_conta ();
		printf("Digite sua opcao: ");
		setbuf(stdin, NULL);
    	scanf("%d", &o);
    	switch(o) {
    		case 1:
    			criar_conta();
				break;
    		case 2:
    			editar_conta();
				break;
			case 3:
				excluir_conta();
    			break;
    		case 4:
				break;		
		}
	}
}
