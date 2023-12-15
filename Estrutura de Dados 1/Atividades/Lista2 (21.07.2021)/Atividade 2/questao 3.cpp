/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 21/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 2

QUESTAO 3) Ler um número inteiro e exibir na tela a mensagem ‘Par’ se ele for um número par, ou ‘Ímpar’ se ele for 
um número ímpar. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 2  - Questao 3 \n\n");
int n,r;
printf("Entre com um numero inteiro: ");
scanf("%d",&n);
r=n%2;
   if(r==0)
   printf("\nO numero %d eh par",n);
   else printf("\nO numero %d eh impar",n);
	return 0;
}
