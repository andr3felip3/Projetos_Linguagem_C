// Programa em C //
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define n 4

int main(){

// Lista de preferencia
int listPref[2*n][n] = { 
	    {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };

// Vetores de relacionamento
 int mulher[n]; // mulheres querendo casar
 int homem[n];  // homens disponiveis
 
// Tornado eles solteiros (0:solteiro   1:casado) 
 for(int v=0;v<n;v++){
 mulher[v]=0;  
 homem[v]=0; 
 }
 
 int cont=0;  //contador (casais sendo formados)
 
 int i;   //percorrer no vetor homem

 // Estabelecer o casamento 
 while(cont<n){
   
 for(i=0;i<n;i++)
    if(homem[i]==0)
      break;
      
 int j; // percorrer na coluna da lista de preferencia
  
 for(j=0;j<n && homem[i]==0;j++){ // seleciona uma linha e anda pelas colunas da lista de preferencia 
  
   int k= listPref[i][j];
  
  if(mulher[k-n]==0){     // Se a mulher esta solteira
   mulher[k-n]=i;  //relaciona mulher com marido(i) 
   homem[i]=1;  //casou
   cont++;
  }
  
  else{ // Se a mulher ta casada, verifica se ela quer trocar
  
  int p=mulher[k-n]; // marido(p) atual
  
     for(int r=0;r<n;r++){
     
      //caso marido(p) vem antes do marido(i), nao faz nada pq ja tavam casado
       
      //senao troca os maridos, ja que o marido(i) vem antes do marido(p) na lista de preferencia.  
	  if(listPref[k][r]!=p){
      break;
      mulher[k-n]=i;
      homem[i]=1;
      homem[p]=0;
                } // fim-if
            
            }//fim-for
    
        }//fim-else
        
        
  
     }//fim-for
   
 }//fim-while
 
 // Exibe casamento estavel
 int q;
 printf("mulher homem\n");
for(int s=0;s<n;s++){ 
q=s+n;
   printf(" %d %d\n",q,mulher[s]);
}

    return 0;
} //fim-main

