/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: Andr� felipe costa da silva
DATA: 24/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 3

QUESTAO 5) Escrever um algoritmo e um programa em C que produza na tela um tri�ngulo de Pascal de grau �n� usando uma 
matriz. Abaixo temos um tri�ngulo de Pascal de grau 6 (isto �, com seis linhas): 
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
Os elementos extremos em cada linha s�o iguais a 1. Os outros s�o obtidos somando-se os dois valores que aparecem 
imediatamente acima e � esquerda na linha anterior. Exemplo: O quarto elemento da linha corresponde a soma do 
quarto e do terceiro elemento na linha anterior, isto �, 4 = 1 + 3. (Suponha: uma matriz quadrada de dimens�o n 
qualquer, ou seja, n ser� fornecido pelo usu�rio do programa) 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
   printf("\tLISTA 3  - Questao 5 \n\n");
   int n,i,j;
   int a[n][n];
	
	printf("Defina a ordem da matriz: ");
	scanf("%d",&n);
	printf("\n*** Triangulo de Pascal ***\n\n");
	
	for(i=0;i<n;i++){
      for(j=0;j<=i;j++){
      a[i][j]=0;
	  a[i][i]=1;
	  a[i][0]=1;
	  if(a[i][j]==0)
	   a[i][j]=a[i-1][j-1]+a[i-1][j+1];	
	   printf("%d\t",a[i][j]); 
      }
  printf("\n\n");
   }
return 0;
}
