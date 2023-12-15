/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 11/08/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 7

QUESTAO 2) Faça um programa que faz uma ficha de dados de 7 pessoas. 
A estrutura deve conter os seguintes campos: RG, Nome da Pessoa, Rua, número da casa.

*/

#include<stdio.h>
#include<stdlib.h>

struct pessoa{
	int rg;
	char nome[10];
	char rua[10];
	int nmrcasa;
};
int main() {
printf("\tLISTA 7  - Questao 2 \n\n");
struct pessoa p[7];   
int i;
for(i=0;i<7;i++){
	printf("Entre com o nome da pessoa: ");
	scanf("%s",&p[i].nome);
	printf("Entre com o rg da pessoa: ");
	scanf("%d",&p[i].rg);
	printf("Entre com a rua da casa: ");
	scanf("%s",&p[i].rua);
	printf("Entre com o numero da casa: ");
	scanf("%d",&p[i].nmrcasa);
	printf("\n");
}
  printf("\tPessoas Cadastradas\n");   
   for(i=0;i<7;i++){
   	printf("\nNome: %s | Rg: %d | Rua: %s | Numero da casa: %d ",p[i].nome,p[i].rg,p[i].rua,p[i].nmrcasa);
   	
   }
printf("\n");
	return 0;
}
