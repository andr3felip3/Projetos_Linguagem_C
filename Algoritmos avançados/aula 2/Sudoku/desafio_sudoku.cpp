#include <cstdio>
#include <set>
#define TAM 9

using namespace std;

int verificarLinhas(int matriz[TAM][TAM]){
    set<int> c;

    for(int i = 0; i < TAM; i ++){
        for(int j = 0; j < TAM; j++){
            c.insert(matriz[i][j]);
        }
        if(c.size() != 9) {
            c.clear();
            return 0;
        }
        c.clear();
    }

    return 1;
}

int verificarColunas(int matriz[TAM][TAM]){
    set<int> c;

    for(int i = 0; i < TAM; i ++){
        for(int j = 0; j < TAM; j++){
            c.insert(matriz[j][i]);
        }
        if(c.size() != 9) {
            c.clear();
            return 0;
        }
        c.clear();
    }

    return 1;
}

int main(){
    int n;  // Numero de tabuleiros
    int tabuleiro[TAM][TAM];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Instancia %d\n", i + 1);
        for(int k = 0; k < TAM; k++){
            for(int m = 0; m < TAM; m++){
                scanf("%d", &tabuleiro[k][m]);
            }   
        }

        int linhasValidas = verificarLinhas(tabuleiro);

        if(!linhasValidas) {
            printf("NAO\n");
            continue;
        }

        int colunasValidas = verificarColunas(tabuleiro);

        if(!colunasValidas) {
            printf("NAO\n");
            continue;
        }

        printf("SIM\n");

        if(i != n - 1) printf("\n");
    }
}