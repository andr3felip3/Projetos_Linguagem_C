/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 16/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 1

QUESTAO 8) Fazer um programa que leia 2 valores inteiros para duas variáveis A e B, escreva os conteúdos 
das variáveis na tela, e em seguida troque os conteúdos das duas variáveis (use uma variável 
auxiliar para isto), exibindo novamente os seus conteúdos na tela. Exemplo de tela de saída: 

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
