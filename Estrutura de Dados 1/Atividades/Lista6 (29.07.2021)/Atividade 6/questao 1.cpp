/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: Andr� felipe costa da silva
DATA: 29/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 6

QUESTAO 1) Fa�a uma fun��o que receba dois n�meros inteiros positivos por par�metro e retorne 
a soma dos N n�meros inteiros existentes entre eles.

*/

#include<stdio.h>
#include<stdlib.h>
int soma(int a,int b){
	int s;
	s=a+b;
	return s;
}
int main() {
printf("\tLISTA 6  - Questao 1 \n\n");
   int a,b,s;
   printf("Entre com um numero inteiro: ");
   scanf("%d",&a);
   printf("Entre com um numero inteiro: ");
   scanf("%d",&b);
   s=soma(a,b);
   printf("\nA soma de %d + %d = %d\n",a,b,s);
	return 0;
}
