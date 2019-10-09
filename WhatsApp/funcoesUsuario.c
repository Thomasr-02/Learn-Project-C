#include "funcoes.h"

// Retorna o ID do usuario
tUsuario logar(FILE *arquivo){
    system("cls");
    tUsuario usuario;

    printf("Informe o login: ");
    gets(usuario.login);
    setbuf(stdin,NULL);
    printf("Informe a senha: ");
    gets(usuario.senha);
    setbuf(stdin,NULL);

    // Autenticar
    char linha[50];
    char* pedaco = NULL;
     if(arquivo == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
     else{
         while((fgets(linha, sizeof(linha), arquivo)) != NULL){
            usuario.id = atoi(strtok(linha, ","));//Primeira intém é o ID
            pedaco = strtok(NULL, ",");//Segundo é o login
            if(strcmp (pedaco, usuario.login) == 0){
                pedaco = strtok(NULL, ",");
                if(strcmp (pedaco, usuario.senha) == 0){
                    pedaco = strtok(NULL, ",");
                    pedaco = strtok(NULL, ",");// Pega o IP

                    strcpy(usuario.ip, pedaco);
                    return usuario;
                }
            }
        }
    }
    //Caso não encontre o login
    usuario.id = -1;
    return usuario;
}



void cadastrarUsuario(){
    tUsuario usuario;
    FILE *arquivo;
    arquivo = fopen("usuarios.txt", "r");

    system("cls");
    printf("Informe o nome: ");
    gets(usuario.nome);
    setbuf(stdin,NULL);

    printf("Informe o IP: ");
    gets(usuario.ip);
    setbuf(stdin,NULL);

    printf("Informe o Login: ");
    gets(usuario.login);
    setbuf(stdin,NULL);

    printf("Informe a Senha de acesso: ");
    gets(usuario.senha);
    setbuf(stdin,NULL);

    usuario.id = verificaID();
    //Testar se o usuario já existe

    if(verificaUsuario(usuario, arquivo) == 1){
        arquivo = fopen("usuarios.txt", "a");
        if(arquivo == NULL){
            printf("Erro");
        }else{
            fprintf(arquivo, "%d,%s,%s,%s,%s; \n",  usuario.id, usuario.login, usuario.senha, usuario.nome, usuario.ip);
            fclose(arquivo);
            printf("\nCadastro realizado com sucesso!\n\n");
        }
    }

    printf("Tecle ENTER para voltar ao Menu ");
    getchar();
    system("cls");

}

//Testar se o usuario já existe, retorna 0 caso exista
int verificaUsuario(tUsuario usuario, FILE* arquivo){
    char* pedaco = NULL;
    char linha[100];

    if(arquivo == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
        printf("\n\nDeu NULO\n\n");
    }else{
        while((fgets(linha, sizeof(linha), arquivo)) != NULL){
            if(linha[0] != '\n'){
                pedaco = strtok(linha, ",");
                pedaco = strtok(NULL, ",");

                if(strcmp(usuario.login, pedaco) == 0){
                    printf("\nO Login já existe!\nUsuário não cadastrado!\n\n");
                    return 0;
                }
            }else{
                continue;
            }
         }
         fclose(arquivo);
         return 1;
    }
}

//Ter que dar uma conferida
void excluiUsuario(FILE*arquivo){

    char linha[100];
    int i = 0, cod = -1, qtd = 0;
    char* pedaco = NULL;
    tUsuario arrayUsuarios[100];

    if(arquivo == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{
        while((fgets(linha, sizeof(linha), arquivo)) != NULL){
            pedaco = strtok(linha, ",");//Retorna um ponteiro de chars
            strcpy(arrayUsuarios[i].nome, pedaco);

            pedaco = strtok(NULL, ",");
            strcpy(arrayUsuarios[i].ip, pedaco);

            printf("\nCodigo: %d\n", i);
            printf("    Nome: %s\n", arrayUsuarios[i].nome);
            printf("    IP: %s\n", arrayUsuarios[i].ip);
            i++;
         }
         qtd = i;
         fclose(arquivo);
         printf("Digite o codigo da pessoa que deseja excluir: ");
         scanf("%d", &cod);
         setbuf(stdin,NULL);
         arquivo = fopen("contatos.txt", "w");

        for(i = 0; i < qtd; i++){
            if(arquivo == NULL)
                printf("Erro");
            else{
                if(i != cod){
                    fprintf(arquivo, "%s, %s \n", arrayUsuarios[i].nome, arrayUsuarios[i].ip);
                }
            }
        }
            printf("\nPessoa excluida com sucesso!\n");
        }
}

//Retorna o ultimo ID (identificador) cadastrado no arquivo Usuario
int verificaID(){
    char linha[100], str[10];
    int id = 0, cod = -1, qtd = 0;
    char* pedaco = NULL;
    tUsuario arrayUsuarios[100];
    FILE* arquivo = fopen("usuarios.txt", "r");

    if(arquivo == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{
        //Pega o id da ultima linha
        while( fgets(linha, sizeof(linha), arquivo) !=NULL ) {}
        char bagui[10];
        strcpy(str, strtok(linha, ","));
        if(str != NULL){
            id = atoi(str);
        }
    }
    fclose(arquivo);
    id += 1;
    return id;
}

void listarUsuarios(FILE *arquivo){
    char linha[100];
    int i = 0, cod = -1, qtd = 0;
    char* pedaco = NULL;
    tUsuario arrayUsuarios[100];

    if(arquivo == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{
        while((fgets(linha, sizeof(linha), arquivo)) != NULL){
            pedaco = strtok(linha, ",");//Retorna um ponteiro de chars
            strcpy(arrayUsuarios[i].nome, pedaco);

            pedaco = strtok(NULL, ",");
            strcpy(arrayUsuarios[i].ip, pedaco);

            printf("\nCodigo: %d\n", i);
            printf("    Nome: %s\n", arrayUsuarios[i].nome);
            printf("    IP: %s\n", arrayUsuarios[i].ip);
            i++;
         }
    qtd = i;
    fclose(arquivo);
    }
}
