/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: Andr� felipe costa da silva
DATA: 21/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 2

QUESTAO 8) Fazer um programa em que o usu�rio pode escolher qual fun��o usar: 
1- Inserir n�meros
2- A Soma dos n�meros digitados
3- A quantidade de n�meros digitados
4- A m�dia dos n�meros digitados
5- O maior n�mero digitado
6- O menor n�mero digitado
7- A m�dia dos n�meros pares
8- Finalizar 
Escolhida a fun��o, (fa�a um menu e depois utilize o bloco de comando SWITCH-CASE), o usu�rio deve 
entrar com o(s) n�mero(s) . Esse processo deve ser repetido at� que o usu�rio escolha a op��o Finalizar (utilize 
o bloco de comando DO-WHILE). 

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
printf("\tLISTA 2  - Questao 8 \n");
   int opcao=0,cont=0;
   float num,soma=0,media,maior=-999,menor=+999;
   int numpar,somapar=0,contpar=0;
   float mediapar;
   while(opcao!=8){
   	 printf("\n1-Insere numeros");
   	 printf("\n2-Soma dos numeros digitados");
   	 printf("\n3-A quantidade de numeros digitados");
   	 printf("\n4-A media dos numeros digitados");
   	 printf("\n5-O maior numero digitado");
   	 printf("\n6-O menor numero digitado");
   	 printf("\n7-A media dos numeros pares");
   	 printf("\n8-Finalizar");
   	 printf("\nQual sua opcao: ");
   	 scanf("%d",&opcao);
   	 switch(opcao){
   	 	
   	 	case 1: printf("\n1-Insere numeros\n");
   	 	       printf("\nEntre com um numero:");
   	 	       scanf("%f",&num);
   	 	       printf("\nNumero %.f inserido\n",num);
   	 	       soma+=num;
   	 	       cont++;
   	 	       media=soma/cont;
   	 	       
   	 	       numpar=(int)num%2;
   	 	       if(numpar==0){
   	 	       	somapar+=num;
   	 	       	contpar++;
				   }
				   
				if(maior<num)
				maior=num;
				if(menor>num)
				menor=num;
   	 	       
		     break;
		case 2: printf("\n2-Soma dos numeros digitados\n");
		        printf("\nA soma eh %.2f\n",soma);
			 
			 break;
		case 3: printf("\n3-A quantidade de numeros digitados\n");
			    printf("\nA quantidade de numeros eh %d\n",cont);
			 
			 break;
		case 4: printf("\n4-A media dos n�meros digitados\n");
			    printf("\nA media dos numeros digitados eh %.2f\n",media);
			 
			 break;
	    case 5: printf("\n5-O maior n�mero digitado\n");
	            printf("\nO maior numero digitado eh %.f\n",maior);
			
			 break;
	    case 6: printf("\n6-O menor n�mero digitado\n");
	            printf("\nO menor numero digitado eh %.f\n",menor);
			
			
			 break;
		case 7: printf("\n7-A media dos numeros pares\n");
		   
		     mediapar=somapar/contpar;
		     printf("\nA media dos numeros pares eh %.2f\n",mediapar);
			
			break;  
		
		}
   	 
   }
	return 0;
}
