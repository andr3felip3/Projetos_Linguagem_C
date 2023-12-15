#include <stdio.h>
#include <conio.h>
#define TF 8
struct registro{
    char status; // L-livre ou O-ocupado ou R-removido
	int  chave;
};
void criar(struct registro p[TF]){
	 int i;
    for (i=0; i<TF; i++){
        p[i].status= 'L';
        p[i].chave=0;
    }
    printf("\n tabela Hash enderecamento aberto (tentativa linear) criada");
}
int Hash(int chave){
	int ender = chave % TF;
	return ender;
}
void inserir (struct registro p[TF]){
	int chave, ender;
	printf("\nDigite a chave:");
	scanf("%d",&chave);
	ender = Hash(chave);
	if (p[ender].status=='L'){
		p[ender].chave=chave;
		p[ender].status='O';
	}
	else {
		int i=0;
        while (i<TF && p[(ender+i)%TF].status != 'L') 
		   	    i = i+1; // i++;
    	if (i<TF){
    		 p[(ender+i)%TF].chave = chave;
	         p[(ender+i)%TF].status = 'O';
		} else printf("tabela cheia!"); 		       
	}//else
}//inserir
void mostrar_hash(struct registro p[TF]){
	int i;
	while (i < TF){
		printf("\n Chave[%d]:%d  Status:%c",i,p[i].chave,p[i].status);
		i++;
	}
}
int buscar(int chaveprocurada, struct registro p[TF]){
	int i=0;
	int ender = Hash(chaveprocurada);
	while (i<TF && p[(ender+i)%TF].status != 'L' &&  p[(ender+i)%TF].chave != chaveprocurada)
	     i = i + 1;
	
	if (p[(ender+i)%TF].chave == chaveprocurada)
         return (ender+i)%TF;
		 else
		 return TF; // não encontrou	  
}
void remover(struct registro p[TF]){
	int ender, chave;
	printf ("Digite a chave a ser removida: ");
    scanf ("%d", &chave);
    ender = buscar(chave,p);
    if (ender < TF){
       p[ender].status='R';
       printf("removeu com sucesso %d",chave);
	   } else
	   printf("chave nao encontrada na tabela");
}

main() {
	registro p[TF]; // tabela p tem posicoes de 0 até 7
    criar(p);
    int opcao=0;
    while (opcao!=4){
        printf ("\n");
		printf("\n1 - Inserir Chave");
        printf ("\n2 - Mostrar tabela Hashing");
        printf ("\n3 - Remover chave");
        printf ("\n4 - Sair");
        printf ("\nOpcao?: ");
        scanf ("%d", &opcao);
        switch (opcao){
        case 1:
            inserir(p);
            break;
        case 2:
        	mostrar_hash(p);
            break;
        case 3:
		    remover(p);
            break;
        }
    }
}
