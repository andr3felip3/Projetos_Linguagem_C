/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 16/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 1

QUESTAO 3) Escreva um programa que retorne o resto e o quociente da divisão por dois números inteiros. 
 
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
printf("\tLISTA 1 - Questao 03\n\n");
int a,b;
float q, r;
printf("Entre com o primeiro numero inteiro: ");
scanf("%d",&a);
printf("Entre com o segundo numero inteiro: ");
scanf("%d",&b);
q=(float)a/b;
r=a%b;
printf("\nO quociente de %d por %d eh %.2f e o resto eh %.f\n",a,b,q,r);
return 0;
}
