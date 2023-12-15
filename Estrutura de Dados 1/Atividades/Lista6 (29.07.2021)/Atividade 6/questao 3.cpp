/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 29/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 6

QUESTAO 3) Faça uma função que receba uma matriz de 3 x 3 elementos. Calcule a soma dos elementos que estão acima da diagonal principal.
*/

#include<stdio.h>
#include<stdlib.h>

int soma(int m[][3]){
	int i,j,s=0;
for(i=0;i<3;i++){
  for(j=0;j<3;j++){
    s=m[0][1]+m[0][2]+m[1][2];
	 
  }
}
   return s;
}
int main() {
printf("\tLISTA 6  - Questao 3 \n\n");
   int m[3][3];
   int i,j;
   for(i=0;i<3;i++){
   	for(j=0;j<3;j++){
   		printf("Adicione numeros inteiros: ");
   		scanf("%d",&m[i][j]);
	   }
       
	}
	   int s=soma(m);
	   printf("\nA soma dos elementos acima da diagonal principal eh %d\n",s);
 
	return 0;
}
