#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
struct conta{
	int num_conta;
	char tipo_conta; // C=comum ou E=especial
	char nome[30];
	float limite;
	float saldo;
};
void novasContas(){
	conta cliente;
	printf("\nLeitura do teclado NOVAS CONTAS SEM apagar as anteriores do arquivo binario");
	FILE *arqnovo = fopen("contas.dat","ab");
	char opcao='S';
	while (opcao=='S'){
		// ler do teclado o cliente
		   printf("\nEntre com numero da conta:");scanf("%d",&cliente.num_conta);
		   printf("\nEntre com tipo da conta:(E/C)");cliente.tipo_conta=getche();
		   printf("\nEntre com o nome do cliente:");scanf("%s",&cliente.nome);
		   cliente.limite=0;
		   if (cliente.tipo_conta=='E' ||cliente.tipo_conta=='e'){
		      printf("\nEntre com o limite da conta:");scanf("%f",&cliente.limite);
	    	}
		   printf("\nEntre com o saldo da conta:");scanf("%f",&cliente.saldo);
		// tem que salvar o cliente no arquivo binario
		fwrite(&cliente,sizeof(conta),1,arqnovo);
		printf("\nVoce deseja incluir uma nova conta no arquivo? (s/n)");
		opcao=getche();
		if (opcao=='s') opcao = 'S';
	}
	fclose(arqnovo);
}
void leTecladoGravaArquivo(){
	conta cliente;
	printf("\nLeitura do teclado e salva no arquivo binário");
	FILE *arqnovo = fopen("contas.dat","wb");
	char opcao='S';
	while (opcao=='S'){
		// ler do teclado o cliente
		   printf("\nEntre com numero da conta:");scanf("%d",&cliente.num_conta);
		   printf("\nEntre com tipo da conta:(E/C)");cliente.tipo_conta=getche();
		   printf("\nEntre com o nome do cliente:");scanf("%s",&cliente.nome);
		   cliente.limite=0;
		   if (cliente.tipo_conta=='E' ||cliente.tipo_conta=='e'){
		      printf("\nEntre com o limite da conta:");scanf("%f",&cliente.limite);
	    	}
		   printf("\nEntre com o saldo da conta:");scanf("%f",&cliente.saldo);
		// tem que salvar o cliente no arquivo binario
		fwrite(&cliente,sizeof(conta),1,arqnovo);
		printf("\nVoce deseja incluir uma nova conta no arquivo? (s/n)");
		opcao=getche();
		if (opcao=='s') opcao = 'S';
	}
	fclose(arqnovo);
}
void relatorio(){
	conta cliente;
	printf("\nEXIBE TODAS CONTAS DO ARQUIVO BINARIO CONTAS.DAT");
	FILE *arquivo = fopen("contas.dat","rb");
	fread(&cliente,sizeof(conta),1,arquivo);
	while(!feof(arquivo)){
		printf("\nNumero:%d  Tipo%c  Nome%s  Limite%5.2f  Saldo%5.2f",cliente.num_conta,cliente.tipo_conta,
		                 cliente.nome,cliente.limite,cliente.saldo);
		fread(&cliente,sizeof(conta),1,arquivo);                 
	}
	fclose(arquivo);
	printf("\n\n");
}
int consulta(int num){
    conta cliente;
	int posicao = -1;
	FILE *arq = fopen("contas.dat","rb"); // vou ler o arquivo. ele tem que existir
	if (arq==NULL)
	   printf("\nNAO localizou o arquivo");
	   else {// arquivo contas.dat foi localizado
	      fseek(arq,0,SEEK_SET); // posiciona o cursor no inicio do arquivo
	   	  fread(&cliente,sizeof(conta),1,arq);
	   	  posicao=0;
	   	  while (!feof(arq)&& (num!=cliente.num_conta)){
	   	  	    posicao++;
	   	  	    fread(&cliente,sizeof(conta),1,arq);
			 }
		  if (num==cliente.num_conta)	{
		  	fseek(arq,posicao*sizeof(conta),SEEK_SET);
		  	fread(&cliente,sizeof(conta),1,arq);
		  	printf("\n Conta:%d tipo:%c  nome:%s saldo:%5.2f",cliente.num_conta,cliente.tipo_conta,
			                         cliente.nome,cliente.saldo);
		  } else posicao=-1;
		  fclose(arq);
	   }   
	return posicao;

}

