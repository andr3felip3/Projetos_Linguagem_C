/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 28/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 5

QUESTAO 6) Faça um programa que leia uma quantidade qualquer de números armazenando-os na memória e 
pare a leitura quando o usuário entrar com um número negativo. Em seguida, imprima o vetor lido. 
Use a função REALLOC. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 5  - Questao 6 \n\n");
int *p;
int j,i=1,opcao;
p=(int*) malloc(10);
p=(int*) realloc(NULL,0);
while(opcao>=0){
	p=(int*) realloc(p,i);
	printf("Entre com um numero inteiro (Numero negativo sai): ");
	scanf("%d",&p[i]);
	opcao=p[i];
	i++;
}
printf("\n*** VETOR ***\n");
for(j=1;j<i-1;j++)
  printf("\nPosicao [%d]: %d",j,p[j]);
  printf("\n");
  return 0;
}
