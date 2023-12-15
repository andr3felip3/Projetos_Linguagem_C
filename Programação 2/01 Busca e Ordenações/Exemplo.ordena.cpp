#define TF 7  // tamanho do vetor
#define MAX 99999 // maximo elemento gerado randomicamente dentro do vetor

#include <stdbool.h> // para usar variaveis booleanas
#include <time.h>  // calcular a diferença do tempo inicial e final
#include <stdlib.h> // pra usar a funcao RAND()
#include <stdio.h>
void cria(int vetor[TF]){
	//for (int i=0;i<TF;i++){
	//	vetor[i]= rand() % MAX;
	//}
	vetor[0]=30;
	vetor[1]=26;
	vetor[2]=20;
	vetor[3]=15;
	vetor[4]=16;
	vetor[5]=24;
	vetor[6]=10;	
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
int buscaSequencial(int vetor[TF], int tl, int elem)   { 
      int i=0;
      while ((elem > vetor[i])&&(i<tl))
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
void heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(true) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n <= 0) 
		  return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}
void quickSort(int vetor[], int inicio, long fim) {
      int aux, i,  pivo;
      long j;
      i=inicio;     j=fim;
      pivo=vetor[(i+j)/2];
      do {
         while(vetor[i]<pivo) i++;
         while(vetor[j]>pivo) j--;
         if(i<=j)  {
            aux= vetor[i];
            vetor[i]=vetor[j];
            vetor[j]=aux;
            printf("\n 0=%d  1=%d  2=%d  3=%d  4=%d   5=%d  6=%d",vetor[0],vetor[1],vetor[2],vetor[3],vetor[4],vetor[5],vetor[6]);
            i++;
            j--;
         }
      } while(i<=j);
      if (j>inicio) quickSort(vetor,inicio,j);
      if (i<fim) quickSort (vetor,i,fim);   
}
main(){
	int tl=0;
	int vetor[TF];
	bool ordenado=false;
	int opcao=0,posicao=-1,elem;
	time_t tempoi, tempof;
	float diferenca;

	while (opcao != 9){
		printf("\n1 - Cria o vetor de %d elementos",TF);
		printf("\n2 - Exibe o vetor gerado");
		printf("\n3 - BOLHA ordena o vetor");
		printf("\n4 - SELECAO ordena o vetor");
		printf("\n5 - INSERCAO DIRETA ordena o vetor");
		printf("\n6-  INSERCAO BINARIA ordena o vetor");
		printf("\n7-  HEAPSORT ordena o vetor");
		printf("\n8-  QUICKSORT ordena o vetor");
		printf("\n9 - Sair");
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
			case 7: tempoi = time(NULL);
			        heapsort(vetor,TF);
					tempof = time(NULL);
					diferenca = difftime(tempof,tempoi);
					printf("\n ordenou pelo HEAPSORT e demorou %f num vetor de %d elementos",diferenca,TF);
					ordenado=true;
					break;
			case 8: tempoi = time(NULL);
			        quickSort(vetor,0,TF-1);
					tempof = time(NULL);
					diferenca = difftime(tempof,tempoi);
					printf("\n ordenou pelo QUICKSORT e demorou %f num vetor de %d elementos",diferenca,TF);
					ordenado=true;
					break;		
								
		}//switch
	}//while
}//main
