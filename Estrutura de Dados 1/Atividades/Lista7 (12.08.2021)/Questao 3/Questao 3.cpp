/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 7

QUESTAO 3) Crie uma estrutura representando os alunos de um determinado curso.
A estrtura deve conter a matricula do aluno,nome,nota da primeira prova,nota da
segunda prova e nota da terceira prova.

a) Permita ao usuário entrar com os dados de 5 alunos.
b) Encontre o aluno com maior nota da primeira prova.
c) Encontre o aluno com maior media geral.
d) Encontre o aluno com menor media geral.
e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o
valor 6 para aprovação.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct aluno{
	int matricula;
	char nome[10];
	float n1,n2,n3;
	char situacao[10];
};

int main() {
printf("\tLISTA 7  - Questao 3 \n\n");
 struct aluno a[5];
 int i;  
 float media;
 float maiorN1=-99,maiorMed=-99,menorMed=99;
 char AlumaiorN1[10],AlumaiorMed[10],AlumenorMed[10]; 
  for(i=0;i<5;i++){
  	printf("Entre com a matricula: ");
  	scanf("%d",&a[i].matricula);
  	printf("Entre com o nome: ");
  	scanf("%s",&a[i].nome);
	printf("Entre com a nota 1: ");
	scanf("%f",&a[i].n1);
	printf("Entre com a nota 2: ");
	scanf("%f",&a[i].n2);
	printf("Entre com a nota 3: ");
	scanf("%f",&a[i].n3);
	printf("\n");
}
  printf("\tAlunos\n");
  
   for(i=0;i<5;i++){
   	
   		media=(a[i].n1+a[i].n2+a[i].n3)/3;
	
	if(a[i].n1>maiorN1){
	   maiorN1=a[i].n1;
	   strcpy(AlumaiorN1,a[i].nome);
       
}
	if(media>maiorMed){
	    maiorMed=media;
	    strcpy(AlumaiorMed,a[i].nome);
		}
	    else if(media<menorMed){
	        menorMed=media;
	        strcpy(AlumenorMed,a[i].nome);			
			}
		if(media>=6)
		strcpy(a[i].situacao,"aprovado");
		 else strcpy(a[i].situacao,"reprovado");
		
		printf("Aluno : %s | Matricula: %d | Nota 1: %.1f | Nota 2: %.1f | Nota 3: %.1f |Media: %.1f | situacao: %s ",a[i].nome,a[i].matricula,a[i].n1,a[i].n2,a[i].n3,media,a[i].situacao);
		 printf("\n");
		}
       
    printf("\nAluno com a maior Nota 1: %s %.1f ",AlumaiorN1,maiorN1);
    printf("\nAluno com maior media: %s  %.1f",AlumaiorMed,maiorMed);
    printf("\nAluno com menor media: %s  %.1f",AlumenorMed,menorMed);
   
	return 0;
}
