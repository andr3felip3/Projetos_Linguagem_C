#include <stdio.h>
#include <string.h>
struct produto{
	char descricao[20];
	int qtdest;
	int qtdmin;
};
struct produto2{
	char descricao[20];
	int qtdest;
	int qtdmin;
	int qtdcomprar;
};
void carrega (struct produto tabprodutos[100], int &tl){
	strcpy(tabprodutos[0].descricao,"arroz");
	tabprodutos[0].qtdest=100;
	tabprodutos[0].qtdmin=150;
	strcpy(tabprodutos[1].descricao,"leite");
	tabprodutos[1].qtdest=190;
	tabprodutos[1].qtdmin=60;
	strcpy(tabprodutos[2].descricao,"feijao");
	tabprodutos[2].qtdest=45;
	tabprodutos[2].qtdmin=50;
	strcpy(tabprodutos[3].descricao,"macarrao");
	tabprodutos[3].qtdest=68;
	tabprodutos[3].qtdmin=60;
	strcpy(tabprodutos[4].descricao,"molho");
	tabprodutos[4].qtdest=24;
	tabprodutos[4].qtdmin=20;
	strcpy(tabprodutos[5].descricao,"acucar");
	tabprodutos[5].qtdest=17;
	tabprodutos[5].qtdmin=70;
	strcpy(tabprodutos[6].descricao,"bolacha");
	tabprodutos[6].qtdest=135;
	tabprodutos[6].qtdmin=45;
	strcpy(tabprodutos[7].descricao,"agua");
	tabprodutos[7].qtdest=100;
	tabprodutos[7].qtdmin=40;
	tl=8;
}
void exibe(struct produto tabprodutos[100], int tl){
	int i=0;
	int acomprar=0;
	for (i=0;i<tl;i++){
		if (tabprodutos[i].qtdest < tabprodutos[i].qtdmin)
		    acomprar = tabprodutos[i].qtdmin - tabprodutos[i].qtdest;
		    else acomprar=0;
	    printf("\nDescricao %s   Estoque%d   Minimo%d  A comprar%d",tabprodutos[i].descricao,tabprodutos[i].qtdest,
	                            tabprodutos[i].qtdmin,acomprar);
    }
}
void gravar(struct produto tabprodutos[100], int tl){
	FILE *arq = fopen("compras.txt","w");
	int i, acomprar;
	for (i=0;i<tl;i++){
       if (tabprodutos[i].qtdest < tabprodutos[i].qtdmin) 
	      acomprar = tabprodutos[i].qtdmin-tabprodutos[i].qtdest;
	      else
	      acomprar=0;
	   fprintf(arq,"%s %d %d %d\n",tabprodutos[i].descricao,tabprodutos[i].qtdest,tabprodutos[i].qtdmin,acomprar);
    }
	fclose(arq); 
	printf("\n Gravado o arquivo texto COMPRAS.TXT");  
}
main(){
	int tl=0;
	struct produto tabprodutos[10]; 
    int opcao=0;
	while (opcao!=4){
		printf("\n1 - Carrega a tabela TABPRODUTOS");
		printf("\n2 - Exibe a tabela");
		printf("\n3 - Grava o novo arquivo Produtos.txt");
		printf("\n4 - sair");
		printf("\nopcao?");
		scanf("%d",&opcao);
		switch(opcao){
		   case 1: carrega(tabprodutos,tl);
		           printf("\n tabela de produtos carregada igual da prova");
				   break;
		   case 2: exibe(tabprodutos,tl);
		           break;
		   case 3: gravar(tabprodutos,tl);
		           printf("\n arquivo texto gravado com sucesso");
				   break;	   		   	
		}//switch
	}//while
}