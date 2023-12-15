/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 16/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 1

QUESTAO 2)Leia um número inteiro e imprima seu sucessor e seu antecessor. 
 
*/
#include<stdio.h>
#include<stdlib.h>

int main() {
	printf("\tLISTA 1 - Questao 02\n\n");
	int a;
	printf("Entre com um numero inteiro: ");
	scanf("%d",&a);
	printf("\nO sucessor do %d eh o %d\n",a,a+1);
	return 0;
}
