/****
 * Título: [ZapRaiz]
 * Autor: [Nathan Carlos, Denilson Pedro]
 * Data de Criação: [16/04/2019]
 * Última alteração: [01/05/2019]
 * Descrição Geral: 
 	[Esse módulo tem como especialidade trabalhar com contatos como remover contato, adicionar contatos e edição de contatos, 
	 como também trabalha com a parte dos grupos onde o usuario pode criar um grupo, editar um grupo e removê-lo. ]
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
    char telefone[50];
    char ip[50];
}contatos;

int s;
char Gnome[30], Guser[30], Gsenha[30], Gporta[30];

contatos add[20];

int p=0;
void preencher_struct_contato(contatos add[20]) {
	
	
	p=0;
	
	char array[50][50], aux[50], resultado[30];
	int i, j, r=0, k;
	
	sprintf(resultado, "contatos_%s.txt", Gnome);
	
	FILE *arq;
	arq=fopen(resultado, "r");
	
	while(fgets(array[p], 50, arq) != NULL) {
		p++;
	}
	//printf("%s", array);


	for(i=0; i<p; i++) {
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
		strcpy(add[i].nome, aux); //colocando dentro da estrutura o nome 
		r=0;
	}

	//pegando os users
	r=0;
	for(i=0; i<strlen(aux); i++) { //zerando a array aux
		aux[i]=' ';
	}
	int len;
	for(i=0; i<p; i++) {
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
		strcpy(add[i].telefone, aux);
		r=0;
	}
	char aux2[50];

	//pegando os ips
	for(i=0; i<p; i++) {
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
		strcpy(add[i].ip, aux2); //colocando dentro da estrutura a senha
		r=0;
	}
	fclose(arq);
}

typedef struct {
	char nome[50];
	char user[50];
	char passw[50];
	char porta[50];

}contas1;

contas1 pessoas[20];

int verificar_contas(contas1 pessoas[20], char nome[20]) {
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
	
	
	int flag=0;
	
	for(i=0; i<s; i++) {
		if(strcmp(pessoas[i].nome, nome)==0) {
			flag=1;
		}
	}
	
	return flag;
 
 fclose(arq);
}

void adicionar_contato() {
	
	preencher_struct_contato(add);
	
	char nome[20], porta[20], ip[20];
	
    printf("\nDigite o NOME do contato: ");
    scanf("%s", nome);
	
	int x= verificar_contas(pessoas, nome);
	
	if(x==0) {
		system("cls");
		printf("\nContato não cadastrado!\n");
		system("pause");
	}
	
	else {
	
		int flag1=0, flag=0, i; //flag para verificar se o contato está cadastrado
		flag=0;
		
		for(i=0; i<p; i++) { //verificando se existe um nome igual ao já existente na lista de contatos
			if(strcmp(nome, add[i].nome)==0) {
				flag=1;
				system("cls");
				printf("\nContato já existente na sua lista de contatos!\n");
				system("pause");
				break;
			}
		}
		
		FILE *arq;
		
		if(flag==0) {
			char nomearq[20];
			
			printf("\nDigite a PORTA do contato: ");
		    scanf("%s", porta);
		    
		    printf("\nDigite o IP do contato: ");
		    scanf("%s", ip);
			
			sprintf(nomearq, "contatos_%s.txt", Gnome);
			
			arq = fopen(nomearq,"a");
			setbuf(stdin, NULL);
			fflush(stdin);
			
			fprintf(arq, "%s:%s %s/\n", nome, porta, ip);
			
			system("cls");
			printf("\nContato adicionado!\n");
			system("pause");
	    	
			fclose(arq);
	    	preencher_struct_contato(add); 
		}
	}
	
}



void editar_contato() {
	
	preencher_struct_contato(add);
	
	char nome[20];
	
	int i;
	
	if(p<=0) { //verificando se existe o contas no arquivo de contas
		system("cls");
		printf("\nLista de contatos vazia!\n");
		system("pause");
	}
	
	else {

		for(i=0; i<p; i++) {
			printf("Nome: %s Porta: %s Ip: %s\n", add[i].nome, add[i].telefone, add[i].ip);
		}
			
		printf("\nDigite o NOME do contato que deseja alterar: ");
		scanf("%s", nome);
		
		int x= verificar_contas(pessoas, nome);
			
		if(x==0) {
			system("cls");
			printf("\nContato não cadastrado!\n");
			system("pause");
		}
		
		else {
			int flag1=0, flag=0;
			char nwnome[20], nwporta[20], nwip[20];
			
			for(i=0; i<p; i++){
				if(strcmp(nome, add[i].nome)==0){
					flag1=1;
				} 
			} 
			
			if(flag1==1) {
			
				printf("\nDigite o NOVO NOME para o contato: ");
				scanf("%s", nwnome);			
						
				printf("\nDigite a NOVA PORTA para o contato: ");
				scanf("%s", nwporta);
					
				printf("\nDigite o NOVO IP para o contato: ");
				scanf("%s", nwip);
				
				/*for(i=0; i<p; i++) { //comparando oq ele digitou com oq ta na struct
					if(strcmp(nwnome, add[i].nome) ==0) {
						flag=1;
						system("cls");
						printf("\nContato já cadastrado\n");
						system("pause");
						break;
					
					}
				}*/
				if (flag==0) { //alterando a struct para o novo nome
					for(i=0; i<p; i++) { 
						if(strcmp(nome, add[i].nome) ==0) {
							strcpy(add[i].nome, nwnome);
							strcpy(add[i].telefone, nwporta);
							strcpy(add[i].ip, nwip);
						}
					}
					system("cls");
					printf("\nContato alterado!\n");
					system("pause");
				}
			
			else {
				system("cls");
				printf("\nContato não encontrado\n");
				system("pause");	
			}
				
			FILE *arq;
			char nomearq[20];
			
			sprintf(nomearq, "contatos_%s.txt", Gnome);
			arq=fopen(nomearq, "w");
			
			for(i=0; i<p; i++) { //colocando dentro do arquivo o login alterado
				fprintf(arq, "%s:%s %s/\n", add[i].nome, add[i].telefone, add[i].ip);
			}
			fclose(arq);
		  	preencher_struct_contato(add);
			}
		}
	}	
}

