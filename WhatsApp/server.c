#include "funcoes.h";
#include <winsock2.h>
#include <stdio.h>

void InitWinsock2()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
}


void iniciaServer()
{

    SOCKET socketS;

    int quantidade,i, porta;
    InitWinsock2();//Inicia o Winsock

    printf("Informe a porta: ");
    scanf("%d", &porta);

    struct sockaddr_in local;
    struct sockaddr_in from;
    int fromlen = sizeof(from);
    local.sin_family = AF_INET;//IPV4
    local.sin_port = htons(porta);//1234
    local.sin_addr.s_addr = INADDR_ANY;

    socketS = socket(AF_INET,SOCK_DGRAM,0);//Socket Servidor

    bind(socketS,(SOCKADDR* )&local,sizeof(local));//Associa o Socket ao IP do servidor
    while (1)
    {
        char buffer[1024];
        ZeroMemory(buffer, sizeof(buffer));
        printf("Waiting...\n");
        if (recvfrom(socketS,buffer,sizeof(buffer),0,(SOCKADDR*)&from,&fromlen)!=SOCKET_ERROR)
        {

            printf("Mensagem: %s\n",buffer);
            ZeroMemory(buffer, sizeof(buffer));
            printf("Resposta: ");
            scanf("%s",&buffer);
            sendto(socketS, buffer, sizeof(buffer), 0, (SOCKADDR*)&from, fromlen);

            printf("Mensagem: %s\n", buffer);
        }
    }
    closesocket(socketS);
    return 0;
}
