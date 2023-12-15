/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 24/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 3

QUESTAO 7) Faça um programa que receba um nome e retorne quantas letras tem esse nome. 

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
printf("\tLISTA 3  - Questao 7 \n\n");
   char nome[10];
   int i;
   printf("Entre com o nome: ");
  gets(nome);
  i=strlen(nome);
  printf("\nO nome: %s, tem %d letras\n",nome,i);
	return 0;
}