void excluir_contato() {
	
	char palavra[40];
	int i=0, j=0;
	char arqnome[30];
	
	preencher_struct_contato(add);
    
    if(p<=0) {
    	system("cls");
    	printf("\nLista de contatos vazia!\n");
    	system("pause");
	}
	else {
	    printf("\n==========LISTA DE CONTATOS==========\n");
		for(i=0; i<p; i++) {
			printf("Nome: %s Telefone: %s IP: %s\n", add[i].nome, add[i].telefone, add[i].ip);
		}	
			
		printf("Digite o NOME do contato que  deseja excluir!\n");
		scanf("%s",palavra);
		system("cls");
		
		int cont=0;
		for(i=0; i<p; i++){
			if(strcmp(palavra, add[i].nome)==0){
				add[i].nome[0]='\0';
				add[i].telefone[0]='\0';
				add[i].ip[0]='\0';
				
				printf("\nContato excluido!\n");
				system("pause");
				cont=1;
				break;
			}
		}
		if(cont==1) {
			sprintf(arqnome, "contatos_%s.txt", Gnome);
			FILE *arq;
			arq=fopen(arqnome, "w");
			
			for(i=0; i<p; i++) {
				if(add[i].nome[0] != '\0' || add[i].telefone[0] != '\0' || add[i].ip[0] != '\0')
					fprintf(arq, "%s:%s %s/\n", add[i].nome, add[i].telefone, add[i].ip);
			}
			preencher_struct_contato(add);
			fclose(arq);
		}
		else {
			printf("\nContato não encontrado\n");
			system("pause");
		}
	}
}


void gerenciar_contatos() {
	
	int p;
	while(p != 4) {
		system("cls");
		menu_contatos();
		printf("Digite sua opcao: ");
		setbuf(stdin, NULL);
    	scanf("%d", &p);
    	switch(p) {
    		case 1:
    			adicionar_contato();
				break;
    		case 2:
    			editar_contato();
				break;
			case 3:
				excluir_contato();
    			break;
    		case 4:
				break;		
		}
	}
}

