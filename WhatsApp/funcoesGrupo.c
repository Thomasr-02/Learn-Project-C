#include "funcoes.h"

void criarGrupo(tGrupo grupo)
{
    system("cls");
    char nomeGrupo[100];
    FILE *arquivo = NULL;
    arquivo = fopen("grupos.txt", "a");

    printf("Informe o nome do Grupo: ");
    gets(nomeGrupo);
    setbuf(stdin,NULL);

    printf("\n\nusuario.id = %d, nomeGrupo: = %s\n\n", grupo.id_usuario, nomeGrupo);

    if(arquivo == NULL)
    {
        printf("Erro");
    }
    else
    {
        fprintf(arquivo, "%d,%s,\n", grupo.id_usuario, nomeGrupo);
        printf("\nGrupo cadastrado com sucesso!\n\n");
        system("pause");
    }

    fclose(arquivo);
}

//Não funfa
void addContatoNoGrupo(tUsuario usuario)
{
    char linha[500];
    int i = 0, cod = -1, qtd = 0, excluiu;
    char* pedaco = NULL;
    tGrupo arrayGrupos[100];
    tContato arrayContatos[100];

    FILE* arquivo;
    arquivo = fopen("grupos.txt", "r");

    system("cls");
    //Salavar todos os contatos do arquivo no array de contatos
    if(arquivo == NULL)
    {
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }
    else
    {
        while((fgets(linha, sizeof(linha), arquivo)) != NULL)
        {
            pedaco = strtok(linha, ",");
            arrayGrupos[i].id_usuario = atoi(pedaco);
            pedaco = strtok(NULL, ",");
            strcpy(arrayGrupos[i].nome, pedaco);

            i++;
        }
        qtd = i;
        i=0;
        fclose(arquivo);

        //listar apenas os grupos do usuario atual
        printf("\n          Seus grupos:\n");
        arquivo = fopen("grupos.txt", "r");
        printf("\n_______________________________\n ");
        while((fgets(linha, sizeof(linha), arquivo)) != NULL)
        {
            if(arrayGrupos[i].id_usuario == usuario.id)
            {
                printf("\nCodigo: %d\n", i);
                printf("    Nome: %s\n", arrayGrupos[i].nome);

            }
            i++;
        }
        fclose(arquivo);
        printf("\n_______________________________\n: ");
        printf("\nInforme o codigo do Grupo: ");

        scanf("%d", &cod);
        setbuf(stdin,NULL);
        //Testar se o codigo do grupo é valido

        //***

        i=0;
        //Salavar todos os contatos do arquivo no array de contatos
        printf("DJ1 0.5\n");
        if(arquivo == NULL)
        {
            printf("Erro, nao foi possivel abrir o arquivo\n");
        }
        else
        {
            char linha2[100];
            arquivo = fopen("contatos.txt", "r");
            while((fgets(linha2, sizeof(linha2), arquivo)) != NULL)
            {
                printf("DJ while\n");
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
            printf("DJ1");
            //listar apenas os contatos que pertencam ao usuario atual
            arquivo = fopen("contatos.txt", "r");
            while((fgets(linha, sizeof(linha), arquivo)) != NULL)
            {
                printf("\nWHILE DO DJ\n");
                if(arrayContatos[i].id_usuario == usuario.id)
                {
                    printf("\nIF DO DJ\n");
                    printf("\nCodigo: %d\n", i);
                    printf("    Nome: %s\n", arrayContatos[i].nome);
                    printf("    IP: %s\n", arrayContatos[i].ip);
                }
                i++;
            }
            fclose(arquivo);

            printf("Digite o codigo do contato que deseja adicionar: ");
            scanf("%d", &cod);
            setbuf(stdin,NULL);
            printf("DJ2");
            //Testa se o codigo é valido
            if(arrayContatos[cod].id_usuario == usuario.id)
            {
                arquivo = fopen("contatos.txt", "w");
                //Reescreve todos os contatos, exceto o especificado
                for(i = 0; i < qtd; i++)
                {
                    if(arquivo == NULL)
                        printf("Erro");
                    else{
                        if(i != cod )
                        {
                            //fprintf(arquivo, "%d,%s,%s;\n", arrayContatos[i].id_usuario, arrayContatos[i].nome, arrayContatos[i].ip);
                            printf("Adicionando...\n");
                            system("Pause");
                        }
                    }
                }
                printf("\nContato adicionado com sucesso!\n");
            }
            else
            {
                printf("\nO codigo digitado não pertence a nenhum dos seus usuários!!\n");
                system("pause");
            }
        }
        fclose(arquivo);
    }
}

