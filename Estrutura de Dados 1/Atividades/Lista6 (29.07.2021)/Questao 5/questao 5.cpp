/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 29/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 6

QUESTAO 5) Faça uma função que forneça como parâmetro dois números e retorne esses valores trocados.

*/

#include<stdio.h>
#include<stdlib.h>
struct inverso{
	int a,b;
};
inverso troca(int x,int y){
  inverso i;
  i.a=y;
  i.b=x;
  return i;
}

int main() {
	inverso i;
printf("\tLISTA 6  - Questao 5 \n\n");
  int a,b;
  printf("Entre com um numero: ");
  scanf("%d",&a);
  printf("Entre com um numero: ");
  scanf("%d",&b);
  printf("\nAntes da troca A: %d B: %d\n",a,b);
 i=troca(a,b);
  printf("\nApos a troca A: %d B: %d\n",i.a,i.b);
	return 0;
}
