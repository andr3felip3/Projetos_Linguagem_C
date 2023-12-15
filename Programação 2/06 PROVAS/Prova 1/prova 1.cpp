#include <stdio.h>

struct produto{
	char desc [20];
	int qtdest;
	int qtdmin;
	int qtdcomprar;
};
void gravar (struct produto tabprodutos[100],int tl){
int i;	
File *arq= fopen("compras.txt","w+");
for(i=0;i<tl;i++){
	
	if(tabprodutos[i].qtdest<tabprodutos[i].qtdmin)
	tabprodutos[i].qtdcomprar= tabprodutos[i].qtdmin - tabprodutos[i].qtdest;
	
	else vetor[i].qtdcomprar=0;
	
fprintf(arq,"%s %d %d %d",tabprodutos[i].desc,tabprodutos[i].qtdest,tabprodutos[i].qtdmin,tabprodutos[i].qtdcomprar);
}
fclose(arq);
          printf("Arquivo texto criado");

	
}

main(){
//declaração de variaves
// menu de opcões
// chamar função
}
