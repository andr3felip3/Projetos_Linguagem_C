#define TF 5000 //contsante de valor 50
#define MAX 999 //constante de valor 1000
#include <stdbool.h> // para usar variaveis booleanas
#include <time.h>
#include <stdlib.h> // pra usar a funcao RAND()
#include <stdio.h>
void cria(int vetor[TF]){
	for (int i=0;i<TF;i++){
		vetor[i]= rand() % MAX;
	}
}
void exibe(int vetor[TF]){
		int i;
	for (i=0;i<TF;i++)
	   printf("\n vetor[%2d]=%3d",i,vetor[i]);
	getchar();
}
void ordena(int vetor[TF]){
	   int fim,j,aux;
       for (fim=TF-1;fim>0;fim--)
         for (j=0;j<fim;j++){
           if (vetor[j]>vetor[j+1]) {//troca
              aux = vetor[j];
			  vetor[j]=vetor[j+1];
			  vetor[j+1]=aux;
		  }//if
	  }	//for J
}
int  buscaExaustiva (int vetor[TF], int elem)   { // vetor DESORdenado
      int i=0;
     
      while ((vetor[i] != elem)&&(i<TF))
	  
         i=i+1;
      if ((i < TF) && (vetor[i] == elem)){
	  
                return i;           // achou na posição i 
            
			    }else return  -1; // não achou
  
            
}
int buscaSequencial(int vetor[TF], int elem)   { // obrigatorio o vetor estar ORDENADO
      int i=0;
      while ((elem > vetor[i])&&(i<TF))
              i=i+1;
      if ((i<TF) && (elem == vetor[i])) 
           return i; // achou na posição i
       else return -1; // não achou
}
int buscaBinaria(int vetor[TF], int elem)    { // obrigatorio o vetor estar ORDENADO
      int inicio, meio, fim;
      inicio=0;
      fim=TF-1;
      meio=(inicio+fim)/2;
      while((elem!=vetor[meio])&&(inicio<fim))       {
         if(elem>vetor[meio])
            inicio=meio+1;
            else
            fim=meio;
         meio=(inicio+fim)/2;
      }
      if (elem>vetor[meio])
         return(meio+1);
         else
         return(meio);
}
main(){
	time_t ti,tf;
	float tempo;
	int tl=0;
	int vetor[TF];
	bool ordenado=false;
	int opcao=0,posicao=0,elem;
	while (opcao != 7){
		printf("\n1 - Cria o vetor de 50 elementos");
		printf("\n2 - Exibe o vetor gerado");
		printf("\n3 - Ordena o vetor");
		printf("\n4 - Busca Exaustiva de um elemento no vetor desordenado");
		printf("\n5 - Busca Sequencial num vetor Ordenado");
		printf("\n6 - Busca Binaria num vetor Ordenado");
		printf("\n7 - Sair");
		printf("\nEntre com a opcao: ");
		scanf("%d",&opcao);
		switch(opcao){
			case 1: srand(time(NULL));  
			        cria(vetor);
			        ordenado=false;
			        printf("\n vetor gerado com %d elementos \n\n",TF);
			        break;
			case 2: exibe(vetor);
			        break;
			case 3: ordena(vetor);
			        printf("\n ordenou vetor");
			        ordenado=true;
					break;
			case 4: printf("\n Exaustiva. Entre com o valor a ser procurado: ");
			        scanf("%d",&elem);
			        
					ti=time(NULL);
				posicao = buscaExaustiva(vetor,elem);
					tf=time(NULL);
                    tempo=difftime(tf,ti);
					
					if (posicao==-1)
					   printf("\n NAO encontrou e Demorou %.2f segundos no vetor de %d posicoes\n",tempo,TF);
					   else 
					   printf("\n Encontrou no vetor na posicao vetor[%d]=%d e Demorou %.2f segundos num vetor de %d posicoes\n",posicao,vetor[posicao],tempo,TF);
					
					break;
			case 5: printf("\n SEQUENCIAL exige vetor ORDENADO!!! \n Entre com o valor a ser procurado: ");
			        scanf("%d",&elem);
			        if (ordenado){
					ti=time(NULL);
					  posicao = buscaSequencial(vetor,elem);
					  tf=time(NULL);
                    tempo=difftime(tf,ti);
					  if (posicao == -1)
					    printf("\n NAO encontrou e Demorou %.2f segundos no vetor de %d posicoes \n",tempo,TF);
					     else printf("\n Encontrou no vetor na posicao vetor[%d]=%d e Demorou %.2f segundos num vetor de %d posicoes \n",posicao,vetor[posicao],tempo,TF);
				}
					else printf("Vetor NAO esta ordenado \n\n");
					break;
			case 6: printf("\n BINARIA exige vetor ORDENADO!!! \n Entre com o valor a sere procurado: ");
			        scanf("%d",&elem);
			        if (ordenado){
					  posicao = buscaBinaria(vetor,elem);
					  if (vetor[posicao]!=elem)
					     printf("\n NAO encontrou - posicao ideal para inserir %d e Demorou %.2f no vetor de %d posicoes \n",posicao,tempo,TF);
					     else printf("\n Encontrou no vetor na posicao vetor[%d]=%d e Demorou %.2f no vetor de %d posicoes \n",posicao,vetor[posicao],tempo,TF);
				    } else 
					    printf("Vetor NAO esta ordenado \n\n");
					break;				   	        		       

	
		}//switch
	}//while
}//main


