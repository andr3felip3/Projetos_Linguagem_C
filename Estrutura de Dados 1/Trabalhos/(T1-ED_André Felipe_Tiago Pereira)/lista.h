// tad Lista
//Implementa��o Lista Encadeada Din�mica

typedef struct{
	char engh[30],port[30];
}tipo_elem; 


typedef struct no{
	tipo_elem info;
	struct no *prox;
}No; 


typedef struct{
	No *inicio;
}Lista;

//Estrutura de dados Lista

//Opera��es:


//Define
void define(Lista *L);


//exibir todos os elementos da lista
void exibir(Lista *L);


//exibir um elemento
void exibir_um_elemento(tipo_elem v);


//inser��o de elemento a elemento
void inserir_palavra(tipo_elem *v, char engh[30],char port[30]);


//inserir no in�cio
int inserir_inicio(Lista *L, tipo_elem v);


//remove palavra
int remover(Lista *L, char port[30]);


//esvazia lista
void esvaziar(Lista *L);


//busca palavra
int Busca(Lista *L, char engh[30]);


//se ta vazia	
int vazia(Lista *L);

	
//tamanho da lista
int tamanho(Lista *L);

 
