/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 28/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 5

QUESTAO 4) Escreva um programa que imprima um vetor de inteiros na ordem inversa endereçando os 
elementos com um ponteiro. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 5  - Questao 4 \n\n");
   int v[5]={1,2,3,4,5};
   int *p;
   int i;
   for(i=4;i>=0;i--){
   	p=&v[i];
   	printf("\nVetor[%d]:%d ender:%x",i,v[i],p);
   }
	return 0;
}
