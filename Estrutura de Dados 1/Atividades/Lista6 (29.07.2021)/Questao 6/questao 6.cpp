/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: Andr� felipe costa da silva
DATA: 29/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 6

QUESTAO 6) Crie uma fun��o recursiva que receba um n�mero inteiro positivo N e calcule o somat�rio dos n�meros de 1 a N.
*/

#include<stdio.h>
#include<stdlib.h>

int soma(int n){
   if(n==0)
     return 0;
  else 
	return n+soma(n-1);
}


int main() {
printf("\tLISTA 6  - Questao 6 \n\n");
   int s,n;
   printf("Entre com um numero inteiro: ");
   scanf("%d",&n);
   s=soma(n);
   printf("\nSoma: %d",s);
	return 0;
}
