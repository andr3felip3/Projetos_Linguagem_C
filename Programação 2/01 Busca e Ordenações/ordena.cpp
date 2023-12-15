#define TF 50000  // tamanho do vetor
#define MAX 9999 // maximo elemento gerado randomicamente dentro do vetor

#include <stdbool.h> // para usar variaveis booleanas
#include <time.h>  // calcular a diferença do tempo inicial e final
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
void bolha(int vetor[TF]){
	 int i;
      int  tam;
      tam = TF-1;
      while ( tam > 1)  {
         for (i=0; i<tam; i++)    {
            if (vetor[i]>vetor[i+1])  {
               int aux=vetor[i];
               vetor[i]=vetor[i+1];
               vetor[i+1]=aux;
            }
         }
         tam=tam-1;
      }
   }
void selecao(int vetor[TF]){
	  int i, j, menor, posmenor;
      for (i=0;i<TF-1;i++)   {
         menor=vetor[i];
         posmenor=i;
         for (j=i+1;j<TF;j++)
            if  (vetor[j]<menor) {
                 menor=vetor[j];
                 posmenor=j;
            }
         vetor[posmenor]=vetor[i];
         vetor[i]=menor;
      }
}
int buscaSequencial(int vetor[TF], int tl, int aux)   { 
      int i=0;
      while ((aux > vetor[i])&&(i<tl))
              i=i+1;
      return i; // achou na posição i
}
void insercaoDireta(int vetor[TF]){
	int aux, i, j, n, posi;
      if (vetor[0]>vetor[1]) // ordena 2 primeiros
      {
         aux=vetor[0];
         vetor[0]=vetor[1];
         vetor[1]=aux;
      }
      for (n=2;n<TF;n++) // insere na parte ordenada
      {
         aux=vetor[n];
         posi=buscaSequencial(vetor,n,aux);

         for  (j=n; j>posi; j-- )
            vetor[j]=vetor[j-1];
         vetor[posi]=aux;
      }
   }
int buscaBinaria(int vetor[TF],int tl, int elem)    { // obrigatorio o vetor estar ORDENADO
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
void insercaoBinaria(int vetor[TF]){
	int aux, i, j, n, posi;
      if (vetor[0]>vetor[1]) // ordena 2 primeiros
      {
         aux=vetor[0];
         vetor[0]=vetor[1];
         vetor[1]=aux;
      }
      for (n=2;n<TF;n++) // insere na parte ordenada
      {
         aux=vetor[n];
         posi=buscaBinaria(vetor,n,aux);

         for  (j=n; j>posi; j-- )
            vetor[j]=vetor[j-1];
         vetor[posi]=aux;
      }
}
main(){
	int tl=0;
	int vetor[TF];
	bool ordenado=false;
	int opcao=0,posicao=-1,elem;
	time_t tempoi, tempof;
	float diferenca;

	while (opcao != 7){
		printf("\n1 - Cria o vetor de %d elementos",TF);
		printf("\n2 - Exibe o vetor gerado");
		printf("\n3 - BOLHA ordena o vetor");
		printf("\n4 - SELECAO ordena o vetor");
		printf("\n5 - INSERCAO DIRETA ordena o vetor");
		printf("\n6-  INSERCAO BINARIA ordena o vetor");
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
			case 3: tempoi = time(NULL); // obtem o tempo inicial para cronometrar
			        bolha(vetor);
			        tempof = time(NULL);
			        diferenca = difftime(tempof, tempoi);
			        printf("\n ordenou metodo BOLHA e demorou %f num vetor de %d elementos",diferenca, TF);
			        ordenado=true;
					break;
			case 4: tempoi = time(NULL); // obtem o tempo inicial para cronometrar
			        selecao(vetor);
			        tempof = time(NULL);
			        diferenca = difftime(tempof, tempoi);
			        printf("\n ordenou metodo SELECAO e demorou %f num vetor de %d elementos",diferenca, TF);
			        ordenado=true;
					break;
			case 5: tempoi = time(NULL); // obtem o tempo inicial para cronometrar
			        insercaoDireta(vetor);
			        tempof = time(NULL);
			        diferenca = difftime(tempof, tempoi);
			        printf("\n ordenou funcao INSERCAO DIRETA e demorou %f num vetor de %d elementos",diferenca, TF);
			        ordenado=true;
					break;
			case 6: tempoi = time(NULL); // obtem o tempo inicial para cronometrar
			        insercaoBinaria(vetor);
			        tempof = time(NULL);
			        diferenca = difftime(tempof, tempoi);
			        printf("\n ordenou funcao INSERCAO BINARIA e demorou %f num vetor de %d elementos",diferenca, TF);
			        ordenado=true;
					break;	
		}//switch
	}//while
}//main
