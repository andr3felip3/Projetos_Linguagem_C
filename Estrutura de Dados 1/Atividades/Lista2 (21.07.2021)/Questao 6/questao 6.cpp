/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: Andr� felipe costa da silva
DATA: 21/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 2

QUESTAO 6) Fa�a um programa para o �jogo de adivinhar um n�mero�. O computador deve sortear um n�mero entre 0 
e 100 e pedir para o usu�rio tentar adivinhar este n�mero. O usu�rio vai dizer o seu palpite, e o computador 
deve responder, se ele � maior ou menor que o n�mero que ele sorteou. O programa termina somente quando 
o usu�rio acertar exatamente qual o n�mero que o computador tinha sorteado, escrevendo uma mensagem 
de felicita��es para o nosso usu�rio e indicando o n�mero total de tentativas feitas.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
printf("\tLISTA 2  - Questao 6 \n\n");
int num,num_st;
srand(time(NULL));
num_st=rand () % 100;
printf("\t( %d )\n",num_st);
 printf("\nAdvinhe o numero sorteado: ");
 scanf("%d",&num);
 while(num!=num_st){
 	if(num>num_st){
	 
 	printf("\nERROU, o numero sorteado eh menor que %d",num);
 	printf("\nAdvinhe o numero sorteado: ");
    scanf("%d",&num);
 	}
	 else{
	    printf("\nERROU, o numero sorteado eh maior que %d",num);
 		printf("\nAdvinhe o numero sorteado: ");
        scanf("%d",&num);
	 } 
 }  
  if(num_st==num)
    printf("\nACERTOU, o numero sorteado eh o %d",num);
    
	return 0;
}
