#include "funcoes.h"

//Recebe o ID do usuario para que o Contato poss aser vinculado ao usuario atual
void cadastrarContato(int idUsuario){
    tContato contato;
    FILE* arquivo;

    system("cls");
    printf("Informe o nome: ");
    gets(contato.nome);
    setbuf(stdin,NULL);

    printf("Informe o IP: ");
    gets(contato.ip);
    setbuf(stdin,NULL);

    arquivo = fopen("contatos.txt", "r");

    if(verificaContato(contato, arquivo) == 1){
        if(arquivo == NULL){
            printf("Erro");
        }else{
            arquivo = fopen("contatos.txt", "a");
            fprintf(arquivo, "%d,%s,%s;\n", idUsuario, contato.nome, contato.ip);
            printf("\nContato cadastrado com sucesso!\n\n");
            fclose(arquivo);
        }
    }else{
        printf("\n\n Contato já existe! \n\n");
    }

    printf("Tecle ENTER para voltar ao Menu ");
    getchar();
    system("cls");
}

//Testar se o contato já existe, retorna 0 caso exista
// Não funciona
int verificaContato(tContato contato, FILE* arquivo){
    char* pedaco = NULL;
    char linha[100];

    if(arquivo == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{
        while((fgets(linha, sizeof(linha), arquivo)) != NULL){
            if(linha[0] != '\n'){

                pedaco = strtok(linha, ",");
                pedaco = strtok(NULL, ",");
                //printf("\ncontato.nome = %d e ", strlen(contato.nome));
                //printf("pedaco = %s\n", pedaco);
                if(strcmp(contato.nome, pedaco) == 0){
                    pedaco = strtok(NULL, ";");
                    if(strcmp(contato.ip, pedaco) == 0){
                        printf("\n\n\n");
                        fclose(arquivo);
                        return 0;
                    }
                }
            }else{
                continue;
            }
         }
         fclose(arquivo);
         return 1;
    }
}

//
void excluiContato(tUsuario usuario){
    char linha[100];
    int i = 0, cod = -1, qtd = 0, excluiu;
    char* pedaco = NULL;
    tContato arrayContatos[100];
    FILE* arquivo;
    arquivo = fopen("contatos.txt", "r");

    //Salavar todos os contatos do arquivo no array de contatos
    if(arquivo == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{
        while((fgets(linha, sizeof(linha), arquivo)) != NULL){
            pedaco = strtok(linha, ",");
            arrayContatos[i].id_usuario = atoi(pedaco);
            pedaco = strtok(NULL, ",");
            strcpy(arrayContatos[i].nome, pedaco);

            pedaco = strtok(NULL, ";");
            strcpy(arrayContatos[i].ip, pedaco);

            i++;
        }
        qtd = i;
        i=0;
        fclose(arquivo);

        //listar apenas os contatos que pertencam ao usuario atual
        arquivo = fopen("contatos.txt", "r");
        while((fgets(linha, sizeof(linha), arquivo)) != NULL){
            if(arrayContatos[i].id_usuario == usuario.id){
                printf("\nCodigo: %d\n", i);
                printf("    Nome: %s\n", arrayContatos[i].nome);
                printf("    IP: %s\n", arrayContatos[i].ip);
            }
            i++;
        }
        fclose(arquivo);
        printf("Digite o codigo do contato que deseja excluir: ");
        scanf("%d", &cod);
        setbuf(stdin,NULL);

        //Testa se o codigo do contato é valido
        if(arrayContatos[cod].id_usuario == usuario.id){
            arquivo = fopen("contatos.txt", "w");
             //Reescreve todos os contatos, exceto o especificado
             for(i = 0; i < qtd; i++){
                if(arquivo == NULL)
                    printf("Erro");
                    else{
                        if(i != cod ){
                            fprintf(arquivo, "%d,%s,%s;\n", arrayContatos[i].id_usuario, arrayContatos[i].nome, arrayContatos[i].ip);
                        }
                    }
              }
              printf("\nPessoa excluida com sucesso!\n");
        }else{
            printf("\nO codigo digitado não pertence a nenhum dos seus usuários!!\n");
            system("pause");
        }
    }
    fclose(arquivo);
}

void listarContatos(tUsuario usuario){
    char linha[100];
    int i = 0, cod = -1, qtd = 0;
    char* pedaco = NULL;
    tContato contato;
    FILE* arquivo;
    arquivo = fopen("contatos.txt", "r");

    if(arquivo == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{
        while((fgets(linha, sizeof(linha), arquivo)) != NULL){
            //Tratar em caso de a linha estar em branco
            if(linha[0] != '\n'){
                pedaco = strtok(linha, ",");
                if(atoi(pedaco) == usuario.id){
                    pedaco = strtok(NULL, ",");
                    strcpy(contato.nome, pedaco);

                    pedaco = strtok(NULL, ";");
                    strcpy(contato.ip, pedaco);

                    printf("\nCodigo: %d\n", i);
                    printf("    Nome: %s\n", contato.nome);
                    printf("    IP: %s\n", contato.ip);
                    i++;
                }
            }else{
                continue;
            }
         }
            fclose(arquivo);
    }
}
