/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 28/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 5

QUESTAO 7) Crie um programa que declare uma estrutura (registro) para o cadastro de alunos. 
- Deverão ser armazenados, para cada aluno: matrícula, sobrenome (apenas um) e ano do 
nascimento. 
- Ao início do programa, o usuário deverá informar o número de alunos que serão 
armazenados. 
- O programa deverá alocar dinamicamente a quantidade necessária de memória para 
armazenar os registros dos alunos. 
- O programa deverá pedir ao usuário que entre com as informações dos alunos. 
- Ao final, mostrar os dados armazenados e liberar a memória alocada. 

*/

#include<stdio.h>
#include<stdlib.h>

struct aluno{
	int mat;
	char sob[10];
	int ano;
};
int main() {
printf("\tLISTA 5  - Questao 7 \n\n");
 int num,i,j;
 printf("Quantos anlunos serao cadastrados?: ");
 scanf("%d",&num);
 struct aluno *p=(struct aluno*) malloc(num*sizeof(struct aluno));
 for(i=0;i<num;i++){
 	printf("\nEntre com a matricula: ");
 	scanf("%d",&p[i].mat);
 	printf("Entre com o sobrenome: ");
 	scanf("%s",&p[i].sob);
 	printf("Entre com o ano de nascimento: ");
 	scanf("%d",&p[i].ano);
 }
 getchar();
 printf("\n");
   printf("\n\t*** EXIBIR ALUNOS ***");
      printf("\n"); 
   for(j=0;j<num;j++)
      printf("\nMatricula: %d |Sobrenome: %s |Ano de Nascimento: %d\n",p[j].mat,p[j].sob,p[j].ano);
    printf("\nApertar enter para limpar a memoria  ");
    getchar();
    p=(struct aluno*) realloc(NULL,0);
    printf("\n\n\t*** Memoria Liberada ***\n");
    for(j=0;j<num;j++)
      printf("\nMatricula: %d |Sobrenome: %s |Ano de Nascimento: %d\n",p[j].mat,p[j].sob,p[j].ano);
    
 	return 0;
}
