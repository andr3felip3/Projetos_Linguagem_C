/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 24/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 3

QUESTAO 9) Fazer um programa de “criptografia” (codificação de dados visando a privacidade de acesso as informações), onde 
dada uma string este programa codifique os dados através de um processo de substituição de letras. Você pode definir 
o seu próprio método de criptografia, desde que depois seja possível reverter este processo, ou seja, um código 
criptografado deve poder ser convertido novamente ao valor inicial). Fazer um outro programa complementar a este 
que deve ser capaz de descriptografar a string, ou seja, deve pegar uma string codificada e retornar ao texto original. 
Dica: use uma matriz que seja inversível. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
printf("\tLISTA 3  - Questao 9 \n\n");
   char p[10],c[10];
   int i=0;
   int opcao=0;
   while(opcao!=3){
   	printf("\n\t  MENU DE OPCOES:\n");
   	printf("\n1-Insercao da palavra");
   	printf("\n2-Criptografia & Descriptografia da palavra");
	printf("\n3-sair");
	printf("\n\nQual sua opcao: ");
	scanf("%d",&opcao);
	getchar();
	switch(opcao){
		case 1:
		       printf("\n\tENTRADA DA PALAVRA\n");
			   printf("\nEntre com a palavra a ser criptografada: ");
		       gets(p);
               printf("\nPALAVRA \"%s\" INSERIDA !\n\n",p);
	           break;
		case 2:
		        printf("\n\tCRIPTOGRAFIA\n");
		        printf("\nA palavra criptografada: ");
		        for(i=0;p[i]!='\0';i++)
				printf("%c",1+p[i]);
		        getchar();
		        printf("\nA palavra descriptografada: ");
		        for(i=0;p[i]!='\0';i++)
				printf("%c",(1+p[i])-1);
				printf("\n\n");
				getchar();
				break;
		
               }
         }	
	
     return 0;
}
/*
#include <stdio.h>
#include <string.h>
#include <conio.h>

// Criptografia
int main(){

	char str[100];
	int N, i;
	
	printf("Criptografia\n\n");
	printf("Digite uma frase: ");
	fflush(stdin);
	gets(str);
	N = strlen(str);
	
	//função linear f(x) = x+1 // descriptografar f(x) = x-1
	
	for(i=0; i<N; i++)
		str[i] = str[i] + 1;
	printf("Mensagem criptografada: %s\n", str);
	
	//descriptografar
	for(i=0; i<N; i++)
		str[i] = str[i] - 1;
	
	printf("Mensagem descriptografada: %s\n", str);	
	
	getch();
	return 0;
}
*/
