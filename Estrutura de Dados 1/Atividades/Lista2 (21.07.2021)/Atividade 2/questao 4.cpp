/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 21/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 2

QUESTAO 4) Faça um programa que leia 2 notas de um aluno, e os respectivos pesos de cada uma destas 2 notas. Calcule 
a média ponderada destas notas, usando os pesos, e depois mostre na tela o resultado (exibir a média com 
apenas 2 casas após a vírgula). Se o aluno teve uma nota superior a 6.0, indique que ele foi “Aprovado”, se 
o aluno teve uma nota entre 3.0 e 6.0 indique que ele está em “Recuperação”, e se o aluno teve uma nota 
entre 0.0 e 3.0 indique que ele está “Reprovado”. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 2  - Questao 4 \n\n");
   float n1,n2,p1,p2,med;
   printf("Entre com a nota 1: ");
   scanf("%f",&n1);
   printf("Entre com nota 2: ");
   scanf("%f",&n2);
   printf("Entre com o peso 1: ");
   scanf("%f",&p1);
   printf("Entre com o peso 2: ");
   scanf("%f",&p2);
   
   med=((p1*n1)+(p2*n2))/(p1+p2);
   
   if(med>6.0)
   printf("\nMedia %.2f - Aluno aprovado",med);
   else if((med>=3.0)&&(med<=6.0))
     printf("\nMedia %.2f - Aluno de Recuperacao",med);
    else
	 printf("\nMedia %.2f - Aluno Reprovado",med);
	
	return 0;
}
