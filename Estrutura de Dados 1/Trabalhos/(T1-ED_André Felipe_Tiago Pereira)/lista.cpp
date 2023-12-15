#include<stdio.h>
#include<string.h>
#include "lista.h"
#include <stdlib.h>

//Define
void define(Lista *L){
	L->inicio=NULL;
}

//exibir todos os elementos da lista
void exibir(Lista *L){
	No *p;
	if(vazia(L))
		printf("Nao ha Palavras\n");
	else{
		p = L->inicio;
		while(p){
			exibir_um_elemento(p->info);
			p=p->prox;
		}
	}
}

//Exibi um elemento
void exibir_um_elemento(tipo_elem v){
	
	printf("%s-------:%s\n",v.engh,v.port);
}


//insere uma palavra
void inserir_palavra(tipo_elem *v, char engh[30],char port[30]){
	strcpy(v->port, port);
	strcpy(v->engh, engh);	
}


//inserir no início
int inserir_inicio(Lista *L, tipo_elem v){
	No *p = (No *)malloc(sizeof(No));
	if(p==NULL)// não alocou espaço p==NULL
		return 0;
	p->info = v;
	p->prox = L->inicio;
	L->inicio = p;
	return 1;
}

//inserir no final da lista 
int inserir_final(Lista *L, tipo_elem v){
	No *q, *p;
	q = L->inicio;
	
	if(vazia(L))
		return(inserir_inicio(L,v));
		
	//atializando os campos de p	
	p = (No *)malloc(sizeof(No));
	if(!p)// não alocou espaço p==NULL
		return 0;
	p->info = v;
	p->prox = NULL;
	//buscar o ultimo elemento
	while(q->prox!=NULL)
		q = q->prox;
		//inserir p depois de q, pois q é o ultimo elemento da lista
		q->prox= p;
		return 1;
}


//inserir na posição depois de k
int inserir_pos(Lista *L, tipo_elem v, No* k){

	No *p = (No *)malloc(sizeof(No));
	if(!p) return 0;
	p->info = v;
	p->prox = k->prox;
	k->prox = p;
	return 1;		
}
//Insere ordenado
int inserir_ord(Lista *L, tipo_elem v){
	No *p = L->inicio;
	No *q = NULL;
	//buscar a posição a ser inserido o elemento
	while(p && (strcmp(p->info.port,v.port)<0)){ //(p && (p->info.port< (strcmp(p->info.port,v.port)<0)))
		q = p;
		p = p->prox;
		 
	}
	if(q==NULL)
		return(inserir_inicio(L,v));
		
	return(inserir_pos(L,v,q));	

}

//remover uma palvra 
int remover(Lista *L, char port[30]){
	No *p,  *q;
	
	if(vazia(L))
		return 0;
		//buscar o elemento na lista
		
		p = L->inicio;
		q = NULL;
		while(p && (strcmp(p->info.port,port) !=0)){//(p->info.chave!=chave)
								//strcmp(p->info.chave,port) !=0
			q = p;
			p = p->prox;
		}
		if(p==NULL)
			return 0;
		if(q==NULL)
			L->inicio = p->prox;
		else
			q->prox = p->prox;
		free(p);
}
//Esvaziar
void esvaziar(Lista *L){
	No *p =L->inicio;
	No *q;
	
	while(p!=NULL){
		q = p->prox;
		free(p);
		p= q;
	}
	L->inicio = NULL;
}

//Busca
int Busca(Lista *L, char engh[30]){
	No *p = L->inicio;
	int a;
	 
	while(p!=NULL){
		
		a=strcmp(p->info.engh,engh);
		
		if(a==0){
			printf("\nINGLES-------PORTUGUES\n\n");
			printf("%s %s\n\n",p->info.engh,p->info.port);
			return 1;	
		}
			
			
		p = p->prox;
	}
	return 0;
}

//Veirificar se ta vazia		
int vazia(Lista *L){
	return(L->inicio==NULL);
}

//verifica o tamanho da lista
int tamanho(Lista *L){
	No *p = L->inicio;
	int cont = 0;
	 
	while(p!=NULL){
		cont++;
	
		p = p->prox;
	}
	return cont;
}

