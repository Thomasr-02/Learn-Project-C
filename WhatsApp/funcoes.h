#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include <stdio.h>

typedef struct tContato{
    char nome[30];
    char ip[30];
    int id_usuario; //vincula o contato com ousuario
}tContato;

typedef struct tGrupo{
    char nome[30];
    int id_usuario; //vincula o contato com ousuario
}tGrupo;

typedef struct tUsuario{
    char nome[30];
    char login[20];
    char senha[20];
    char ip[30];
    int id;
}tUsuario;

// Tirar

//Funções usuario
extern void listaUsuario(FILE*);
extern void excluiUsuario(FILE*);
extern void cadastrarUsuario();
extern tUsuario logar(FILE*);
extern int verificaID();
extern void enviarMensagem(tUsuario);

//Funções contatos
extern void listarContato(tUsuario);
extern void cadastrarContato(int);
extern void excluiContato(tUsuario);

//FUnções da GUI
extern void menuLogado();
extern void menuiniciar();
extern void menuConversas();
extern void menuEscolha();
extern void gerenciarGrupos();
extern void menuGerenContatos();


//Grupos
extern void criarGrupo(tGrupo);
extern void addContatoNoGrupo(tUsuario usuario);


extern void iniciaServidor();


#endif // FUNCOES_H_INCLUDED
