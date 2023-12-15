/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 24/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 3

QUESTAO 2) Faça um programa que receba do usuário dois vetores, A e B, com 10 números inteiros cada. Crie um novo vetor 
denominado C calculando C=A-B. Mostre na tela os dados do vetor C. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 3  - Questao 2 \n\n");
   int a[10],b[10],c[10];
   int i,j;
   for(i=0;i<10;i++){
   	printf("\n\nEntre com os dados no vetor A [%d]: ",i);
   	scanf("%d",&a[i]);
   	printf("\n\nEntre com os dados no vetor B [%d]: ",i);
   	scanf("%d",&b[i]);
   	 c[i]=a[i]-b[i];		
	  
	   }
	  for(j=0;j<10;j++)
	    printf("\nVetor C[%d]:%d",j,c[j]); 
   
	return 0;
}
