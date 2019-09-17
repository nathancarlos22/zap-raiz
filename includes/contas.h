/* contas.h, print.h e func.h */

/* Declarações de macros */

/* char, int, void */

/* Gnome,Guser,Gsenha,Gporta,s */

/* void preencher_struct_contato, void preencher_struct_grupo,void pegar_porta_conta,void criar_conta,void gerenciar_conta,void editar_conta,void excluir_conta,void cadastro_login,void logado_client,void logado_servidor*/ 


#ifndef CONTAS_H_INCLUDED
#define CONTAS_H_INCLUDED


typedef struct {
	char nome[50];
	char user[50];
	char passw[50];

}contas;

extern int s;
extern char Gnome[30], Guser[30], Gsenha[30], Gporta[30];

int autentication ();//autenticão login
void cadastro_login(); //cria conta/ faz login
void logado_client();
void logado_servidor();

void preencher_struct(contas pessoas[20]);
void pegar_porta_conta(contas pessoas[20]);
void criar_conta();
void gerenciar_conta();
void editar_conta();
void excluir_conta();

#endif