typedef struct {
	
	char grupo[20];
	char nome[20];
	char ip[20];
	char porta[20];
	
}grupos;

grupos gp[20];
int q=0;

void preencher_struct_grupo(grupos gp[20]) {
	
	q=0;
	char novo_nome[20];
	
	sprintf(novo_nome,"grupos_%s.txt",Gnome);
	
	FILE *arq;
	arq=fopen(novo_nome, "r");
	
	char array[50][50], aux[50];
	int i, j, r=0, k;
	
	while(fgets(array[q], 50, arq) != NULL) {
		q++;
	}
	//printf("%s", array);


	for(i=0; i<q; i++) {
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
		strcpy(gp[i].grupo, aux); //colocando dentro da estrutura o nome 
		r=0;
	}

	//pegando os users
	r=0;
	for(i=0; i<strlen(aux); i++) { //zerando a array aux
		aux[i]=' ';
	}
	int len;
	for(i=0; i<q; i++) {
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
		strcpy(gp[i].nome, aux);
		r=0;
	}
	char aux2[50];

	//pegando os ips
	for(i=0; i<q; i++) {
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
		strcpy(gp[i].ip, aux2); //colocando dentro da estrutura a senha
		r=0;
	}

	fclose(arq);
}
void pegar_porta(grupos gp[20]) {
	
	q=0;
	char novo_nome[20];
	
	sprintf(novo_nome,"grupos_%s.txt",Gnome);
	
	FILE *arq;
	arq=fopen(novo_nome, "r");
	
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
		strcpy(gp[q].porta, aux);
		q++;
	}
	fclose(arq);
}


void criar_grupo() {
	
	preencher_struct_grupo(gp);
	pegar_porta(gp);
	
	char gpnome[20], nome[20], ip[20], porta[20], nomearq[20];
	int i, flag=0, n, m;
	
	printf("\nQuantos contatos deseja adicionar ao seu grupo ? ");
	scanf("%d", &n);
	
	printf("\nDigite o NOME DO GRUPO que deseja criar: ");
	scanf("%s", gpnome);
	
	for(i=0; i<q; i++) {
		if(strcmp(gpnome, gp[i].grupo)==0) {
			flag=1;
		}
	}
	
	FILE *arq;
	
	if(flag==0) {
			
		for(m=0; m<n; m++) {
			
			printf("\nDigite o NOME do contato: ");
			scanf("%s", nome);
			
			int x=verificar_contas(pessoas, nome);
	
			if(x==0) {
				system("cls");
				printf("\nContato não cadastrado!\n");
				system("pause");
			}
			else {
					
				printf("\nDigite o IP do contato: ");
				scanf("%s", ip);
		
				printf("\nDigite a PORTA do contato: ");
				scanf("%s", porta);
			
				sprintf(nomearq, "grupos_%s.txt", Gnome);
			
				arq = fopen(nomearq,"a");
			
				fprintf(arq, "%s:%s %s/%s\n", gpnome, nome, ip, porta);
			
	    		preencher_struct_grupo(gp);
				pegar_porta(gp); 
				
				system("cls");
				printf("\nGrupo criado!\n");
				system("pause");
				fclose(arq);
			}
		}
	}
	else {
		system("cls");
		printf("\nGrupo já existente!\n");
		system("pause");
	}
	
}

