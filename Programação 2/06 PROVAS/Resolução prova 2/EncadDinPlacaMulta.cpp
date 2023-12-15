#include <stdio.h>
#include <conio.h>
#include <string.h>
#define TF 30
struct no{
   char placa[9];
   int  dia,mes,ano;
   int  infracao;
   no*  prox;
};
struct partab{
	char chave[9]; // 3 letras e 4 numeros
	no* cabeca;
};
void criar(struct partab p[TF]){
	int i;	 
    for (i=0; i<TF; i++){
    	strcpy(p[i].chave," ");
        p[i].cabeca=NULL;
    }
    printf("\n tabela Hash (encadeam. dinamico) criada");
}
int Hash(char placa[9]){ // placa="ABC1234"   (asc('A') + asc('B')) % TF
    int ender, soma=0;
    soma = placa[0]+ placa[1];
	ender = soma % TF;
	return ender;
}
void inserir(struct partab tab[TF]){
	no* novo = new no;
	printf("\nEntre com a placa do veiculo(AAA9999):");scanf("%s",novo->placa);
	printf("\nEntre com o dia:");scanf("%d",&novo->dia);
	printf("\nEntre com o mes:");scanf("%d",&novo->mes);
	printf("\nEntre com o ano:");scanf("%d",&novo->ano);
	printf("\nEntre com o codigo da infracao:");scanf("%d",&novo->infracao);
	novo->prox=NULL;
	int ender = Hash(novo->placa);
	if (tab[ender].cabeca==NULL){
		tab[ender].cabeca=novo;
		printf("\nInseriu na linha%d cabeca a placa %s\n",ender, novo->placa);
	}else{
		novo->prox=tab[ender].cabeca;
		tab[ender].cabeca=novo;
		printf("\nJa tinha um no entao inseriu novo na cabeca. linha%d  placa%s\n",ender,novo->placa);
	}
}
void consultar(struct partab tab[TF]){
	char placa[9];
	printf("\nEntre com a placa do veiculo(AAA9999):");scanf("%s",placa);
	int ender = Hash(placa);
	if (tab[ender].cabeca==NULL)
	     printf("\n nao achou");
	     else {
	     	no* atual = tab[ender].cabeca;
	     	while (atual!=NULL){
	     		if (strcmp(placa,atual->placa)==0)
	     		       printf("\n ACHOU placa%s  dia%d infracao%d",atual->placa,atual->dia,atual->infracao);
	     		atual=atual->prox;
			 }
		 }
}
void exibir(struct partab tab[TF]){
	int i;
	for (i=0;i<TF;i++)  {
	    printf ("\n linha=%d chave%s  cabeca?",i,tab[i].chave);
	    if (tab[i].cabeca!=NULL){
	    	no* atual=tab[i].cabeca;
	    	while (atual != NULL){
	    		printf("\n     Placa%s dia%d  infracao%d",atual->placa,atual->dia,atual->infracao);
	    		atual=atual->prox;
			}
		}
   }
   	printf("\n") ;  
}
main(){
	int opcao=0;
	struct partab tab[TF];
	criar(tab);
	while (opcao!=4){
		printf("\n1- Inserir infracao veicular - placa, data e codigo infracao");
		printf("\n2- Consultar uma infracao pela placa do carro");
		printf("\n3- Exibir tudo");
		printf("\n4- sair");
		printf("\nopcao?");
		scanf("%d",&opcao);
		switch (opcao){
		   case 1: inserir(tab);
		           break;
           case 2: consultar(tab);
                   break;
		   case 3: exibir(tab);
		           break;
    	}
    }  
}






