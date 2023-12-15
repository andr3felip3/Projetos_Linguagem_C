#include <stdio.h>
#include<string.h>

struct produto{
	char desc [20];
	int qtdest;
	int qtdmin;
	int qtdcomprar;
};
void carrega(struct produto tabprodutos[100],int &tl){
	strcpy(tabprodutos[0].desc,"arroz"); tabprodutos[0].qtdest=100 ;   tabprodutos[0].qtdmin =150 ; 
	strcpy(tabprodutos[1].desc,"leite"); tabprodutos[1].qtdest=190 ;   tabprodutos[1].qtdmin =60  ;
	strcpy(tabprodutos[2].desc,"feijao"); tabprodutos[2].qtdest=45  ;   tabprodutos[2].qtdmin = 50 ;
	strcpy(tabprodutos[3].desc,"macarrao"); tabprodutos[3].qtdest=68  ;   tabprodutos[3].qtdmin =60  ;
	strcpy(tabprodutos[4].desc,"molho"); tabprodutos[4].qtdest= 24 ;   tabprodutos[4].qtdmin = 20 ;
	strcpy(tabprodutos[5].desc,"acucar"); tabprodutos[5].qtdest= 17  ;   tabprodutos[5].qtdmin = 70 ;
    strcpy(tabprodutos[6].desc,"bolacha"); tabprodutos[6].qtdest= 135 ;   tabprodutos[6].qtdmin = 45 ;
    strcpy(tabprodutos[7].desc,"agua"); tabprodutos[7].qtdest= 100 ;   tabprodutos[7].qtdmin = 40 ;
    tl=8;
}

void exibe(struct produto tabprodutos[100],int tl){
	int i;
	for(i=0;i<tl;i++)
		printf("\n descricao: %s  estoque: %d  minimo:%d",tabprodutos[i].desc, tabprodutos[i].qtdest,tabprodutos[i].qtdmin);
	
}

void gravar (struct produto tabprodutos[100],int tl){
int i;	
FILE *arq = fopen("compras.txt","w+");
for(i=0;i<tl;i++){
	
	if(tabprodutos[i].qtdest<tabprodutos[i].qtdmin)
	tabprodutos[i].qtdcomprar= tabprodutos[i].qtdmin - tabprodutos[i].qtdest;
	
	else tabprodutos[i].qtdcomprar=0;
	
fprintf(arq,"%s %d %d %d\n",tabprodutos[i].desc,tabprodutos[i].qtdest,tabprodutos[i].qtdmin,tabprodutos[i].qtdcomprar);
}
fclose(arq);
          printf("Arquivo texto criado");
	
}

main(){
int tl=0;
int opcao=0;
struct produto tabprodutos[10];
while(opcao!=7){
	printf("\n 1-carrega tabela");
    printf("\n 2-exibe tabela");
    printf("\n 3-grava tabela");
    scanf("%d",&opcao);
    switch(opcao){
    	case 1: carrega(tabprodutos,tl);
    	         break;
        case 2 : exibe(tabprodutos,tl);
                 break;
        case 3 : gravar(tabprodutos,tl);
                  break;
	}
	
}
}


