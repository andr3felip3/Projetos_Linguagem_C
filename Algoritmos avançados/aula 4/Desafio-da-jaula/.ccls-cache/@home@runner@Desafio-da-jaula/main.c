#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(const void * a, const 
void *b){
    return (*(int*)a - *(int*)b);
    
  }

typedef struct {
	int primeiro;
int segundo;
}jau;

int main() {
  int jaulas=3;  //c
  int animais=4;  //s
  int massas[20]={5,1,2,7};  //M
  int extra;
  jau j[jaulas];

  // se S < 2C
  if(animais<(2*jaulas)){
     extra = (2*jaulas);
    for(int i=0;i<extra;i++){
     massas[extra]=0;
      massas[extra-1]=0;
      }
    }

//ordenação
    qsort(massas,6,sizeof(int),compare);


// exibe
  for(int i=0;i<3;i++){
       printf("#Jaula %d:",i+1);
        j[i].primeiro=massas[i];
        j[i].segundo=massas[extra-1];
        if(j[i].primeiro > 0)
        printf(" %d", j[i].primeiro);
        
        if(j[i].segundo > 0)
        printf(" %d\n",j[i].segundo);
        extra--;
     }

  return 0;
}