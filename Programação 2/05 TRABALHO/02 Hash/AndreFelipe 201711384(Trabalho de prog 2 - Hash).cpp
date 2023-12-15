   /*  ANDRÉ FELIPE COSTA DA SILVA  201711384  */
 
#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct no{
    int codigo;
    char nome[10];
    float notafinal;
    no* prox;
};
struct partab{
	int chave;
	no* cabeca;
};
int HASH (int codigo){
	int ender;
	ender = (codigo % 15);
	return ender;
}
void criar(struct partab tabela[15]){
	int i;
	for(i=0;i<15;i++){
	tabela[i].chave=0;
	tabela[i].cabeca=NULL;
	}
  printf("***** TABELA CRIADA *****");
}
void inserir (struct partab tabela[15]){
    int codigo;
    no* novo= new no;
    printf("\n Entre com o CODIGO do aluno: ");
    scanf("%d",&novo->codigo);
    printf("\n Entre com o NOME do aluno: ");
    scanf("%s",&novo->nome);
    printf("\n Entre com a NOTA FINAL do aluno: ");
    scanf("%f",&novo->notafinal);
    novo->prox=NULL;
	int ender = HASH(novo->codigo);
	if(tabela[ender].cabeca==NULL)
	 tabela[ender].cabeca=novo;
	else {
	  novo->prox=tabela[ender].cabeca;
	  tabela[ender].cabeca=novo;
}
printf("\nCadastro feito com sucesso !!");	
}
void exibir(struct partab tabela[15]){
	printf("\n*** TODOS OS ALUNOS QUE FORAM CADASTRADOS ***\n");
	no* atual=NULL;
	for (int i=0;i<15;i++){
		printf("\n chave:%d",i);
		atual=tabela[i].cabeca;
		while(atual!=NULL){
printf("\n  | Nome: %s - Nota final: %.2f - Codigo do aluno: %d |",atual->nome,atual->notafinal,atual->codigo);
       atual=atual->prox;
		}
		
	}
	
}
void exibirAprovados(struct partab tabela[15]){
	printf ("\n * ALUNOS APROVADOS COM NOTA FINAL SUPERIOR OU IGUAL A 7 *\n\n");
	no* atual;
	for (int i=0;i<15;i++){	
		atual=tabela[i].cabeca;
		while(atual!=NULL){
		if (atual->notafinal>=7){
        printf("| Nome: %s - Nota final: %.2f - Codigo do aluno: %d - Chave: %d|\n",atual->nome,atual->notafinal,atual->codigo,i);
		atual=atual->prox;
	}
		else atual=atual->prox;
      
    }
  }
}
main(){
	struct partab tabela[15];
	criar(tabela);
	int opcao=0;
	while (opcao!=4){
		printf("\n\n1 - Cadastrar aluno com seu Codigo, Nome e Nota Final");
		printf("\n2 - Consultar todos os alunos que foram cadastrados");
		printf("\n3 - Consultar todos os alunos aprovados");
		printf("\n4 - sair");
		printf("\n\n Qual sua opcao: ");
		scanf("%d",&opcao);
		switch(opcao){
			case 1: inserir(tabela);
			    break;
			case 2: exibir(tabela);
			     break;
		    case 3: exibirAprovados(tabela);
		          break;
		}
	}	
	
}

   /*  ANDRÉ FELIPE COSTA DA SILVA  201711384  */
