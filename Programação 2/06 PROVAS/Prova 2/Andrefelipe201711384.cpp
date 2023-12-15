#include<stdio.h>
#include<string.h>
#define TF 30

struct no{
	char placa[10];
	int dia;
	char mes[10];
	int ano;
	int codigo;
	no* prox;
};

struct partab{
	int registro;
	no* cabeca;
}; 
void criar (struct partab t[]){
	int i;
	for(i=0;i<TF;i++){
	t[i].registro=i;
	t[i].cabeca=NULL;
  }
}
 

 int Hash(char placa[]){
 	int ender=(placa[0]+placa[1]+placa[2])%TF;
 	return ender;
 	
 }
 
 void inserir(struct partab t[]){
 	no* novo=new no;
 	int ender;
 	printf("\n Entre com a PLACA do carro: ");
 	scanf("%s",&novo->placa);
 	printf("\n Entre com o dia da ocorrencia: ");
 	scanf("%d",&novo->dia);
 	printf("\n Entre com o MES da ocorrencia (Letras): ");
 	scanf("%s",&novo->mes);
 	printf("\n Entre com o ANO da ocorrencia: ");
 	scanf("%d",&novo->ano);
 	printf("\n Entre com o CODIGO da ocorrencia: ");
 	scanf("%d",&novo->codigo);
 	novo->prox=NULL;
 	ender= Hash(novo->placa);
 	if (t[ender].cabeca==NULL)
 	  t[ender].cabeca=novo;
 	else{
 		novo->prox=t[ender].cabeca;
 		t[ender].cabeca=novo;
	 }
    
	printf("\n\n Multa inserida com sucesso no Registro: %d\n",ender);	
 
  }

void consulta(struct partab t[],char placa[]){
	no* atual;
	int ender=Hash(placa);
	atual=t[ender].cabeca;
	if(strcmp(atual->placa,placa)==0)
	printf("\n Registro: %d - Placa: %s - Data da ocorrencia: %d / %s / %d - Codigo da infracao: %d \n",t[ender].registro,atual->placa,atual->dia,atual->mes,atual->ano,atual->codigo);
}

main(){
	struct partab t[TF];
	int opcao=0;
	char placa[10];
	criar(t);
	while(opcao!=3){
	printf("\t *Registro de Multas*\n ");
	printf("\n 1- Insere infracao");
	printf("\n 2- Consulta infracao pela placa ");
	printf("\n 3- Exibe tudo");
	printf("\n 4- Sair");
	printf("\n\n Qual sua opcao: ");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:printf("\t\n * INSERCAO DE MULTAS *\n"); 
		       inserir(t);
		         break;
		case 2: printf("\t\n * CONSULTA DE MULTAS *\n");
		        printf("\n Entre com a placa: "); 
		        scanf("%s",&placa);
		consulta(t,placa);
		         break;
	    
	}
  }
}
