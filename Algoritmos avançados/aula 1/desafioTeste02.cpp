/*                               1
#include <stdio.h>
#define MAX 100

int main(void) {
  int m,n,x=0, i,j;
  char matriz[MAX][MAX];
  scanf("%d %d",&n,&m);
  printf("\n\n");
  //roda enquanto tiver entre essa condição
  while((n>0) && (m<100)){
  
  //entrada
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      scanf("%s",&matriz[i][j]);
    }
    printf("\n");
  }
    x=x+1;
 // saida do programa
    printf("Campo #%d:\n",x);
    for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      //if()
      printf("%c", matriz[i][j]);
    }
    printf("\n");
  }
    scanf("%d %d",&n,&m);
    }
  
  return 0;
}

*/

                                  //2
#include<stdio.h>
#include<stdlib.h>

int main(){
 int n,m,cont=0;
 char CAMP[8][8];
 int i,j,x=1;
 int k;
 printf("\t\t**Desafio 2**\n\n");
 
 printf("Entre com o valor de n (linhas do campo): ");
 scanf("%d",&n);
 printf("Entre com o valor de m (colunas do campo: ");
 scanf("%d",&m);
 cont=0;
 // Entrada //

 while((n!=0) && (m!=0)&&(x<100)){
  printf("\n\tMATRIZ:%d X %d",n,m);
   for(i=0;i<m;i++){
     for(j=0;j<n;j++){
      printf("\nDefina o quadrado[%d][%d] (. = Livre | * = Mina) : ",i,j);
      scanf("%s",&CAMP[i][j]);
      getchar();

    }
   }
   
   //Exibe caracteres//
   printf("\n\tMATRIZ %d X %d\n",n,m);
  for(i=0;i<m;i++){
     for(j=0;j<n;j++){
    printf("%c",CAMP[i][j]);
  
     } printf("\n");
  }
  // Exibe numeros 
  printf("\n\n");
  printf("\tCAMPO #%d\n",x);
  
    for(i=0;i<m;i++){
     for(j=0;j<n;j++){
   // calculo
   for(k=j;k<n;k++){
   
     if(CAMP[k][j]=='*'){
        cont++;
        /// na frente
     	if(CAMP[k][j+1]!='*'){
     	
		  if (CAMP[k][j+1]=='.'){
		  		
     		CAMP[k][j+1]=cont+'0';
		 }
		   else if(CAMP[k][j+1]!='.'){
		   	cont++;
     		CAMP[k][j+1]=cont+'0';
		   }
		   cont=0;
	   }
	   
	   else {
	   	if (CAMP[k][j+1]=='.'){
	   		
     		CAMP[k][j+1]=cont+'0';
		 }
		   else if(CAMP[k][j+1]!='.'){
		 	
     		CAMP[k][j+1]=cont+'0';
		   }
	   }
      /// atras (incompl
      	if(CAMP[k][j-1]!='*'){
     	
		  if (CAMP[k][j-1]=='.'){
		  		
     		CAMP[k][j-1]=cont+'0';
		 }
		   else if(CAMP[k][j-1]!='.'){
		   	cont++;
     		CAMP[k][j-1]=cont+'0';
		   }
		   cont=0;
	   }
	   
	   else {
	   	if (CAMP[k][j-1]=='.'){
	   		
     		CAMP[k][j-1]=cont+'0';
		 }
		   else if(CAMP[k][j-1]!='.'){
		 	
     		CAMP[k][j-1]=cont+'0';
		   }
	   }
   ///// embaixo (incompl
   	if(CAMP[k+1][j]!='*'){
     	
		  if (CAMP[k+1][j]=='.'){
		  		
     		CAMP[k+1][j]=cont+'0';
		 }
		   else if(CAMP[k+1][j]!='.'){
		   	cont++;
     		CAMP[k+1][j]=cont+'0';
		   }
		   cont=0;
	   }
	   
	   else {
	   	if (CAMP[k+1][j]=='.'){
	   		
     		CAMP[k+1][j]=cont+'0';
		 }
		   else if(CAMP[k+1][j]!='.'){
		 	
     		CAMP[k+1][j]=cont+'0';
		   }
	   }
   
   //// em cima (incompl
   	if(CAMP[k-1][j]!='*'){
     	
		  if (CAMP[k-1][j]=='.'){
		  		
     		CAMP[k-1][j]=cont+'0';
		 }
		   else if(CAMP[k-1][j]!='.'){
		   	cont++;
     		CAMP[k-1][j]=cont+'0';
		   }
		   cont=0;
	   }
	   
	   else {
	   	if (CAMP[k-1][j]=='.'){
	   		
     		CAMP[k-1][j]=cont+'0';
		 }
		   else if(CAMP[k-1][j]!='.'){
		 	
     		CAMP[k-1][j]=cont+'0';
		   }
	   }
   ///diagonal direita-cima (incompl
   	if(CAMP[k-1][j+1]!='*'){
     	
		  if (CAMP[k-1][j+1]=='.'){
		  		
     		CAMP[k-1][j+1]=cont+'0';
		 }
		   else if(CAMP[k-1][j+1]!='.'){
		   	cont++;
     		CAMP[k-1][j+1]=cont+'0';
		   }
		   cont=0;
	   }
	   
	   else {
	   	if (CAMP[k-1][j+1]=='.'){
	   		
     		CAMP[k-1][j+1]=cont+'0';
		 }
		   else if(CAMP[k-1][j+1]!='.'){
		 	
     		CAMP[k-1][j+1]=cont+'0';
		   }
	   }
   /// diagonal esquerda-cima (incompl
   	if(CAMP[k-1][j-1]!='*'){
     	
		  if (CAMP[k-1][j-1]=='.'){
		  		
     		CAMP[k-1][j-1]=cont+'0';
		 }
		   else if(CAMP[k-1][j-1]!='.'){
		   	cont++;
     		CAMP[k-1][j-1]=cont+'0';
		   }
		   cont=0;
	   }
	   
	   else {
	   	if (CAMP[k-1][j-1]=='.'){
	   		
     		CAMP[k-1][j-1]=cont+'0';
		 }
		   else if(CAMP[k-1][j-1]!='.'){
		 	
     		CAMP[k-1][j-1]=cont+'0';
		   }
	   }
   /// diagonal direita-baixo (incomp
   	if(CAMP[k+1][j+1]!='*'){
     	
		  if (CAMP[k+1][j+1]=='.'){
		  		
     		CAMP[k+1][j+1]=cont+'0';
		 }
		   else if(CAMP[k+1][j+1]!='.'){
		   	cont++;
     		CAMP[k+1][j+1]=cont+'0';
		   }
		   cont=0;
	   }
	   
	   else {
	   	if (CAMP[k+1][j+1]=='.'){
	   		
     		CAMP[k+1][j+1]=cont+'0';
		 }
		   else if(CAMP[k+1][j+1]!='.'){
		 	
     		CAMP[k+1][j+1]=cont+'0';
		   }
	   }
   /// diagonal esquerda-baixo (incompl
   	if(CAMP[k+1][j-1]!='*'){
     	
		  if (CAMP[k+1][j-1]=='.'){
		  		
     		CAMP[k+1][j-1]=cont+'0';
		 }
		   else if(CAMP[k+1][j-1]!='.'){
		   	cont++;
     		CAMP[k+1][j-1]=cont+'0';
		   }
		   cont=0;
	   }
	   
	   else {
	   	if (CAMP[k+1][j-1]=='.'){
	   		
     		CAMP[k+1][j-1]=cont+'0';
		 }
		   else if(CAMP[k+1][j-1]!='.'){
		 	
     		CAMP[k+1][j-1]=cont+'0';
		   }
	   }
      
     }
     
     else if(CAMP[k][j]=='.'){
     		CAMP[k][j]=cont+'0';
     		  		
		 }
	
     
    
   }
   
   printf("%c",CAMP[i][j]);
   }
   printf("\n");
}

 
 printf("\nEntre com o valor de n (linhas do campo): ");
 scanf("%d",&n);
 printf("Entre com o valor de m (colunas do campo: ");
 scanf("%d",&m);
x++;
  }
  

 
 
  return 0;
} 


