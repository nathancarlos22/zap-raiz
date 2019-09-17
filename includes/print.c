

/****
 * Título: [ZapRaiz]
 * Autor: [Nathan Carlos, Denilson Pedro]
 * Data de Criação: [16/04/2019]
 * Última alteração: [01/05/2019]
 * Descrição Geral: [Por último esse modulo é onde fica os prints dos menus do programa, no qual existe pra cada print especifico uma funçao.]
 * ****/
/* print.h,contas.h e func.h*/

#include <stdio.h>



void menu_inicial_client(){
    printf("********************************************************************************\n Seja bem-vindo ao ZapRaiz, o melhor programa de troca de mensagens do planeta!\n********************************************************************************\n");
    printf(">>>>>>>>> LOGIN CLIENT <<<<<<<<<\n       \n\t 1-Criar conta\n\t 2-Login\n\t 3-Sair\n");   
}

void menu_inicial_servidor(){
    printf("\n Seja bem-vindo ao ZapRaiz, o melhor programa de troca de mensagens do planeta!\n*********\n");
    printf("==========LOGIN-SERVIDOR=========\n\t 1-Criar conta\n\t 2-Login\n\t 3-Sair\n");
}

void menu_login_client (){
	printf("*************************************\n>>>>>>>>> LOGIN CLIENT <<<<<<<<<\n          \n\t 1-Gerenciar contas\n\t 2-Gerenciar contatos\n\t 3-Gerenciar grupos\n\t 4-Iniciar uma conversa\n\t 5-Fazer logout\n************************************\n");
}

void menu_login_servidor (){
	printf("*******************************************\n >>>>>>>>>> LOGIN SERVIDOR <<<<<<<<<<<\n        \n\t 1-Gerenciar contas\n\t 2-Gerenciar contatos\n\t 3-Gerenciar grupos\n\t 4-Participar de uma conversa\n\t 5-Fazer logout\n*******************************************\n");
}

void menu_gerenciar_conta(){
	printf("*******************************************\n >>>>>>>>>>> GERENCIAR CONTA <<<<<<<<<\n         \n\t 1-Criar uma nova conta\n\t 2-Editar conta\n\t 3-Excluir conta\n\t 4-Voltar\n*******************************************\n");
}

void psaiu(){
	printf("*************************************************************\n\nMuito Obrigado por ultilizar nosso programa, VOLTE SEMPRE!!!\n*************************************************************\n");
}

void menu_contatos(){
	printf("**********************************\n >>>>>>>>> CONTATOS <<<<<<<<<\n        \n\t 1-Adicionar contato\n\t 2-Editar contato\n\t 3-Excluir contato\n\t 4-Voltar\n**********************************\n");
}

void menu_gerenciar_grupos(){
	printf("*******************************************\n >>>>>>>>>> GERENCIAR GRUPOS <<<<<<<<<\n\t 1-Criar grupo\n\t 2-Editar grupo\n\t 3-Excluir grupo\n\t 4-Voltar\n*******************************************\n");
}

void menu_envio(){
	printf("**************************************\n >>>>>>>>>> ENVIAR MENSAGENS <<<<<<<<<\n      \n\t 1-Contatos\n\t 2-Grupos\n\t 3-Voltar\n**************************************\n");
}


