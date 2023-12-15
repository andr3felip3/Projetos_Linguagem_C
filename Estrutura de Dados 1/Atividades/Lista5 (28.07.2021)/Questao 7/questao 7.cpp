/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: Andr� felipe costa da silva
DATA: 28/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 5

QUESTAO 7) Crie um programa que declare uma estrutura (registro) para o cadastro de alunos. 
- Dever�o ser armazenados, para cada aluno: matr�cula, sobrenome (apenas um) e ano do 
nascimento. 
- Ao in�cio do programa, o usu�rio dever� informar o n�mero de alunos que ser�o 
armazenados. 
- O programa dever� alocar dinamicamente a quantidade necess�ria de mem�ria para 
armazenar os registros dos alunos. 
- O programa dever� pedir ao usu�rio que entre com as informa��es dos alunos. 
- Ao final, mostrar os dados armazenados e liberar a mem�ria alocada. 

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
