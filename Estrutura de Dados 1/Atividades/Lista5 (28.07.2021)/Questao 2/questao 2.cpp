/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 28/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 5

QUESTAO 2) Crie um programa que contenha um array de float contendo 10 elementos. Imprima o endereço de 
cada posição desse array. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 5  - Questao 2 \n\n");
   float a[10];
   int i;
   printf("\t*** VETOR ***\n\n");
   for(i=0;i<10;i++)
    printf("posicao[%d]: %x\n",i,&a[i]);
	return 0;
}
