/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 16/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 1

QUESTAO 5) Implemente um programa que calcule o ano de nascimento de uma pessoa a partir de sua idade e do ano atual. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 1  - Questao 5 \n\n");
int a,i;
printf("Entre com o ano atual: ");
scanf("%d",&a);
printf("Entre com a idade da pessoa: ");
scanf("%d",&i);
printf("\nO ano de nascimento da pessoa eh %d\n",a-i);

	return 0;
}
