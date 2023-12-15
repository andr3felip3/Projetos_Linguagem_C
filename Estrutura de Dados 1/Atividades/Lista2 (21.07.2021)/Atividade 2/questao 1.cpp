/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 21/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 2

QUESTAO 1) Faça um programa que leia um caractere do teclado e verifique se é um caractere de pontuação: ‘,’ ou ‘.’ 
ou ‘;’ ou ‘!’ ou ‘?’. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 2  - Questao 1 \n\n");
   char c;
   printf("Entre com o caracter: ");
   scanf("%c",&c);
   if( (c==',')|| (c=='.')||(c==';')||(c=='!')||(c=='?') )
   printf("\nO \" %c \" eh um caracter de pontuacao !\n",c);
   else printf("\nO \" %c \" nao eh caracter de pontuacao\n",c);
	return 0;
}