void remover_grupo() {
	
	char palavra[40];
	int i=0, j=0;
	char arqnome[30];
	
	preencher_struct_grupo(gp);
    pegar_porta(gp);
    
    if(q<=0) {
    	system("cls");
    	printf("\nLista de grupos vazia!\n");
    	system("pause");
	}
	else {
	    printf("\n==========LISTA DE GRUPOS==========\n");
		for(i=0; i<q; i++) {
			printf("Nome do grupo: %s Nome: %s IP: %s Porta: %s\n", gp[i].grupo, gp[i].nome, gp[i].ip, gp[i].porta);
		}	
			
		printf("Digite o NOME do grupo que  deseja excluir!\n");
		scanf("%s",palavra);
		
		int cont=0;
		for(i=0; i<q; i++){
			if(strcmp(palavra, gp[i].grupo)==0){
				gp[i].grupo[0]='\0';
				gp[i].nome[0]='\0';
				gp[i].ip[0]='\0';
				gp[i].porta[0]='\0';
				
				cont=1;
			}
		}
		if(cont==1) {
			system("cls");
			printf("\nGrupo excluido!\n");
			system("pause");
			
			sprintf(arqnome, "grupos_%s.txt", Gnome);
			FILE *arq;
			arq=fopen(arqnome, "w");
			
			for(i=0; i<q; i++) {
				if(gp[i].grupo[0] != '\0')
					fprintf(arq, "%s:%s %s/%s\n", gp[i].grupo, gp[i].nome, gp[i].ip, gp[i].porta);
			}
			preencher_struct_grupo(gp);
			pegar_porta(gp);
			
			fclose(arq);
		}
		else {
			system("cls");
			printf("\nGrupo não encontrado\n");
			system("pause");
		}
	}
}


void editar_grupo () {
	preencher_struct_grupo(gp);
	pegar_porta(gp);
	
	char nome[20];
	
	int i;
	setbuf(stdin, NULL);
	
	if(q<=0) {
		system("cls");
		printf("\nLista de grupos vazia!\n");
		system("pause");
	}
	else {
		
	for(i=0; i<q; i++) { //printando contas
		printf("Nome do grupo: %s Nome: %s IP: %s Porta: %s\n", gp[i].grupo, gp[i].nome, gp[i].ip, gp[i].porta);
	}
	printf("\nDigite o NOME do grupo que deseja alterar: ");
	scanf("%s", nome);
	
	char nwnome[20], nwporta[20], nwip[20], nwporta1[20];
	
	int flag=0, n, j;
	
	for(i=0; i<q; i++) { //comparando oq ele digitou com oq ta na struct
		if(strcmp(nome, gp[i].grupo) ==0) {
			flag=1;	//um aviso para dizer que encontrou o nome que ele digitou com o nome que ta na struct
		}
	}
	
	if(flag==1) {
		printf("\nDigite o NOVO NOME DO GRUPO: "); //colocando o nome do grupo fora do for para nao pegar cada contato que tiver no grupo, alterando so os contatos e nao o nome do grupo
		scanf("%s", nwnome);
	}
	
	for(i=0; i<q; i++) { //comparando oq ele digitou com oq ta na struct
		if(strcmp(nome, gp[i].grupo) ==0) {
			printf("\nAltere a o nome do contato %s: ", gp[i].nome);
			scanf("%s", nwporta);
			
			printf("\nAltere o IP: %s: ", gp[i].ip);
			scanf("%s", nwip);
	
			printf("\nAltere a PORTA %s: ", gp[i].porta);
			scanf("%s", nwporta1);
			
			strcpy(gp[i].grupo, nwnome);
			strcpy(gp[i].nome, nwporta);
			strcpy(gp[i].ip, nwip);
			strcpy(gp[i].porta, nwporta1);
		}
	}
	if(flag==0) {
		system("cls");
		printf("\nNome do grupo não encontrado!\n");
		system("pause");
	}
	if(flag==1) { //se for 1 quer dizer q entrou no for de trocar os grupos pelo oq ele digitou
		system("cls");
		printf("\nGrupo alterado!\n");
		system("pause");
	}
		
	FILE *arq;
	char nomearq[20];
	
	sprintf(nomearq, "grupos_%s.txt", Gnome);
	arq=fopen(nomearq, "w");
	
	for(j=0; j<q; j++) { //colocando dentro do arquivo o login alterado
		fprintf(arq, "%s:%s %s/%s\n", gp[j].grupo, gp[j].nome, gp[j].ip, gp[j].porta);
	}
	fclose(arq);
  	
	preencher_struct_grupo(gp);
	pegar_porta(gp);
	}
}

void gerenciar_grupos() {
		
		system("cls");
    	menu_gerenciar_grupos();
		int p=0;
    	while(p!= 4) {
  			system("cls");
    		menu_gerenciar_grupos();
			
			printf("Digite sua opcao: ");
    		setbuf(stdin, NULL);
    		scanf("%d", &p);
    		
    		switch(p) {
    			case 1:
    				criar_grupo();
					break;
    			case 2:
    				editar_grupo();
    				break;
				case 3:
					remover_grupo();
    				break;
    			case 4:
    				break;
			}
		}
}

    void InitWinsock()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
}

