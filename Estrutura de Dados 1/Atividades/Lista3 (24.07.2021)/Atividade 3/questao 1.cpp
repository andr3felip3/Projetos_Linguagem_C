/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: Andr� felipe costa da silva
DATA: 24/072021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 3

QUESTAO 1) Leia 10 n�meros inteiros e armazene em um vetor. Em seguida escreva os elementos que s�o primos e suas 
respectivas posi��es no vetor. 
*/

#include <stdio.h>
#include<math.h>

int main(){
	printf("\tLISTA 3  - Questao 1 \n\n");
    int v[10] ;
    int d,i,limite;
    int primo=1; 
    
    for(i=0; i<10 ;i++) {
    	
    	printf("\nEntre com os numeros inteiros: ");
    	scanf("%d",&v[i]);
        if (v[i] > 1) { 
            d = 2;
            primo = 1;
            limite = sqrt(v[i]); 
            while(primo && d <= limite) 
             {
               
                if (v[i] % d  == 0){ 
                    
                    primo = 0;
                }
                
                d++;
             } 
            
            if (primo) // � o mesmo que verifica == 1
                printf("\nVetor[%d]:%d eh primo.\n",i, v[i]);
                else printf("\nVetor[%d]:%d nao eh primo.\n", v[i],i);
        }
    }
    return 0;   
}
