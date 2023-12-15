
/*UNIVERSIDADE FEDERAL DE RONDONIA - DACC/UNIR
NOME: André felipe costa da silva
DATA: 16/06/2022
COMPILADOR: Dev c++
SISTEMA OPERACIONAL: Windows 
*/
#include <stdio.h>
#include <map>
#include <queue>
#include <vector>
using namespace std;

//procura uma posicao vazia para o vetEstado
int disponivel(vector<int> vetEstado, int dispo){ 
	for (int i = 0; i < (int)vetEstado.size(); i++)
    //verifica se posicao tabuleiro esta vazio
		if (vetEstado[i] == dispo)
			// retorna essa posicao
      return (i);
	return -1;
}

// calcula os movimentos para alcançar o valor da distancia
int heurist(vector<int> vetEstado, vector<int> desejado) {
	int distan = 0;
	for (int i = 0; i < (int)vetEstado.size(); i++) {
		distan+=desejado[i] != vetEstado[i];
	}
	return distan;
}


void move(vector<int> vetAux, int &nEstados, vector<int> vetEstado[4]){
    int pos,i,j,aux;
  // busca a posicao do zero 
	pos = disponivel(vetAux, 0); 
	i = pos/3;  
	j = pos%3;
	
	vetEstado[0] = vetEstado[1] = vetEstado[2] = vetEstado[3] = vetAux;
	
	if (i== 0 && j == 0){
		nEstados = 2;
		//1
		aux=vetEstado[0][i*3+j];
		vetEstado[0][i*3+j]=vetEstado[0][i*3+j+1];
		vetEstado[0][i*3+j+1]=aux;
		//2
		aux=vetEstado[1][i*3+j];
		vetEstado[1][i*3+j]=vetEstado[1][(i+1)*3+j];
		vetEstado[1][(i+1)*3+j]=aux;
		
  } else if (i == 0 && j == 2){
		nEstados = 2;
		//1
		aux=vetEstado[0][i*3+j];
		vetEstado[0][i*3+j]=vetEstado[0][i*3+j-1];
		vetEstado[0][i*3+j-1]=aux;
		
		//2
		aux=vetEstado[1][i*3+j];
		vetEstado[1][i*3+j]=vetEstado[1][(i+1)*3+j];
		vetEstado[1][(i+1)*3+j]=aux;
		
		
 } else if (i == 2 && j == 0){
		nEstados = 2;
				
		//1
		aux=vetEstado[0][i*3+j];
		vetEstado[0][i*3+j]=vetEstado[0][i*3+j+1];
		vetEstado[0][i*3+j+1]=aux;
		
		//2
		aux=vetEstado[1][i*3+j];
		vetEstado[1][i*3+j]=vetEstado[1][(i-1)*3+j];
		vetEstado[1][(i-1)*3+j]=aux;
		
 } else if (i == 2 && j == 2){
		nEstados = 2;
		//1
		aux=vetEstado[0][i*3+j];
		vetEstado[0][i*3+j]=vetEstado[0][i*3+j-1];
		vetEstado[0][i*3+j-1]=aux;
		
		//2
		aux=vetEstado[1][i*3+j];
		vetEstado[1][i*3+j]=vetEstado[1][(i-1)*3+j];
		vetEstado[1][(i-1)*3+j]=aux;
		
 } else if(i == 0 && j == 1){
		nEstados = 3;
	
		//1
		aux=vetEstado[0][i*3+j];
		vetEstado[0][i*3+j]=vetEstado[0][i*3+j-1];
		vetEstado[0][i*3+j-1]=aux;
		
		//2
		aux=vetEstado[1][i*3+j];
		vetEstado[1][i*3+j]=vetEstado[1][i*3+j+1];
		vetEstado[1][i*3+j+1]=aux;
		
		//3
		aux=vetEstado[2][i*3+j];
		vetEstado[2][i*3+j]=vetEstado[2][(i+1)*3+j];
		vetEstado[2][(i+1)*3+j]=aux;
			
 } else if(i == 2 && j == 1){
		nEstados = 3;
		
		//1
		aux=vetEstado[0][i*3+j];
		vetEstado[0][i*3+j]=vetEstado[0][i*3+j-1];
		vetEstado[0][i*3+j-1]=aux;
		
		//2
		aux=vetEstado[1][i*3+j];
		vetEstado[1][i*3+j]=vetEstado[1][i*3+j+1];
		vetEstado[1][i*3+j+1]=aux;
		
		//3
		aux=vetEstado[2][i*3+j];
		vetEstado[2][i*3+j]=vetEstado[2][(i-1)*3+j];
		vetEstado[2][(i-1)*3+j]=aux;
		
		
 } else if(i == 1 && j == 0){
		nEstados = 3;
	
		//1
		aux=vetEstado[0][i*3+j];
		vetEstado[0][i*3+j]=vetEstado[0][i*3+j+1];
		vetEstado[0][i*3+j+1]=aux;
		
		//2
		aux=vetEstado[1][i*3+j];
		vetEstado[1][i*3+j]=vetEstado[1][(i-1)*3+j];
		vetEstado[1][(i-1)*3+j]=aux;
		
		//3
		aux=vetEstado[2][i*3+j];
		vetEstado[2][i*3+j]= vetEstado[2][(i+1)*3+j];
		 vetEstado[2][(i+1)*3+j]=aux;
		
 } else if(i == 1 && j == 2){
		nEstados = 3;
		
		//1
		aux=vetEstado[0][i*3+j];
		vetEstado[0][i*3+j]=vetEstado[0][i*3+j-1];
		vetEstado[0][i*3+j-1]=aux;
		//2
		aux=vetEstado[1][i*3+j];
		vetEstado[1][i*3+j]=vetEstado[1][(i-1)*3+j];
		vetEstado[1][(i-1)*3+j]=aux;
		
		//3
		aux=vetEstado[2][i*3+j];
		vetEstado[2][i*3+j]=vetEstado[2][(i+1)*3+j];
		vetEstado[2][(i+1)*3+j]=aux;
		
	                } 
  else {  // 
		nEstados = 4;
		
		//1
		aux=vetEstado[0][i*3+j];
		vetEstado[0][i*3+j]=vetEstado[0][i*3+j-1];
		vetEstado[0][i*3+j-1]=aux;
		
		//2
		aux=vetEstado[1][i*3+j];
		vetEstado[1][i*3+j]=vetEstado[1][i*3+j+1];
		vetEstado[1][i*3+j+1]=aux;
		
		//3
		aux=vetEstado[2][i*3+j];
		vetEstado[2][i*3+j]= vetEstado[2][(i-1)*3+j];
		 vetEstado[2][(i-1)*3+j]=aux;
		
		//4
		aux=vetEstado[3][i*3+j];
		vetEstado[3][i*3+j]= vetEstado[3][(i+1)*3+j];
		 vetEstado[3][(i+1)*3+j]=aux;
		
	   }
}

