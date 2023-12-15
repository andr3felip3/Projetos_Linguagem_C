/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 24/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 3

QUESTAO 5) Escrever um algoritmo e um programa em C que produza na tela um triângulo de Pascal de grau “n” usando uma 
matriz. Abaixo temos um triângulo de Pascal de grau 6 (isto é, com seis linhas): 
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
Os elementos extremos em cada linha são iguais a 1. Os outros são obtidos somando-se os dois valores que aparecem 
imediatamente acima e à esquerda na linha anterior. Exemplo: O quarto elemento da linha corresponde a soma do 
quarto e do terceiro elemento na linha anterior, isto é, 4 = 1 + 3. (Suponha: uma matriz quadrada de dimensão n 
qualquer, ou seja, n será fornecido pelo usuário do programa) 

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
/* Outra forma
#include <stdio.h>
#include <conio.h>


int main(){
	int M[50][50];
	int grau;
	int i, j;
	
	printf("Triangulo de Pascal\n\n");
	printf("Digite o grau (maior que zero): ");
	scanf("%d", &grau);
	
	for(i=0; i<grau; i++){
		//extremos são iguais a 1
		M[i][0] = 1;
		M[i][i] = 1;
		// calculando o "miolo"
		for(j=1; j<=i; j++){
			M[i][j] = M[i-1][j] + M[i-1][j-1];
		}
	}
	
	// exibir o triângulo
	for(i=0; i<grau; i++){
		for(j=0; j<=i; j++)
			printf("%d\t", M[i][j]);
		printf("\n");
	}
		
	getch(
	getch();
	return 0;
}
*/
