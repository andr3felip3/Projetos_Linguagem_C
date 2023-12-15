/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 28/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 5

QUESTAO 3) Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas. Imprima o 
endereço de cada posição dessa matriz. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 5  - Questao 3 \n\n");
   float m[3][3];
   int i,j;
   printf("\t\t\t\t*** MATRIZ ***\n\n");
   
   for(i=0;i<3;i++){
   	for(j=0;j<3;j++){
   		printf("\tposicao[%d,%d]: %x",i,j,&m[i][j]);
	   } printf("\n\n");
   }
	return 0;
}
