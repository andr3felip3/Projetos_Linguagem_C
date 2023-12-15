#include<stdio.h>
#include<string.h>
#include<conio.h>

struct IndRemedio{
int codigo;
int posender;
};

struct Remedio{
int codRem;
char desc[10];
int dosagem;	
float preco;
};

struct IndClientes{
int codigo;
int posender;	
};

struct Clientes{
int codCliente;
char nomeCliente[10];
int cpf;
int celular;	
};

struct Vendas{
int notaF;
char data[10];
int codCliente;
int codRem;
int quantidade;	
};

int BuscaBinariaIndexada(int codigo, struct indice vetor[], int tl){  	
	int inicio,fim,meio;  	
	int posicao=-1;
	inicio=0;  	
	fim=tl-1;  	
	meio=(inicio+fim)/2;  	
	while ((inicio<fim)&&(vetor[meio].codigo !=codigo)){ 
 	 	if (codigo < vetor[meio].codigo) 
 	 	    fim=meio;  	 	    
			  else inicio = meio+1;  	 	
		 meio=(inicio+fim)/2;     
 		} 
 	if (vetor[meio].codigo ==codigo){
	 	posicao=vetor[meio].posender; 
		return posicao;} 
 	   else return posicao; // nao encontrou 
} 

void CadastraVenda(struct IndRemedio vetR[],struct IndClientes vetC[],int tlR,int tlC){
 Vendas v;
 Clientes c;
 Remedio r;
 int posClie, posRem;
 int notaF;
 char dat[10];
 int codClie, codRem, quant;
 float valor,total;
 FILE *arqR = fopen("REMEDIOS.bin","rb");
 FILE *arqC = fopen("CLIENTES.bin","rb");
 FILE *arqVendas= fopen("VENDAS.bin","ab"); // Adiciona
 if(arqVendas==NULL)
   FILE *arqVendas= fopen("VENDAS.bin","wb"); // Cria
 printf("\nEntre com a nota fiscal: ");
 scanf("%d",&notaF);
 printf("\nEntre com a data: ");
 scanf("%s",&dat);
 printf("\nEntre com o codigo do Cliente: ");
 scanf("%d",&codClie);
 posClie= BuscaBinariaIndexada(codClie,vetC,tlC);
 if(posClie==-1)
 printf("\nNao encontrou");
 else{
 	fseek(arqC,posClie*sizeof(Clientes),SEEK_SET);
 	fread(&c,sizeof(Clientes),1,arqC);
 	printf("\nCliente: %s - CPF: %d - Celular: %d"c.nomeCliente,c.cpf,c.celular);
    fwrite(&v,sizeof(Vendas),1,arqVendas);
 }
 printf("\nEntre com o codigo do Remedio (Zero Finaliza): ");
 scanf("%d",&codRem);
 while(codRem!=0){
 	posRem=BuscaBinariaIndexada(codRem,vetR,tlR);
  if(posRem==-1)
    printf("\nNao encontrou");
  else{
 	fseek(arqR,posRem*sizeof(Remedio),SEEK_SET);
 	fread(&r,sizeof(Remedio),1,arqR);
 	printf("\nDescricao: %s - Dosagem: %d - preco: %.2f",r.desc,r.dosagem,r.preco);
 	printf("\nEntre com a quantidade desejada: ");
 	scanf("%d",&quant);
 	valor=quant*r.preco;
 	printf("\nValor a pagar do remedio %s = %.2f",r.desc,valor);
 	total+=valor;
	fwrite(&v,sizeof(Vendas),1,arqVendas);
 	printf("\nEntre com o codigo do Remedio (Zero Finaliza): ");
    scanf("%d",&codRem);
    }
  }
  printf("\nTotal de todos os remedios a pagar: %.2f",total);
  fclose(arqR);
  fclose(arqC);
  fclose(arqVendas);
}
 main(){
 	struct IndRemedio vetR[10];
 	struct IndClientes vetC[10];
 	int tlR=0,tlC=0;
 	int opcao=0;
 	while(opcao!=2){
 		printf("\n1-Cadastramento de venda");
 		printf("\nQual sua opcao: ");
 		scanf("%d",&opcao);
 		switch(opcao){
 			
 			case 1: CadastraVenda(vetR,vetC,tlR,tlC);
 			    break;
		 }
	 }
 }
