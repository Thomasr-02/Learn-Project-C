/****
 * Título: [EXERCICIOLP1]
 * Autor: [Thomas Ribeiro de Araújo]
 * Data de Criação: [05/04/2019]
 * Última alteração: [11/04/2019]
 * Descrição Geral: [Cadastramento de pessoas]
 * ****/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	char pessoa[40];
	int idade;
	float sal;
	
}pess;

int main (){
	// CRIANDO VARIAVEIS, ARQUIVOS
	int X,str;
	FILE *arq;
	int tam;
	pess PESSOAS[40];
	char remove[100];
	int pessoa_q, i;
	while(X != 4){
		//MENU
		printf ("\t\tDigite a opcao que deseja\n\t-1-Incluir Pessoas\n\t-2-Listar Pessoas\n\t-3-Remover Pessoas\n\t-4- Sair\n");
		scanf ("%d", &X);
		int i,j;
		switch (X){
			case 1:
				//OPCAO DE INCLUIR PESSOAS
				system ("cls");
				//
				arq=fopen("bancodepessoas.txt", "a");
				if (arq == NULL){
					printf ("Problemas ao abrir o arquivo.");
					fclose(arq);
				}else{
					int k,i,N;
					k=0;				
					// For para preencher o arquivo
					setbuf (stdin, NULL);
					printf ("Digite: NOME IDADE SALARIO.\n");
					//RECEBENDO INFORMAÇÕES DO USUARIO
					scanf ("%s %d %f", &PESSOAS[0].pessoa, &PESSOAS[0].idade, &PESSOAS[0].sal);	
					//ESCREVENDO NO ARQUIVO
					fprintf (arq, "%s %d %.2f \n", PESSOAS[0].pessoa, PESSOAS[0].idade, PESSOAS[0].sal);
					k+=1;
					fclose(arq);
					system ("cls");
	
				}			

				break;
			case 2:
				//OPCAO DE LISTAR PESSOAS
				system ("cls");
	
				arq = fopen("bancodepessoas.txt","r");
				//VERIFICANDO SE EXISTE PESSOAS NO ARQUIVO
                if(arq == NULL){
                    printf("Nao ha pessoas cadastradas.\n");
                    
                }
				else if (arq == 0){
					// caso o arquivo esteja vazio, exibe mensagem:
					printf ("Não contém pessoas listadas.\n");
				}
				 else {
                 	i=0;
                    while(!feof(arq)){
                    	// percorrendo carctere por carctere e printando na tela
                    	if (strcmp(PESSOAS[0].pessoa, "") != 0){
							//LER O ARQUIVO E IMPRIMINDO PARA O USUARIO AS PESSOAS LISTADAS 
							fscanf(arq, "%s %d %f\n", &PESSOAS[i].pessoa, &PESSOAS[i].idade, &PESSOAS[i].sal);				
							printf("nome: %s idade: %d salario: %.2f\n\n", PESSOAS[i].pessoa, PESSOAS[i].idade, PESSOAS[i].sal);
							i++;
						} else{
							printf("Nao ha pessoas cadastradas.\n");
							break;
						}
					}
					
					pessoa_q = i;
                }
                fclose(arq);
				break;
			case 3:
				
				arq= fopen ("bancodepessoas.txt", "w");
				//RECENDO DO USUARIO PESSOA PARA REMOVER
				printf("Digite o nome da pessoa que deseja remover: ");
				scanf("%s", &remove);
				
				for (i = 0; i < pessoa_q; i++){
					//COMPARANDO STRING 
					if (strcmp(PESSOAS[i].pessoa, remove) != 0){
						fprintf(arq, "%s %d %.2f\n", PESSOAS[i].pessoa, PESSOAS[i].idade, PESSOAS[i].sal);
						printf ("Pessoa nao encontrada./n");
						
					}
				
					 else{
						//REMOVENDO PESSOA DA POSICAP [I]
						strcpy(PESSOAS[i].pessoa, "");
						PESSOAS[i].idade = NULL;
						PESSOAS[i].sal = 0.0;
						printf ("\n\tRemovido.\n\n");
						
					}
					system ("cls");
				}
				fclose (arq);
				break;
		
			case 4:
				//OPCAO DE SAIR DO PROGRAMA
				printf ("\t\tSaindo...");
				sleep (1);
				break;
			default:
				//OPCAO PARA TRATAMENTO DE ERRO
				printf ("\nOpcao digitada incorretamente.\n");
		}
	}
}