/*                                          3
#include <stdio.h>
#define MAX 100



int main(void) {
  int m=0,n=0,x=0, i=0,j=0,cont=0;
  char matriz[MAX][MAX];

  //int mnm[MAX][MAX];
  scanf("%d %d",&n,&m);
  printf("\n\n");
  //roda enquanto tiver entre essa condição
  for(i=1;i<=n;i++){
      for(j=1;j<=m;j++){
        matriz[i][j] = '*';
        }
    }
  while((n>0) && (m<100)){

  //entrada
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      scanf("%s",&matriz[i][j]);
      fflush(stdin);
    }
    printf("\n");
  }
    x=x+1;
 // saida do programa
    printf("Campo #%d:\n",x);
    for(i=1;i<=n;i++){
      for(j=1;j<=m;j++){
        if(matriz[i][j]=='*'){
        cont++;
        //quando vai na primeira casa
          if(matriz[1][1]){
            matriz[i][j+1] = cont+'0';
            matriz[i+1][j] = cont+'0';
            matriz[i+1][j+1] = cont+'0';
          }

          // quando * ultima casa
          if(matriz[n][m]){
            matriz[n-1][m] = cont+'0';
            matriz[n][m-1] = cont+'0';
            matriz[n-1][m-1] = cont+'0';
            }
          // quando * primeira linha ultima col
          if(matriz[1][m]){
            matriz[i+1][j-1]=cont+'0';
            matriz[i][j-1]=cont+'0';
            matriz[i+1][j]=cont+'0';
          }

      }
      else if (matriz[i][j] == '.'){
        matriz[i][j] = '0';
      }
      printf("%c", matriz[i][j]);
    }
    printf("\n");
  }
    cont=0;
    scanf("%d %d",&n,&m);

    }

  return 0;
}
*/
