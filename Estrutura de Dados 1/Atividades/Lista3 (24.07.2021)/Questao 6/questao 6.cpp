/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: Andr� felipe costa da silva
DATA: 24/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 3

QUESTAO 6) Fa�a um programa que receba uma palavra e a imprima de tr�s-para-frente. 

*/

#include <stdio.h>
#include <string.h>
int main() {
	printf("\tLISTA 3  - Questao 6 \n\n");
	char p[10];
	int i, j; 
	printf("\nEntre com uma palavra: "); 
	gets(p);
	j = strlen(p); 
	printf("\nA palavra invertida eh:"); 
  	for(i = j; i >= 0; i--) {
	printf("%c", p[i]);
    } 
    printf("\n");
	return 0;
}