void contaEspecial(){
    conta cliente;
	printf("\nEXIBE TODAS CONTAS DO ARQUIVO BINARIO CONTAS.DAT");
	FILE *arquivo = fopen("contas.dat","rb");
	fread(&cliente,sizeof(conta),1,arquivo);
	while(!feof(arquivo)){
		if(cliente.tipo_conta=='E')
		printf("\nNumero:%d  Tipo%c  Nome%s  Limite%5.2f  Saldo%5.2f",cliente.num_conta,cliente.tipo_conta,
		                 cliente.nome,cliente.limite,cliente.saldo);
		fread(&cliente,sizeof(conta),1,arquivo);                 
	}
	fclose(arquivo);
	printf("\n\n");
}
void contaComum(){
    conta cliente;
	printf("\nEXIBE TODAS CONTAS DO ARQUIVO BINARIO CONTAS.DAT");
	FILE *arquivo = fopen("contas.dat","rb");
	fread(&cliente,sizeof(conta),1,arquivo);
	while(!feof(arquivo)){
		if(cliente.tipo_conta=='C')
		printf("\nNumero:%d  Tipo%c  Nome%s  Limite%5.2f  Saldo%5.2f",cliente.num_conta,cliente.tipo_conta,
		                 cliente.nome,cliente.limite,cliente.saldo);
		fread(&cliente,sizeof(conta),1,arquivo);                 
	}
	fclose(arquivo);
	printf("\n\n");
}

void Deposito(int num, float valor){
	conta cliente;
	int posicao=consulta(num);
	
	if(posicao==-1)
	printf("\nNao localizou esta conta");
	
	else{
		FILE *arq=fopen("contas.dat","r+b");
		
		if(arq!=NULL){
		fseek(arq,posicao*sizeof(conta),SEEK_SET);
        fread(&cliente,sizeof(conta),1,arq);
		cliente.saldo+=valor;
		fseek(arq,posicao*sizeof(conta),SEEK_SET);
		fwrite(&cliente,sizeof(conta),1,arq);
		printf("\nSucesso conta:%d Nome:%s novo saldo:%5.2f",cliente.num_conta,cliente.nome,cliente.saldo);
		fclose(arq);
		   } 
	    else printf("\nNao conseguiu localizar o arquivo");
	}
	
}
void Saque(int num, float valor){
	conta cliente;
	int posicao=consulta(num);
	
	if(posicao==-1)
	printf("\nNao localizou esta conta");
	
	else{
		FILE *arq=fopen("contas.dat","r+b");
		
		if(arq!=NULL){
		fseek(arq,posicao*sizeof(conta),SEEK_SET);
        fread(&cliente,sizeof(conta),1,arq);
		   if(cliente.saldo+cliente.limite>=valor){
		   cliente.saldo-=valor;
		   fseek(arq,posicao*sizeof(conta),SEEK_SET);
		   fwrite(&cliente,sizeof(conta),1,arq);
		   printf("\nSucesso conta:%d Nome:%s novo saldo:%5.2f",cliente.num_conta,cliente.nome,cliente.saldo);
	    	}
		
		   else printf("\nNao ha saldo");
		   fclose(arq);
	   } 
	
	    else printf("\nNao conseguiu localizar o arquivo");
	
	}
	
}
main(){
	conta cliente;
	int opcao=0;
	int num, posicao;
	float valor;
	while (opcao!=9){
		printf("\n1 - Leitura do teclado e grava CONTAS num arquivo binario");
		printf("\n2 - Relatorio: leitura do arquivo e exibe todos na tela");
		printf("\n3 - Novas contas: leitura teclado e grava sem apagar as anteriores");
		printf("\n4 - Consulta uma conta");
		printf("\n5 - Exibe todas as contas Especiais gravadas no arquivo binario");
		printf("\n6 - Exibe todas as contas Comuns gravadas no arquivo binario");
	    printf("\n7 - Deposito em uma conta");
        printf("\n8 - saque em uma conta");	
		printf("\n9 - Sair");
		printf("\nQual opcao?");
		scanf("%d",&opcao);
	    switch (opcao){
	    	case 1: leTecladoGravaArquivo();
	    	        break;
	    	case 2: relatorio();
			        break;
			case 3: novasContas();
			        break;
			case 4: printf("\nQual numero da conta a ser consultado?");
			        scanf("%d",&num);
					posicao= consulta(num);
					if (posicao==-1)
					   printf("\nEsta conta nao existe no arquivo %d\n",num);
					   else
					   printf("\nEsta conta foi localizada no arquivo na posicao %d\n\n",posicao);
					break; 
			case 5: contaEspecial();
					break;   
			case 6: contaComum();	
					break;   
			case 7: printf("\nEntre com conta a ser realizado o deposito:");
			        scanf("%d",&num);
					printf("\nEntre com o valor de deposito:");
					scanf("%f",&valor);
					Deposito(num,valor);
					break;
			case 8:	printf("\nEntre com conta a ser realizado o saque:");
			        scanf("%d",&num);
					printf("\nEntre com o valor do saque:");
					scanf("%f",&valor);
					Saque(num,valor);
					break;		
			  			        
		}
	}
	printf("\nFIM");
	getchar();
}


