/***************************************************************
* Aluna: JULIANA FERREIRA GUARLOTH *
* Curso: Ciência da Computação*
* Trabalho 2: Dicionário de Verbos Irregulares Inglês-Português*
* organizado com uma AVL *
* Estrutura de Dados I-- 2021 -- DACC/UNIR, Profa. Carolina Watanabe *
* Compilador: Dev-C++ ... versão 5.11 *
* Sistema Operacional: Windows 7 *
***************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"avl.h"

int main() {
		Arvore t;
		int op, chave;
		char e[100], p[100];
		tipo_elem v;
		
		define(&t);
			//abrindo o arquivo txt
		FILE *arq = fopen("arq.txt","r+");
		if(arq==NULL)
			printf("\n arquivo inexistente!\n");
		else{
			while(!feof(arq)){
				fscanf(arq, "%s %s\n", e, p);
				strcpy(v.e, e);
				strcpy(v.p, p);
				inserir(&t, v);
				
			}
			// fechando o arquirvo
			fclose(arq);	
		}
		do{
			// menu
			printf("1-Vazia\n");
			printf("2-Inserir\n");
			printf("3-Exibir Palavras do Dicionario\n");
			printf("4-Contar palavras do Dicionario\n");
			printf("5-Esvaziar\n");
			printf("6-Busca\n");
			printf("7-Sair\n");
			
			printf("digite a opçao: \n");
			scanf("%d",&op);
			printf("\n\n");
			
			switch(op){
				case 1: // vazia
					if(vazia(&t))
						printf("\nArvore vazia\n");
					else
						printf("\nArvore nao vazia\n");
				break;
				
				
				case 2: // inserir
					printf("Digite a palavra em INGLES a ser guardada: ");
					setbuf(stdin,NULL);
					gets(e);
					
					printf("Digite a TRADUCAO da PALAVRA a ser guardada: ");
					setbuf(stdin,NULL);
					gets(p);
								
					strcpy(v.e,e);
				 	strcpy(v.p,p);
				 	inserir(&t,v);
					printf("\nPalavra inserida com Sucesso!\n");
				break;
				
				
				
				case 3: // exibir pre-ordem
					if(vazia(&t)){
						printf("Nao ha elementos na arvore!");
					}
					else
						exibir_preordem(&t);
					printf("\n\n");

				break;
				
				
				
				case 4: // numero de elementos
					printf("\nHa %d elementos.\n", num_elementos(&t));
				break;
				
				
				
				case 5: // esvaziar
					esvaziar(&t);
				break;
				
				
				
				case 6: // busca
					printf("Digite uma palavra em ingles: ");
					setbuf(stdin, NULL);
					gets(e);
					
					if(busca(&t,e))
						printf("\n");
					else{
						printf("Palavara nao encontrada!\n");
						printf("Digite a tradução: \n");
						setbuf(stdin, NULL);
						gets(e);
						
						if(FILE *arq = fopen("arq.txt","a+")){
							fscanf(arq, "%s %s\n", e, p);
							fclose(arq);
							strcpy(v.e, e);
							strcpy(v.p, p);
							inserir(&t,v);		
						}
						else printf("Arquivo nao encontrado!\n");
					}				
				break;		
			}
		}
		while(op!=7);
		return 0;
	}
