#include<conio.h>
#include<string.h>
#include<stdio.h>
#define TF 100
struct no{
	char nome[10];
	no* prox;
};
struct partab{
	int idade;
	no* cabeca;
};
void criar(struct partab tabela[]){
	int i;
	for (i=0;i<TF;i++){
		tabela[i].idade = i;
		tabela[i].cabeca=NULL;
	}
}
void exibir(struct partab tabela[]){
    int i;
    no* atual;
  
	for (i=0;i<TF;i++){
		if (tabela[i].cabeca==NULL)
		     printf("\n\n |Idade:%d e cabeca nula|\n",tabela[i].idade);
		     else {
		     	printf("\n |Idade %d e cabeca diferente de nulo ou seja, tem nomes a serem exibidos aqui|\n",tabela[i].idade);
		     	atual= tabela[i].cabeca;
		     	while(atual!=NULL){
		     	printf("  (Nome: %s)\n",atual->nome);
		     	atual=atual->prox;
			}	 
		}
	}	
}
int Hash(int idade){
	int ender = idade % TF;
	return ender;
}
void inserir(struct partab tabela[]){
	char nome[10];
	int idade;
    no* novo= new no; 
	printf("\n Entre com nome: ");
	scanf("%s",&novo->nome);
	printf("\n Entre com a idade: ");
	scanf("%d",&idade);
	novo->prox=NULL;
	int ender = Hash(idade);
    if(tabela[ender].cabeca==NULL)
      tabela[ender].cabeca=novo;
    else{
    	novo->prox=tabela[ender].cabeca;
    	tabela[ender].cabeca=novo;
	}
}
void informar(struct partab tabela[], int idade){
    int ender=Hash(idade);
    no* atual=tabela[ender].cabeca;
    if(atual==NULL)
    printf("\n Nao ha pessoas com essa idade\n");
    else{
	 while(atual!=NULL){
        printf("\n Nome: %s  Idade: %d\n",atual->nome,idade);
        atual=atual->prox;
    }
   }
   
 }

main(){
	int opcao=0;
	int idade;
	struct partab tabela[TF];
	criar(tabela);
	while (opcao!=4){
		printf("\t\n LISTA HASHING");
        printf("\n1 - Inserir um amigo (nome e idade)");
		printf("\n2 - Exibir a tabela inteira contendo todos os amigos por idade");
		printf("\n3 - Informar os amigos de uma determinada idade");
		printf("\n4 - Sair");
		printf("\nOpcao?: ");scanf("%d",&opcao);
		switch(opcao){
			case 1: // ler o nome e a idade
			        inserir(tabela);
			        printf("\n amigo inserido na tabela\n\n");
			        break;
			case 2: printf("\n\n TODOS OS AMIGOS CONFORME AS IDADES: \n");
			        exibir(tabela);
			        break;
			case 3: printf("\n\n AMIGOS DESSA IDADE: \n");
			        printf("\nQual idade voce quer?: ");
			        scanf("%d",&idade);
					informar(tabela,idade);
					break;		        
		}		
	}
}











