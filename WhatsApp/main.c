/****
 * Título: [PROJETO-LP1]
 * Autor: [Thomas Ribeiro de Araújo] [ Thiago Emanoel Oliveira C. dos Santos]
 * Data de Criação: [20/04/2019]
 * Última alteração: [01/05/2019]
 * Descrição Geral: [O zap raiz, o melhor chat de conversas via conexão UDP, com varias funcionalidades. ]
 *
 ****/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "funcoes.h"


int main()
{
    setlocale(LC_ALL, "Portuguese");

    int qtd,op, escolha, i, logado = 0;
    char ip[30];
    char linha[100];
    FILE *arquivo;
    tUsuario usuario;
    char nome[30], data[10];

    while (escolha != 1 && escolha != 2 && escolha!= 3){
        menuEscolha();
        scanf("%d", &escolha);
        setbuf(stdin,NULL);
    }

    system("cls");
    if(escolha == 1){
        iniciaServer();
    }else if((escolha != 3)){
        escolha=0;
        while(logado == 0){
            menuIniciar();
            scanf("%d", &escolha);
            setbuf(stdin,NULL);

            switch(escolha){
                case 1:
                    arquivo = fopen("usuarios.txt", "r");
                    usuario= logar(arquivo);
                    if(usuario.id != -1){
                        system("cls");
                        printf("\n\nLogin realizado com sucesso!\n\n");
                        logado = 1;
                        system("pause");
                        system("cls");
                        break;
                    }else{
                        system("cls");
                        printf("\n\nEmail ou senha incorreto(s)!\n\nAperte Enter para continuar....");
                        getchar();
                    }
                    fclose(arquivo);
                    break;
                case 2:
                    arquivo = fopen("usuarios.txt", "a");
                    cadastrarUsuario(arquivo);
                    system("cls");
                    fclose(arquivo);
                    break;

                default:
                    printf("\nDigite uma opção valida (Tecle ENTER).\n");
                    getch();
                }
                system("cls");
        }

        //Opções do usuario
        if(logado == 1){
            do{
                menuLogado();
                scanf("%d", &escolha);
                setbuf(stdin,NULL);

               if(escolha == 1){
                   int newop;
                   menuGerenContatos();
                   scanf("%d", &newop);
                   setbuf(stdin,NULL);
                   switch (newop){
                        case 1:
                            //adicionar contato
                            cadastrarContato(usuario.id);

                            break;
                        case 2:
                            //excluir contato
                            system("cls");
                            excluiContato(usuario);
                            printf("Tecle ENTER para voltar ao Menu ");
                            getchar();
                            break;
                        case 3:
                            //listar
                            system("cls");
                            listarContatos(usuario);
                            printf("Tecle ENTER para voltar ao Menu ");
                            getchar();
                            system("cls");
                            break;
                        case 4:
                            //Voltar
                            break;

                        default:

                            printf ("Digite uma tecla válida.\n");
                            system ("pause");

                    }

                }else if(escolha == 2){
                    int newop;
                    menuConversas();
                    scanf("%d", &newop);

                    switch (newop){
                        case 1:
                            //enviar mensagem contato
                            enviarMensagem(usuario);

                            break;
                        case 2:
                            //enviar mensagem grupo
                            printf("\nFalta fazer\n");
                            break;
                        case 3:
                            //VOLTAR
                            break;
                        default:
                            printf ("Digite uma tecla válida.\n");
                            system("pause");
                            system("cls");
                    }
                }/*else if(escolha == 3){
                    //Gerenciar grupos
                    int esco;
                    gerenciarGrupos();
                    scanf("%d", &esco);
                    setbuf(stdin,NULL);
                    tGrupo grupo;
                    switch(esco){
                        case 1:
                            grupo.id_usuario = usuario.id;
                            criarGrupo(grupo);

                            break;
                        case 2:
                            //Add contato em um grupo
                            //addContatoNoGrupo(usuario);
                            break;
                        case 3:
                            //Remover contato de um grupo
                            break;
                        case 4:
                            // Editar grupo
                            break;
                        case 5:
                            // Remover grupo
                            break;
                        case 6:
                            //Voltar
                            break;
                        default:
                            printf ("Digite uma tecla válida.\n");
                            system("pause");
                            system("cls");
                    }/
                }*/

            }while(escolha != 4);
        }

    }
}
