/***************************************************************
* Alunos: André Felipe e Tiago Pereira
* Curso: Ciência da computação
* Trabalho 1: Dicionário de Verbos Irregulares Inglês-Português*
organizado com uma Lista Encadeada Dinâmica
* Estrutura de Dados I-- 2017 -- DACC/UNIR, Profa. Carolina Watanabe
* Compilador: Dev c/c++  versão: 5.1
* Sistema Operacional: Windows 10                                   *
***************************************************************/

#include<stdio.h>
#include<string.h>
#include "lista.h"
#include <stdlib.h>

int main() {
		int op,chave,tam,num;
		Lista L;
		tipo_elem v;
		define(&L);/// criar vazia já é criada automaticamente ao iniciar o programa
		char p[30],e[30];
		
	
		//////////////Abre arquivo texto com função de leitura e escrita////////////
		
		FILE *arq = fopen("tradu.txt", "r+");
		  if(arq == NULL)
				printf("Erro, nao foi possivel abrir o arquivo\n");
		  else  {
			 while( !feof(arq) ){
					fscanf(arq,"%s %s\n",&e,&p);
					//printf("ingles=%s portugues=%s \n",e,p);
					 strcpy(v.engh,e);
				 	 strcpy(v.port,p);
				 	 inserir_inicio(&L,v);
		            }
			    fclose(arq);// fecha arquivo
				}
		///////////////////////////////////////////////////////////////////////////
		
		do{
			printf("1-Inserir Palavra\n");
			printf("2-Remover\n");
			printf("3-Exibir todos os elementos\n");
			printf("4-Numero de elementos\n");
			printf("5-Esvaziar a Lista\n");
			printf("6-Buscar Uma Palavra\n");
			printf("7-Sair\n\n");
			printf("Digite a opcao\n");
			scanf("%d",&op);
			switch(op){
				case 1: //inserir palavra
						printf("Deja inserir quantas Palavras: \n");
						scanf("%d",&num); //numero de palavras a ser inserida
						while(num!=0){
							printf("Digite a palavra em INGLES a ser guardada: ");
							setbuf(stdin,NULL); //limpa o buffer do teclado
							gets(e); //ler a palavra
							
							printf("Digite a TRADUCAO da PALAVRA a ser guardada: ");
							setbuf(stdin,NULL);
							gets(p);
							
							inserir_palavra(&v,e,p);
							
							if(inserir_inicio(&L,v))
								printf("Palavra inserida com Sucesso\n");
							else
								printf("\nNão foi Possivel exibir\n");
							num--;
						}
						
				break;
				
				case 2: //remover
					printf("Digite a palavra em PORTUGUES a ser Removida: ");
					setbuf(stdin,NULL);
					gets(p);
					
					if(remover(&L,p))
						printf("Palavra Removida com Sucesso\n");
					else
						printf("Palavra Nao Removida\n");
				break;
				
				case 3: //exibir
					printf("\nINGLES-------PORTUGUES\n\n");
					exibir(&L);
					printf("\n");
					break;
					
				case 4: //numero de elementos
					tam = tamanho(&L);
					printf("Numero de Palavras guardadas=%d\n",tam);
				break;
				
				
				case 5: //esvaziar lista 
						esvaziar(&L);
						printf("Palavras Retiradas!\n");
				break;
				
				case 6: //Buscar Palavra
					printf("Digite a palavra em INGLES a ser Buscada: ");
					setbuf(stdin,NULL);
					gets(e);
							
					if(Busca(&L,e)){
						printf("Palavra Encontrada com sucesso!\n");
							
					}
					else{
						printf("Palavra nao encontrada\n");
						
						
					    if(arq == NULL)
							printf("Erro, nao foi possivel abrir o arquivo\n");
								
					   else {
							printf("\n A Palavra atual sera gravada no arquivo texto\n");
							printf("\nDigite a TRADUCAO da palavra para gravar no arquivo texto\n");
							setbuf(stdin,NULL);
							gets(p); printf("\n"); 
							
							if(FILE *arq = fopen("tradu.txt", "a+")){	// a palavra não foi encontrada e será salva no arquivo texto	
								fprintf(arq,"\n%s %s",e,p);
								fclose(arq);
								printf("palavra inserida no arquivo texto com sucesso\n");
								
								strcpy(v.engh,e);
								strcpy(v.port,p);
								inserir_inicio(&L,v);
							}
							else{
								printf("Arquivo nao encontrado\n");
							}
										
						}
					}
				break;
			}
			system("pause");
			system("cls");
		}while(op!=7);
		
		esvaziar(&L);
		return 0;
	}
