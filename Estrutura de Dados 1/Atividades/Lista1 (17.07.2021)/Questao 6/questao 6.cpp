/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 16/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 1

QUESTAO 6) Faça um programa que leia o valor da hora de trabalho (em reais) e número de horas 
trabalhadas no mês, e exiba na tela o valor a ser pago ao funcionário, adicionando 10% sobre o 
valor calculado. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 1  - Questao 6 \n\n");
   float ht,t_h,ad,tot;
   printf("Entre com o valor da hora de trabalho:");
   scanf("%f",&ht);
   printf("\nEntre com o numero de horas trabalhadas:");
   scanf("%f",&t_h);
   ad=t_h*0.1;
   tot=(
   ht*t_h)+ad;
   printf("\nHoras de trabalho: %.2f\nHoras trabalhadas: %.f\nAdicional: %.2f \nTotal a ser pago: %.2f\n",ht,t_h,ad,tot);
	return 0;
}