char* retirarenter(char *string){
    string[strlen(string)-1] = '\0';
    return string;
}

void client () {
	
	int i, j;
	char nome[30], array[10][50], aux[50];
	int y=0;
	
	preencher_struct_contato(add);
	
	if(p<0) {
		system("cls");
		printf("\nLista de contatos vazia!\n");
		system("pause");
	}	
	
	else {

		printf("\n==========LISTA DE CONTATOS==========\n", p);
		for(i=0; i<p; i++) {
			printf("Nome: %s IP: %s Porta: %s\n", add[i].nome, add[i].ip, add[i].telefone);
		}
		
		char name[30], ip_conversa[10], porta[10];	
		printf("\nDigite o nome do contato que deseja conversar: ");
		scanf("%s", name);
		
		
		for(i=0; i<p; i++) {
			if(strcmp(name, add[i].nome)==0) {
				strcpy(ip_conversa, add[i].ip);//colocando o ip em um var
				y=1;
				break;
			}
		}
		
		if(y==1) {
		
			SOCKET socketC;
	
	    	InitWinsock();
	    	struct sockaddr_in serverInfo;
	    	int len = sizeof(serverInfo);
	    	serverInfo.sin_family = AF_INET;
	    	serverInfo.sin_port = htons(atoi(Gporta)); //a porta de quem fez o login
	    	
	    	serverInfo.sin_addr.s_addr = inet_addr(ip_conversa);//ip do contato que ira ser enviado
			
	    	socketC = socket(AF_INET,SOCK_DGRAM,0);
	  		  		
			while (1) {
	        	char buffer[1024];
	        	ZeroMemory(buffer, sizeof(buffer));
	        	
				printf("Digite sua mensagem(ou sair para voltar ao menu): ");
	        	fgets(buffer, 1024, stdin);
	        	
	        	retirarenter(buffer);
	        	
				if (strcmp(buffer,"sair") == 0){
	            	break;
				}
	        	if (sendto(socketC, buffer, sizeof(buffer), 0, (SOCKADDR*)&serverInfo, len) != SOCKET_ERROR) {
	            	if (recvfrom(socketC, buffer, sizeof(buffer), 0, (SOCKADDR*)&serverInfo, &len) != SOCKET_ERROR) {
	                	printf("Recebida mensagem de: %s\n", buffer);
	            	}
	        	}
	    	}
	    	closesocket(socketC);
		}
		else if(y==0){
			system("cls");
			printf("\nNome não encontrado na sua lista de contatos.\n");
			system("pause");
		}
	}
}

int servidor () {
	SOCKET socketS;
	
    InitWinsock();
    struct sockaddr_in local;
    struct sockaddr_in from;
    int fromlen           = sizeof(from);
    local.sin_family      = AF_INET;
    local.sin_port        = htons(atoi(Gporta));
    local.sin_addr.s_addr = INADDR_ANY;
	
    socketS = socket(AF_INET,SOCK_DGRAM,0);
    bind(socketS,(SOCKADDR* )&local,sizeof(local));
    while (1)
    {
        char buffer[1024];
        ZeroMemory(buffer, sizeof(buffer));
        printf("Esperando mensagem...\n");
        
		if (recvfrom(socketS,buffer,sizeof(buffer),0,(SOCKADDR*)&from,&fromlen)!=SOCKET_ERROR)
        {
            printf("Recebida mensagem de: %s: %s\n",inet_ntoa(from.sin_addr), buffer);
            ZeroMemory(buffer, sizeof(buffer));
            fflush(stdin);
            
            printf("Responda: ");
            fgets(buffer, 1024, stdin);
            
			sendto(socketS, buffer, sizeof(buffer), 0, (SOCKADDR*)&from, fromlen);
        }
    }
    closesocket(socketS);
}


