/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: Andr� felipe costa da silva
DATA: 28/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 5

QUESTAO 5) Crie um programa que: 
(a) Aloque dinamicamente um array de 5 n�meros inteiros; 
(b) Pe�a para o usu�rio digitar os 5 n�meros no espa�o alocado; 
(c) Mostre na tela os 5 n�meros; 
(d) Libere a mem�ria alocada. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 5  - Questao 5 \n\n");
   int *p= (int*)malloc(5*sizeof(int));
   int i;
   for(i=0;i<5;i++){
   	printf("\nAdicione um numero inteiro: ");
   	scanf("%d",&p[i]);
   }
   getchar();
   printf("\nNumeros inseridos - Aperte enter para exibir ");
   getchar();
   printf("\n NUMEROS INSERIDOS \n");
   for(i=0;i<5;i++)
      printf("\nVetor[%d]: %d",i,p[i]);
    printf("\n\nAperte enter para limpar a memoria ");
    getchar();
    p=(int*) realloc(NULL,0);
	printf("\nMemoria Liberada\n");
	
	for(i=0;i<5;i++)
      printf("\nVetor[%d]: %d",i,p[i]);
    
	return 0;
}
