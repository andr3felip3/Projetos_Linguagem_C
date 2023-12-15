#include<stdio.h>

int main() {
    int aux,i,j,cont=0,maior,n;
  scanf("%d %d",&i,&j);
  while((i>0 && i<1000000) && ( j>0 && j <1000000)){
    maior=-1;
  for(n=j;n>=i;n--){
    aux=n;
    cont=1;
  while(aux != 1){

    if(aux%2==0){
      aux=(aux/2);
    }else aux=((aux*3)+1);
    cont++;
  }//fim do while
    
    if(cont>maior)
      maior=cont;
    }
  printf("%d %d %d\n",i,j,maior);
    scanf("%d %d",&i,&j);
    }
    return 0;
}