#include <iostream>
#include<stdio.h>
int main() {
	float troco;
	int quant;
	int moeda[10];
	int cont=0;
	
	
	// Entrada
	

	scanf("%f",&troco);
	

	scanf("%d",&quant);
	
	for(int i=0;i<quant;i++){

	scanf("%d",&moeda[i]);	
}
 
   // Calcula troco
   for(int i=0;i<quant;i++){
  if(troco>=moeda[i]){
  
	troco=troco-moeda[i];
      printf("%d ",moeda[i]);
	  i=0;
	  cont++;   
}
}
 printf("\n%d",cont);
  

	
	return 0;
}
