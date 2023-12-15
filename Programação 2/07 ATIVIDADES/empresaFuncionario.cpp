#include<stdio.h>
#include<string.h>
struct funcionario{
	char nome[10];
	float salario;
	int idade;
};
void carrega(struct funcionario vetor[10],int &tl){
	// ler o arquivo texto empresa.txt e carregar o vetor de funcionarios
	// tl++;
}
void exibe(struct funcionario vetor[10], int tl){
     // voce tem que exibir todos os funcionarios dentro do vetor
}
int busca(struct funcionario vetor[10],int tl,char nome[]){
	int posicao=-1;
	return posicao;
}
main(){
	int opcao=0;
	struct funcionario vetor[10];
	int tl=0, posicao;
	char nome[10];
	while (opcao!=7){
		printf("\n\n1 - Leitura do arquivo texto para carregar o vetor");
		printf("\n2 - Exibe o vetor na memoria principal");
		printf("\n3 - Consulta um funcionario (busca) no vetor");
		printf("\n4 - Inclusao de um novo funcionario no vetor - memoria principal");
		printf("\n5 - Remocao de um funcionario no vetor");
		printf("\n6 - Regravar o arquivo texto- grava no HD ");
		printf("\n7 - Sair");
		printf("\n Opcao:"); scanf("%d",&opcao);
		switch (opcao) {
			case 1: carrega(vetor,tl);
			        printf("\nVetor carregado com tl=%d funcionarios", tl);
			        break;
			case 2: exibe(vetor,tl);
			        break; 
			case 3: printf("\n Entre com o nome a ser procurado: ");
			        scanf("%s",&nome);
					posicao = busca(vetor, tl, nome);
					if (posicao==-1)
					   printf("\n Nao encontrou");
					   else printf("\n Encontrou na posicao %d %s",posicao,nome);
					break;
			case 4: //inclusao(vetor,tl);
			        break;
			case 5: printf("\n faca voce a remocao como exercicio");
			        break;        
			case 6: //regravar(vetor,tl);
			        break;		   		       
		}
		
	}
}
