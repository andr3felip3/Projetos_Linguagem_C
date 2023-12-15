#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"avl.h"

// Operações

// Iniciar/definir
void define(Arvore *t){
	t->raiz=NULL;
}

int vazia(Arvore *t){
	return(t->raiz==NULL);
}

//buscar
int busca(Arvore *t, char e[100]){
	busca_rec(t->raiz, e);
}
int busca_rec(No *t, char e[100]){
	if(t==NULL)
		return 0;
		//comando pra comparar se sao iguais ou maiores ou menores strcmp
		// se for igual a 0 sao iguais 
	else if(strcmp(t->info.e,e)==0) 
		return printf("%s %s ",t->info.e, t->info.p);
	else if(strcmp(t->info.e,e)>0)
		return busca_rec(t->dir, e);
	else 
		return busca_rec(t->esq, e);
			
}


// inserir
void inserir(Arvore *t, tipo_elem v){
	int flag = 0;
	inserir_rec(&(t->raiz),&v, &flag);
}
void inserir_rec(No **t, tipo_elem *v, int *flag){
	if((*t)==NULL){
		(*t)=(No*)malloc(sizeof(No));
		(*t)->info = *v;
		(*t)->esq = (*t)->dir = NULL;
		(*t)->fb = 0;
		*flag = 1;
	}
	else{
		if(v->e <(*t)->info.e){
			inserir_rec(&((*t)->esq), v, flag);
			if(*flag){
				switch((*t)->fb){
					
				
				case 0:
					(*t)->fb = -1;
				break;
				
				case 1:
					(*t)->fb = 0;
					*flag = 0;
				break;
				
				case -1://houve desbalanciamento
					if(((*t)->esq)->fb == -1)//rotação simples
						rot_dir(&(*t));
					else//(((*t)->esq)->fb == 1)//rotação dupla
						rot_esq_dir(&(*t));
						(*t)->fb = 0;
						*flag = 0;
				break;
				}
				
			}	
		}
		else if(v->e <(*t)->info.e){
			inserir_rec(&((*t)->esq), v, flag);
			if(*flag){
				switch ((*t)->fb){
					case 0:
						(*t)->fb =1;
					break;
					case -1:
						(*t)->fb = 0;
						(*flag) = 0;
					break;
					case 1://houve desbalanciamento
						if(((*t)->dir)->fb==1)//rotaçao simples pra esquerda
						rot_esq(&(*t));
						else //rotação dupla
							rot_dir_esq(&(*t));
							(*t)->fb=0;
							*flag = 0;
					break;
							
				}
			}
		}	
	}
}
 //rotação simples para direita
 
void inserir_um_elemento(tipo_elem *v, char e[100], char p[100]){
	strcpy(v->e,e);
	strcpy(v->p,p);
	
}
 
void rot_dir(No **p){
	No *q, *r;
	q = (*p)->esq;
	r= q->dir;
	q->dir = *p;
	(*p)->esq = r;
	(*p) = q;
}

//rotação simples para esquerda
void rot_esq(No **p){
	No *q , *r;
	q = (*p)->dir;
	r  = q->esq;
	q ->esq = *p;
	(*p)-> dir = r;
	(*p) = q;
	
}
// rotação dupla direita-esquerda
void rot_dir_esq(No **p){
	rot_dir(&((*p)->dir));
	rot_esq(&(*p));
	
}
// rotação dupla esquerda-direita
void rot_esq_dir(No **p){
	rot_esq(&((*p)->esq));
	rot_dir(&(*p));
}

// remover
int remover(Arvore *t, int chave){
}

// esvaziar / destruir
void esvaziar(Arvore *t){
	esvaziar_rec(&(t->raiz));
}
void esvaziar_rec(No **p){
	if(*p != NULL){
		esvaziar_rec(&((*p)->esq));
		esvaziar_rec(&((*p)->dir));
		free(*p);
		*p = NULL;
	}
}
// número de elementos
int num_elementos(Arvore *t){//usar o percurso em pré-ordem
	return(tam(t->raiz));
}

int tam(No *p){
	if(p==NULL)
		return 0;
	return(1+tam(p->esq)+tam(p->dir));
}
// exibir usando paragrafação
void exibir_preordem(Arvore *t){
	exibir_preordem_rec(t->raiz);
}
void exibir_preordem_rec(No *p){
	if(p!=NULL){
		printf("%s-------:%s\n",p->info.e,p->info.p);
		exibir_preordem_rec(p->esq);
		exibir_preordem_rec(p->dir);
	}
}


void exibir_inordem(Arvore *t){
	exibir_inordem_rec(t->raiz);
}
void exibir_inordem_rec(No *p){
		if(p!=NULL){
		
		exibir_inordem_rec(p->esq);
		printf("%s-------:%s\n",p->info.e,p->info.p);
		exibir_inordem_rec(p->dir);
	}
}
void exibir_posordem(Arvore *t){
	exibir_posordem_rec(t->raiz);
}

void exibir_posordem_rec(No *p){
		if(p!=NULL){
		
		exibir_posordem_rec(p->esq);
		exibir_posordem_rec(p->dir);
		printf("%s-------:%s\n",p->info.e,p->info.p);
	}
}
