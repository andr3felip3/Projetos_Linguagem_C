/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 21/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 2

QUESTAO 2) Fazer a leitura de três valores dos coeficientes A, B e C, e depois efetuar o cálculo das raízes de uma equação 
de segundo grau. 

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
printf("\tLISTA 2  - Questao 2 \n\n");
   float A,B,C;
   float x1,x2;
   float d;
   printf("Entre com o valor do coeficiente A: ");
   scanf("%f",&A);
   printf("Entre com o valor do coeficiente B: ");
   scanf("%f",&B);
   printf("Entre com o valor do coeficiente C: ");
   scanf("%f",&C);
   d=((B*B)-4*A*C);
  
   if(d<0){
   	printf("\nO valor de Delta eh %.1f | (D<0) - nao ha raizes reais ",d);
    printf("\nLogo nao ha raizes \n"); 
   	
   }
    else if(d>0){
   	   x1=(-B+sqrt(d))/(2*A);
       x2=(-B-sqrt(d))/(2*A);
       printf("\nO valor de Delta eh %.1f | (D>0) - raizes diferentes",d);
       printf("\nLogo valor da raiz 1 eh %.2f e da raiz 2 eh %.2f\n",x1,x2);
	} 
	  else{
	x1=(-B+sqrt(d))/(2*A);
    printf("\nO valor de delta eh %.1f | (D=0) - raizes iguais",d);
    printf("\nLogo valor das duas raizes eh %.2f\n",x1);   	
	   }
	  
	return 0;
}
