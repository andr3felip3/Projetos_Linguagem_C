/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: Andr� felipe costa da silva
DATA: 16/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 1

QUESTAO 1) Escreva um programa que calcule a soma, a subtra��o, a multiplica��o e a divis�o de dois n�meros 
fornecidos pelo usu�rio. 
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    float a,b;
	printf("\tLISTA 1 - Questao 01\n\n");
    printf("Entre com o primeiro numero: ");
    scanf("%f",&a);
    printf("\nEntre com o segundo numero: ");
	scanf("%f",&b);
	printf("\nA soma de %.f + %.f = %.f\n",a,b,a+b);
	printf("A subtracao de %.f - %.f = %.f\n",a,b,a-b);
	printf("A multiplicao de %.f x %.f = %.f\n",a,b,a*b);
	printf("A divisao de %.f / %.f = %.2f\n",a,b,a/b);
	return 0;
}
