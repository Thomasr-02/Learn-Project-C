#include "funcoes.h";
#include <winsock2.h>
#include <stdio.h>


//Cliente
void InitWinsock()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
}


void enviarMensagem(tUsuario usuario)
{
    SOCKET socketC;

    char msg[100];
    int porta;
    char linha[100];
    char* pedaco = NULL;
    tContato arrayContatos[100];
    int i = 0, qtd = 0, cod=-1;

    //Escolher o contato
    FILE* arquivo;
    arquivo = fopen("contatos.txt", "r");
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
    }
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
    printf("Digite o codigo do contato que deseja enviar a mensagem: ");
    scanf("%d", &cod);
    setbuf(stdin,NULL);

    //Verificar se o codigo existe ou se pertence a esse usuario:

    // **********


    printf("Digite a mensagem: ");
    gets(msg);
    setbuf(stdin,NULL);
    printf("Digite a porta: ");
    scanf("%d",&porta);
    setbuf(stdin,NULL);

    InitWinsock();
    struct sockaddr_in local;
    struct sockaddr_in from;
    int fromlen = sizeof(from);

    struct sockaddr_in serverInfo;
    int len = sizeof(serverInfo);
    serverInfo.sin_family = AF_INET;//IPV4
    serverInfo.sin_port = htons(porta);//Porta 1234
    //serverInfo.sin_addr.s_addr = inet_addr("127.0.0.1");//IP do Server
    serverInfo.sin_addr.s_addr = inet_addr(arrayContatos[cod].ip);//IP do Server

    socketC = socket(AF_INET,SOCK_DGRAM,0);// Cria o socket
    char buffer[1024];
    ZeroMemory(buffer, sizeof(buffer));//Buffer
    strcpy(buffer, msg);//MEnsagem
    sendto(socketC, buffer, sizeof(buffer), 0, (SOCKADDR*)&serverInfo, len);//Enviar para  server



    int continua = 1;
    while (continua==1)
    {
        printf("Esperando resposta...\n");
        ZeroMemory(buffer, sizeof(buffer));
        if (recvfrom(socketC,buffer,sizeof(buffer),0,(SOCKADDR*)&from,&fromlen)!=SOCKET_ERROR)
        {
            printf("Resposta: %s\n",buffer);
            ZeroMemory(buffer, sizeof(buffer));
            continua = 0;
        }
    }

    closesocket(socketC);
    system("pause");
}
