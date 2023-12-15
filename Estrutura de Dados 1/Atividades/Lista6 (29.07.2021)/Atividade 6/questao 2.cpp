/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 29/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 6

QUESTAO 2) Função não-recursiva que retorne o fatorial de um número inteiro positivo N.
*/

#include<stdio.h>
#include<stdlib.h>
int fatorial(int n){
	int f=1,i;
	for(i=1;i<=n;i++)
	  f=f*i;
	return f;
}
int main() {
printf("\tLISTA 6  - Questao 2 \n\n");
   int a,f;
   printf("Entre com um numero inteiro: ");
   scanf("%d",&a);
   f=fatorial(a);
   printf("\nO fatorial de %d eh %d\n",a,f);
	return 0;
}
