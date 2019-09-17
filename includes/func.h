/* contas.h, print.h e func.h */

/*void preencher_struct_grupo(grupos gp[20]);
void pegar_porta(grupos gp[20]);
void gerenciar_grupos();
void criar_grupo();
void editar_grupo();
void remover_grupo();
void enviar_grupo();
void client ();
void servidor();
void envio(); */

/* char, int, void */

/* Gnome, Guser, Gsenha, Gporta */

/* void preencher_struct_contato,void adicionar_contato,void editar_contato,void preencher_struct_grupo,void pegar_porta,void gerenciar_grupos,void criar_grupo,void editar_grupo,void remover_grupo,void enviar_grupo,void client,void servidor,void envio */ 



#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED



typedef struct {
    char nome[50];
    char telefone[50];
    char ip[50];
}contatos;


extern int s;
extern char Gnome[30], Guser[30], Gsenha[30], Gporta[30];


void preencher_struct_contato(contatos add[20]);
void adicionar_contato();
void editar_contato();

typedef struct {
	char grupo[30];
	char nome[30];
	char ip[30];
}grupos;



void preencher_struct_grupo(grupos gp[20]);
void pegar_porta(grupos gp[20]);
void gerenciar_grupos();
void criar_grupo();
void editar_grupo();
void remover_grupo();
void enviar_grupo();

void client ();
void servidor();
void envio();

#endif

