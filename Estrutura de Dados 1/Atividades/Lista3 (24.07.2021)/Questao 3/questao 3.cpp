/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 24/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 3

QUESTAO 3) Leia duas matrizes 4x4 e escreva uma terceira com os maiores valores de cada posição das matrizes lidas. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 3  - Questao 3 \n\n");
int A[4][4];
int B[4][4];
int C[4][4];
int i,j;
int maior=-1;

printf("\n*** Entrada da Matriz A ***\n\n");
   for(i=0;i<4;i++){
   for(j=0;j<4;j++){
      printf("Matriz A(%d,%d): ",i,j);
	  scanf("%d",&A[i][j]);	  
  }
}
printf("\n*** Entrada da Matriz B ***\n\n");
   for(i=0;i<4;i++){
   for(j=0;j<4;j++){
      printf("Matriz B(%d,%d): ",i,j);
	  scanf("%d",&B[i][j]);	 
   }
 }  
   printf("\n*** Os maiores valores de cada posicao sao: ***\n\n");
   for(i=0;i<4;i++){
   for(j=0;j<4;j++){
   	if (A[i][j]>B[i][j]) 
			  C[i][j]=A[i][j];
			else C[i][j]=B[i][j];
	   
     printf("Matriz C(%d,%d): %d\t",i,j,C[i][j]);
  } printf("\n\n");
}
	return 0;
}
