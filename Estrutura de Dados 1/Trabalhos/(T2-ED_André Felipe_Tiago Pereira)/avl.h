#include<stdio.h>


//implementação de uma avl

// tipo de dado
typedef struct{
	char e[100], p[100];
}tipo_elem;

typedef struct no{
	tipo_elem info;
	struct no *esq, *dir;
	int fb;//fator de balanciamento
}No;  

// Estrura de Dados AVL
typedef struct{
	No *raiz;
}Arvore;
// Operações

// Iniciar/definir
void define(Arvore *t);

int vazia(Arvore *t);

//buscar
int busca(Arvore *t, char e[100]);

int busca_rec(No *t, char e[100]);

// inserir
void inserir(Arvore *t, tipo_elem v);
void inserir_rec(No **t, tipo_elem *v, int *flag);
void rot_dir(No **p); //rotação simples para direita
void rot_esq(No **p); //rotação simples para esquerda
void rot_dir_esq(No **p); // rotação dupla direita-esquerda
void rot_esq_dir(No **p); // rotação dupla esquerda-direita

void inserir_um_elemento(tipo_elem *v, char e[100], char p[100]);
// remover
int remover(Arvore *t, int chave);

// esvaziar / destruir
void esvaziar(Arvore *t);
void esvaziar_rec(No **p);
// número de elementos
int num_elementos(Arvore *t);

int tam(No *p);

// exibir usando paragrafação
void exibir_preordem(Arvore *t);
void exibir_inordem(Arvore *t);
void exibir_posordem(Arvore *t);

void exibir_preordem_rec(No *p);
void exibir_inordem_rec(No *p);
void exibir_posordem_rec(No *);