// verifica se vetAux = desejado
int equal(vector<int> vetAux, vector<int> desejado){
  int i;
  // percorre pra veficicar se eh diferente
	for (i=0; i< 9; i++)
    // se for verdade retorna 0
		if (vetAux[i] != desejado[i]) 
			return 0; 
  
	return 1;
}


int bfs(vector<int>inicial,vector<int>desejado){
	int nEstados;
	int menor;       
	int profund;
	int cont=0;
	int pq;
  
  //estado selecionado
	vector<int>vetEstado[6];
  
  //vetor a ser manipulado
	vector<int> vetAux; 
  
  //fila de prioridades
	priority_queue<pair<int , vector<int> > >  prioridades; 
  
	//estrutura de dados
  map<vector<int>, int> visitas;  

  //inicia com a profundidade 0 e o vetor inicial
	prioridades.push(make_pair(0, inicial));  

  //classifica como visitado, onde o nivel inicial eh 0
	visitas[inicial] = 0; 
	
	while(!prioridades.empty()) {
     //pega o vetor auxiliar
	vetAux = prioridades.top().second;
    menor = prioridades.top().first;
	prioridades.pop();
    
    //acesso a profundidade pelo mapa de visitados
	profund = visitas[vetAux]; 
    
	if(prioridades.top().first < menor || prioridades.top().first == 0){
     for(int i=0;i<9;i++){
    cont++;
    printf("%d ",vetAux[i]);
    if(cont == 3){
        printf("\n");
        cont=0;
    }
  }
      if(vetAux != desejado) printf("\n");
    } 
    //se for verdade retorna valor
		if (equal(vetAux, desejado)) 
			return profund; 
    
		move(vetAux, nEstados, vetEstado);
		
		for (int i=0; i<nEstados; i++)
			if (!visitas.count(vetEstado[i])){
				visitas[vetEstado[i]] = profund +1;
				pq = (profund+1) + heurist(vetEstado[i],desejado);
        
         // para poder inserir o menor no inicio da fila de prioridade necessario deixar ele negativo
        prioridades.push(make_pair(-pq, vetEstado[i]));
			}
	}
	return -1;
}

int main() {
  //dados
	vector<int>inicial;
	vector<int>desejado;
    int vetInicial,vetDesejado;
  
  // entrada estado inical
  for (int i = 0; i < 9; i++) {
      scanf("%d", &vetInicial);
      inicial.push_back(vetInicial);
     
  }
  // entrada estado desejado
  for (int i = 0; i < 9; i++) {
      scanf("%d", &vetDesejado);
      desejado.push_back(vetDesejado);
  }
  // exibe 
  	printf("#Movimentos: %d", bfs(inicial,desejado));
	return 0;
}