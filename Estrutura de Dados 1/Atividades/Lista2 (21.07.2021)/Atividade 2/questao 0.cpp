/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: Andr� felipe costa da silva
DATA: 21/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 2

QUESTAO 0) Fa�a um programa que leia um n�mero real. Se o n�mero for positivo, calcule a raiz quadrada do n�mero. 
Do contr�rio, imprima o n�mero ao quadrado.

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
printf("\tLISTA 2  - Questao 0 \n\n");
   
float n,r;
printf("ENTRE COM UM NUMERO REAL (Positivo retorna raiz | Negativo retorna potencia): ");
scanf("%f",&n);
 if(n>=0){
  r=sqrt(n);
  printf("\nA raiz de %.f eh %.f\n",n,r);
}
 else{
 r=n*n; 
  printf("\nA potencia de %.f eh %.f\n",n,r);
}
	return 0;
}
