/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: Andr� felipe costa da silva
DATA: 16/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 1

QUESTAO 8) Fazer um programa que leia 2 valores inteiros para duas vari�veis A e B, escreva os conte�dos 
das vari�veis na tela, e em seguida troque os conte�dos das duas vari�veis (use uma vari�vel 
auxiliar para isto), exibindo novamente os seus conte�dos na tela. Exemplo de tela de sa�da: 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 1  - Questao 8 \n\n");
   int A,B,aux;
   printf("Entre com o valor de A: ");
   scanf("%d",&A);
   printf("Entre com valor de B: ");
   scanf("%d",&B);
   printf("\nAntes da troca A=%d e B=%d\n",A,B);
   aux=A; A=B; B=aux;
   printf("\nDepois da troca A=%d e B=%d\n",A,B);
	return 0;
}
