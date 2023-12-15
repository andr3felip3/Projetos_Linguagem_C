#include<cstdio>
#include<iostream>
using namespace std;

#define MAX 4

void criaPalavra1(char *palavra, int indice){
	for (int i='a'; i<='z';i++){
		palavra[indice] = i;					
		for (int j='a'; j<='z';j++){
			palavra[indice+1] = j;
			for (int k='a'; k<='z';k++){
				palavra[indice+2] = k;
				for (int l='a'; l<='z';l++){
					palavra[indice+3] = l;					
					printf("%s\n", palavra);
				}								
			}			
		}	
		
	}

}

void criaPalavra(char *p, int i){
	
	if (i == MAX){
		printf("%s", p);		
	}else{
		for (char letra = 'a'; letra <= 'z'; letra++){
			p[i] = letra;
			criaPalavra(p, i+1);						
		}		
	}	
}

int main(){
	
	char palavra[MAX+1];
	palavra[MAX+1] = '\0';
	
	criaPalavra(palavra, 0);
		
	return 0;
}