void enviar_grupo() {
	
	int i, j;
	char name[30];
	
	char arqnome[30];
	int k;
	char array[10][50], aux[50];
	
			
	preencher_struct_grupo(gp);
	pegar_porta(gp);
	
	if(q<=0) {
		system("cls");
		printf("\nLista de grupos vazia!\n");
		system("pause");
	}
	else {
		
		printf("\n==========LISTA DE GRUPOS==========\n");
		for(i=0; i<q; i++) {
			printf("Grupo: %s Nome: %s IP: %s Porta: %s\n", gp[i].grupo, gp[i].nome, gp[i].ip, gp[i].porta);
		}
			
		printf("\nDigite o nome do grupo que deseja enviar: ");
		scanf("%s", name);
	
		int leen, y=0;
	
		for(i=0; i<q; i++) {
			if(strcmp(name, gp[i].grupo)==0) { //se nao tiver o nome do grupo no arquivo, exibe mensagem informando que nao tem
				y=1;
			}
		}
		if(y==1) {
		
			SOCKET socketC;
	
	    	InitWinsock();
		    struct sockaddr_in serverInfo;
		    int len = sizeof(serverInfo);
		    serverInfo.sin_family = AF_INET;
		    serverInfo.sin_port = htons(5000);
		    		
			socketC = socket(AF_INET,SOCK_DGRAM,0);
			
			char ip_conversa[10], porta[20];
			int port;
		    
			while (1) {
				for(i=0; i<q; i++) { //for com o tamanho de pessoas do grupo
					char buffer[1024];
					
					if(strcmp(name, gp[i].grupo)==0){ //comparando com o nome do grupo
						
						strcpy(ip_conversa, gp[i].ip); //colocando os ips em uma var
						
		    			serverInfo.sin_addr.s_addr = inet_addr(ip_conversa);//alterando na struct o ip de cada pessoa
				        
						ZeroMemory(buffer, sizeof(buffer));
						
						setbuf(stdin, NULL);
				        printf("Enviar mensagem para %s: ", ip_conversa);
				        
						fgets(buffer, 1024, stdin);
				        
				       sendto(socketC, buffer, sizeof(buffer), 0, (SOCKADDR*)&serverInfo, len);
				       
				       recvfrom(socketC, buffer, sizeof(buffer), 0, (SOCKADDR*)&serverInfo, &len);
				        
		    		}
		    		closesocket(socketC);
				}
				break;
			}	
		}
		else if(y==0){
			system("cls");
			printf("\nNome do grupo não encontrado.\n");
			system("pause");
		}
	}
}


void envio() {
	
	system("cls");
    	menu_envio();
		int p=0;
    	while(p!= 3) {
  			system("cls");
    		menu_envio();
			printf("Digite sua opcao: ");
    		setbuf(stdin, NULL);
    		scanf("%d", &p);
    		
    		switch(p) {
    			case 1:
    				client();
					break;
    			case 2:
    				enviar_grupo();
    				break;
				case 3:
    				break;
			}
		}
	}

void logado_client () {
	
    	system("cls");
    	menu_login_client();
		int p=0;
    	while(p!= 5) {
  			system("cls");
    		menu_login_client();
			printf("Digite sua opcao: ");
    		setbuf(stdin, NULL);
    		scanf("%d", &p);
    		
    		switch(p) {
    			case 1:
    				gerenciar_conta();
					break;
    			case 2:
    				gerenciar_contatos();
    				break;
				case 3:
					gerenciar_grupos();
    				break;
    			case 4:
    				envio();
    				break;
				case 5:	
				s=0;
					break;
			}
		}
	}


void logado_servidor () {
	
    	system("cls");
    	menu_login_servidor();
		int p=0;
    	while(p!= 5) {
  			system("cls");
    		menu_login_servidor();
			printf("Digite sua opcao: ");
    		setbuf(stdin, NULL);
    		scanf("%d", &p);
    		
    		switch(p) {
    			case 1:
    				gerenciar_conta();
					break;
    			case 2:
    				gerenciar_contatos();
    				break;
				case 3:
					gerenciar_grupos();
    				break;
    			case 4:
    				servidor();
    				break;
				case 5:	
					s=0;
					break;
			}
		}
	}




