/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: Andr� felipe costa da silva
DATA: 28/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 5

QUESTAO 1) Escreva um programa que contenha duas vari�veis inteiras. Compare seus endere�os e exiba o 
maior endere�o. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 5  - Questao 1 \n\n");
   int a,b;
   int *p,*q;
   p=&a;
   q=&b;
   printf("\nO endereco de A eh %x",p);
   printf("\nO endereco de B eh %x",q);
   if(p>q)
   printf("\n\nO maior endereco eh de A: %x",p);
   else printf("\n\nO maior endereco eh de B: %x",q);
   
	return 0;
}
