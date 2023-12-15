#include<stdio.h>
#include<string.h>
struct funcionario{
	char nome[10];
	float salario;
	int idade;
};
void carrega(struct funcionario vetor[10],int &tl){
	//tl=0;
	//char nome[10];
	//int idade;
	//float salario;
	FILE *arq = fopen("empresa.txt", "r"); 
	if(arq == NULL)
		printf("\n Erro, nao foi possivel abrir o arquivo\n");
	else  {
			while( !feof(arq) ){
			     fscanf(arq,"%s %f %d\n",&vetor[tl].nome,&vetor[tl].salario,&vetor[tl].idade);
			     //strcpy(vetor[tl].nome,nome);
			     //vetor[tl].salario = salario;
			     //vetor[tl].idade=idade;
			     tl++;
                     }
	    fclose(arq);
	}
}
void exibe(struct funcionario vetor[10],int tl){
	int i;
	for (i=0;i<tl;i++)
	     printf("\n %d Nome=%s  Salario=$%5.2f  Idade=%d \n",
                             i,vetor[i].nome, vetor[i].salario, vetor[i].idade);
}
int busca(struct funcionario vetor[10], int tl, char nome[10]){
	int posicao=-1, i;
	for (i=0;i<tl;i++){
		if (strcmp(vetor[i].nome,nome)==0)
		     posicao=i;
	}
	return posicao;
}
void inclusao(struct funcionario vetor[10],int tl){
	printf("\n Entre com o novo nome: ");
	scanf("%s",&vetor[tl].nome);
	printf("\n Entre com o salario: ");
	scanf("%f",&vetor[tl].salario);
	printf("\n Entre com a idade:  ");
	scanf("%d",&vetor[tl].idade);
	tl++;
}
void regravar(struct funcionario vetor[10], int tl){
   FILE *f = fopen("empresa.txt", "w"); // abre arquivo texto para gravação
   int i;
   for (i=0; i<tl; i++) 
            fprintf(f,"%s %f %d\n",vetor[i].nome,vetor[i].salario,vetor[i].idade); 
   fclose(f); 
   printf("\n Regravado com sucesso!\n");
}
   void remove(struct funcionario vetor[10],int tl){
   	int i;
   	char nome[10];
    printf("\n nome a ser removido:\n");
    scanf("%s",&nome);
    for(i=0;i<=tl;i++){
    	if (strcmp(vetor[i].nome,nome)==0){
    		strcpy(vetor[i].nome,vetor[i+1].nome);
    		vetor[i].salario=vetor[i+1].salario;
    		vetor[i].idade=vetor[i+1].idade;
    }
    	else printf("\n Funcionario nao cadastrado \n");
			
	
	
	}  
   	
   }

main(){
	int opcao=0; //opçoes para o usuario
	int tl=0;
	int posicao; 
	struct funcionario vetor[10]; 
	char nome[10]; 
	while (opcao!=7){ 
		printf("\n1 - Leitura do arquivo texto para carregar o vetor");
		printf("\n2 - Exibe o vetor");
		printf("\n3 - Consulta um funcionario (busca)");
		printf("\n4 - Inclusao de um novo funcionario");
		printf("\n5 - Remocao de um funcionario no vetor");
		printf("\n6 - Regravar o novo arquivo texto ");
		printf("\n7 - Sair");
		printf("\n Opcao:"); scanf("%d",&opcao);
		switch (opcao) {
			case 1: carrega(vetor,tl); 
			        printf("\n tl %d", tl);
			        break;
			case 2: exibe(vetor,tl);  
			         break; 
			case 3: printf("\n Entre com o nome a ser procurado:\n ");
			            scanf("%s",&nome);
				        posicao = busca(vetor, tl, nome);
				        if (posicao==-1)
					       printf("\n Nao encontrou \n");
				           else printf("\n Encontrou na posicao %d %s \n",posicao,nome);
					break;
					
			case 5 :remove(vetor,tl);
				   tl--;
				     break;
				
			case 4: inclusao(vetor,tl);
			        tl++;
					break;		
			case 6: regravar(vetor,tl);
			        break;		   		       
		}	
	}
}


