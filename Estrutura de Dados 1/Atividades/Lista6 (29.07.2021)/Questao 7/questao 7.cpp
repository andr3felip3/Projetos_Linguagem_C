/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 29/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 6

QUESTAO 7) Escreva uma função recursiva que calcule a sequência dada por: 

-	F(1) = 1 
-	F(2) = 2 
-	F(n) = 2 * F(n-1) + 3 * F(n-2).

A leitura dos dados de entrada das funções deve ser realizada no programa principal e
as respostas também devem ser exibidas no programa principal. Cada função deve
ser implementada separadamente e chamadas no programa principal.

*/

#include<stdio.h>
#include<stdlib.h>
int recursao(int n){
  int r1,r2,R;
    r1=(2*recursao(n-1));
	if(r1!=0)
      r2=(3*recursao(n-2));
    else return 0;
    if(r2!=0) 
     R=r1+r2;
    else return 0;
  return R;
} 

int main() {
printf("\tLISTA 6  - Questao 7 \n\n");
   int n,r;
   printf("Entre com um numero: ");
   scanf("%d",&n);
   
   r=recursao(n);
   
   printf("%d",r);
   }
