/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 16/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 1

QUESTAO 4)Escreva um programa que leia dois números inteiros e retorne o resultado da divisão destes dois números. 
Apresente o resultado considerando uma variável resultante inteira, e uma float. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 1  - Questao 4 \n\n");
int a,b;
int r1;
float r2;
printf("Entre com o primeiro numero inteiro: ");
scanf("%d",&a);
printf("Entre com o segundo numero inteiro: ");
scanf("%d",&b);
r1=a/b;
r2=(float)a/b;
printf("\nNa resultante inteira %d / %d = %d",a,b,r1);
printf("\nNa resultante float %d / %d = %.2f\n",a,b,r2);


	return 0;
}
