/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 29/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 6

QUESTAO 4) Faça uma função que recebe, por parâmetro, 2 vetores de 5 elementos inteiros e
que calcule e retorne, também por parâmetro, o vetor união dos dois primeiros.
*/

#include<stdio.h>
#include<stdlib.h>
struct Vetuniao{
	int uni[10];
};
Vetuniao uniao(int v[],int w[]){
	Vetuniao u;
 for(int i=0;i<=4;i++){
 	u.uni[i]=v[i];
 }
 int i=0;
 for(int j=5;j<10;j++,i++)
 u.uni[j]=w[i];
 
  return u;  
}
int main() {
printf("\tLISTA 6  - Questao 4 \n\n");
   int v[5],w[5];
   int i;
   struct Vetuniao u;
   for(i=0;i<5;i++){
   	printf("Adicione valores para o primeiro vetor[%d]: ",i);
   	scanf("%d",&v[i]);
   }
   printf("\n");
    for(i=0;i<5;i++){
    printf("Adicione valores para o segundo vetor[%d]: ",i);
   	scanf("%d",&w[i]);
	}
	u=uniao(v,w);
	printf("\n");
	printf("\tExibe Uniao\n\n");
	for(i=0;i<10;i++)
	  printf("[%d]",u.uni[i]);
	  printf("\n");
	return 0;
}
