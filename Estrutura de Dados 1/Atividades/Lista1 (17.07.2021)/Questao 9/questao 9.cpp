/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 16/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 1

QUESTAO 9) A quantia de R$ 780.000,00 será dividida entre três ganhadores de um concurso. Sendo que da quantia total: 
- O primeiro ganhador receberá 46%;
- O segundo receberá 32%;
- O terceiro receberá o restante;
Faça um programa que calcule e imprima a quantia recebida por cada um dos ganhadores. 
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 1  - Questao 9 \n\n");
float q,a,b,c;
printf("Defina a quantia a ser dividida entre os 3 ganhadores: ");
scanf("%f",&q);
a=q*0.46;
b=q*0.32;
c=q-(a+b);
printf("\n  Para a quantia de %.3f\n",q);
printf("\nO Primeiro ganhador tera: %.3f\nO Segundo ganhador tera: %.3f\nO Terceiro tera: %.3f\n",a,b,c);   
	return 0;
}
