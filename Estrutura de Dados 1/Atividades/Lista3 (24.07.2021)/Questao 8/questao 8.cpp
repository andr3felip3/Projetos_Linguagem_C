/*
UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 24/07/2021
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 

- LISTA 3

QUESTAO 8) Escreva um programa que leia a idade e o primeiro nome de até 10 pessoas. Seu programa deve terminar quando 
uma idade negativa for digitada. Ao terminar, seu programa deve escrever o nome e a idade da pessoa mais jovem e 
da mais velha. 

*/

#include <stdio.h>
struct Pessoa {
	char n[10];
	int id;
};
int main() {
	printf("\tLISTA 3  - Questao 8 \n\n");
	printf("\n*** Adicione as informacoes (\"IDADE NEGATIVA FINALIZA PROGRAMA\") ***\n");
	printf("\n");
    struct Pessoa p[10];
    int menor = +999, maior = -999;
   	for(int i=0 ; i < 10; i++) {
		printf("\nEntre com um nome: ");
    	scanf("%s", &p[i].n);
    	printf("Entre com a idade: ");
        scanf("%d", &p[i].id);
        
		if(p[i].id < 0)
		 break;
    	if(p[i].id > maior)
		 maior = p[i].id;
        
		if(p[i].id < menor)
		 menor = p[i].id;
    }
	printf("\n Pessoa mais nova: \n");
    for(int i=0 ; i < 10; i++) {
		if(p[i].id < 0) 
		  break;
        if(p[i].id == menor)
          printf("Nome: %s    Idade: %d anos\n", p[i].n, p[i].id);
    }
	printf("\n Pessoa mais velha: \n");
    for(int i=0 ; i < 10; i++) {
		if(p[i].id < 0) break;
        if(p[i].id == maior)
        printf("Nome: %s    Idade: %d anos\n", p[i].n, p[i].id);
    }
	return 0;
}
