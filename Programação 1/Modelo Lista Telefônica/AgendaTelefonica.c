#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

#define MAX 100

// Declaração da estrutura à ser utilizada
struct AgendaTelefonica{
	int Telefone;	
	char Nome[30];
};

//Renomeando a estrutura AgendaTelefonica para Agenda
typedef struct AgendaTelefonica Agenda; 

//Protótipos das funções

int Carrega_ArquivoTexto(Agenda A[MAX], int TL);

int Insere(Agenda A[MAX],int TL);	
	
void Exibe(Agenda A[MAX], int TL);	
	
void Armazenar(Agenda A[MAX], int TL);

int main(){
	setlocale (LC_ALL,""); //Linha para uso de acentos
	int op; // opcao
	int TL=0; // tamanho logico
	int TL_APOS_CARGA=0; //tamanho logico apos carga da estrutura
	Agenda A[MAX]; // declaracao da estruta
	int TL_APOS_INSERCAO=0; //tamanho logico apos a insercao de dados
	TL_APOS_CARGA=Carrega_ArquivoTexto(A,TL); // tl_apos_carga recebe o tanto de linhas carregadas
	do{
	system ("cls");
	printf ("\n 1. Cadastrar nome e telefone. ");
	printf ("\n 2. Listar todos os nomes e telefones. ");
	printf ("\n 3. Armazenar dados no arquivo texto. ");
	printf ("\n 4. Sair. ");
	printf ("\n Deseja qual opção: ");
	scanf ("%d",&op); 
	   switch(op){
	   	
		case 1:
				TL_APOS_INSERCAO=Insere(A,TL_APOS_CARGA);   			
				TL_APOS_CARGA=TL_APOS_INSERCAO;
				system("pause");
			    break;
		
		case 2:
				Exibe(A,TL_APOS_CARGA);
	   			system("pause");
	   			break;
	   	   
		case 3:
				Armazenar(A,TL_APOS_CARGA);   
		   		system("pause");
		   		break;
		   		
		case 4:
	   		default:
	   		printf ("\n Opção Invalida!! \n Tente mais uma vez \n \n");
	   		system("pause");
			break;
	   
	   }
	}while (op!= 4);
	system("pause");
}

int Insere(Agenda A[MAX],int TL){
	fflush(stdin);//limpar buffer do teclado
	printf("Nome: ");
	scanf("%[^\n]s",A[TL].Nome);// armazenar nome na ultima posicao da estrura
	printf("\nTelefone: ");
	scanf("%d",&A[TL].Telefone); // armazenar telefone na ultima posicao da estrura
	TL++;
return TL;
}	

void Exibe(Agenda A[MAX], int TL){
	int i;
	for(i=0 ; i<TL ; i++){
		printf("%d\t%s\t%d\n",i,A[i].Nome,A[i].Telefone);	// Exibir conteudo da estrutura
}
}

void Armazenar(Agenda A[MAX], int TL){//Funcao para armazenar da estrutura no arquivo.txt
	FILE *arq;
	int i;
	arq=fopen("Agenda.txt","w");  //Abrindo arquivo
	if(arq == NULL){ // se arquivo == null, não foi possivel abrir
			printf("Erro, nao foi possivel abrir o arquivo desejado!!!\n");
				system("pause");
}
	else{//Carregar os dados do arquivo pro programa
			for(i = 0 ; i < TL ; i++ )
			fprintf(arq,"%s %d\n",A[i].Nome,A[i].Telefone);//printar no arquivo.txt o conteudo da estrutura
			}
	fclose(arq);
}

int Carrega_ArquivoTexto(Agenda A[MAX], int TL){ // funcao para pegar conteudo do arquivo.txt
	FILE *arq;
	arq=fopen("Agenda.txt","r");  //Abrindo arquivo
	if(arq == NULL){ // se arquivo == null, não foi possivel abrir
			printf("Erro, nao foi possivel abrir o arquivo desejado!!!\n");
				system("pause");
				return 0;
}
	else{//Carregar os dados do arquivo pro programa
			while(!feof(arq)){
				fscanf(arq,"%s %d\n",A[TL].Nome,&A[TL].Telefone);//armazenar conteudo arquivo.txt na estrutura
				TL++;//ir para proxima posicao
				}
			}
	fclose(arq);
	return TL;//Retorna o tamanho total
}

