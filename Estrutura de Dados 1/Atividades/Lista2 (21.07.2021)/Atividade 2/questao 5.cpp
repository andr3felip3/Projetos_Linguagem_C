/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 21/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 2

QUESTAO 5) Faça um algoritmo que calcule o IMC de uma pessoa e mostre sua classificação de acordo com a tabela 
abaixo: 
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 2  - Questao 5 \n\n");
   float imc,p,h;
   printf("Entre com o peso: ");
   scanf("%f",&p);
   printf("Entre com a altura: ");
   scanf("%f",&h);
   
   imc=p/(h*h);
   printf("\nIMC: %f",imc);
   
    if(imc<18.50)
    printf("\nAbaixo do peso");   
    else if((imc>=18.60)||(imc<=24.90))
    printf("\nSaudavel");
    else if((imc>=25.50)||(imc<=29.90))
    printf("\nPeso em excesso");
    else if((imc>=30.00)||(imc<=34.90))
    printf("\nObesidade grau 1");
	else if((imc>=35.00)||(imc<=39.90))
    printf("\nObesidade grau 2(severa)");
    else printf("\nObesidade grau 3(morbida)");

	return 0;
}
