/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 24/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 3

QUESTAO 4) Faça um programa que leia uma matriz 3x6 com valores reais. 
(a) Imprima a soma de todos os elementos das colunas ímpares; 
(b) Imprima a média aritmética dos elementos da segunda e quarta colunas; 
(c) Substitua os valores da sexta coluna pela soma dos valores das colunas 1 e 2; 
(d) Imprima a matriz modificada. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 3  - Questao 4 \n\n");
   float m[3][6];
   int i,j;
   float m1,m2,s1,s2,s3;
   
   printf("\n*** Entrada da Matriz ***\n\n");
   for(i=0;i<3;i++){
   	 for(j=0;j<6;j++){
     printf("Matriz(%d,%d): ",i,j);
	 scanf("%f",&m[i][j]); 
  }
} 
   for(i=0;i<3;i++){
   	 for(j=0;j<6;j++){
   	    s1+=m[i][0];
   	    s2+=m[i][2];
   	    s3+=m[i][4];
   	    m1+=m[i][1];
   	    m2+=m[i][3];
        m[i][5]=m[i][0]+m[i][1];	    	  	
	   }
   }
      printf("\n\nSoma da coluna 1: %.f | Soma da coluna 3: %.f| Soma da coluna 5: %.f",s1,s2,s3);
      printf("\n\nA media aritmetica da coluna 2: %.f |A media aritmetica da coluna 4: %.f",m1,m2);
    printf("\n\nColuna Modificada:\n\n");
	   for(i=0;i<3;i++){
   	    for(j=0;j<6;j++){
        printf("%.f\t",m[i][j]);
        
} printf("\n\n");
}
	return 0;
}
