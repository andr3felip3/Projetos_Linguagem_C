/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 21/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 2

QUESTAO 10) Fazer um programa que calcule e exiba na tela o fatorial de um número fornecido pelo usuário, usando 
o comando FOR. Perguntar ao usuário se ele deseja calcular o fatorial de outro número e repetir a execução 
do programa tantas vezes quantas o usuário indicar (utilize o bloco de comando WHILE). 
de saída: 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 2  - Questao 10 \n\n");
  int n,i;
  int f=1;
  int opcao;
  printf("deseja calcular o fatorial(1-Sim/2-Nao): ");
  scanf("%d",&opcao);
   while(opcao!=2){
   printf("\nEntre com um numero: ");
   scanf("%d",&n);
   for(i=n;i>=1;i--)
      f*=i;
   	
   	printf("\nO fatorial de %d eh %d\n",n,f);
   	f=1;
   	printf("\nDeseja continuar(1-Sim/2-Nao): ");
   	scanf("%d",&opcao);
   }
   
	return 0;
}
