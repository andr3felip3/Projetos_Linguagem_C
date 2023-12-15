#include <stdio.h>
#include <conio.h>
#include <string.h>
#define TF 20
struct registro{
    char status; // L-livre ou O-ocupado ou R-removido
	char nome[10];
	int dia;
	int mes;
};
void criar(struct registro tab[TF]){
	int i;
	for (i=0;i<TF;i++){
	    tab[i].status='L';
		strcpy(tab[i].nome," ");
		tab[i].mes=0;
		tab[i].dia=0;	
	}
    printf("\n tabela Hash enderec.aberto (tentativa linear) criada");
}
int Hash(int mes){
	int ender = mes % TF;
	return ender;
}
void exibirTodos(struct registro tab[TF]){//opcao 6
   int i;
   for (i=0;i<TF;i++)
      printf("\n linha:%d status:%c nome:%s   dia:%d   mes:%d",i,tab[i].status,
	                                                tab[i].nome,tab[i].dia,tab[i].mes);
   printf("\n");	                                                
}
void consultaMes(struct registro tab[TF],int mes){//opcao 2
     int atual;
     int ender = Hash(mes);
     if (tab[ender].status=='O')printf("\nlinha:%d status:%c nome:%s   dia:%d   mes:%d",ender,tab[ender].status,
	                                                   tab[ender].nome,tab[ender].dia,tab[ender].mes);
	 atual=ender+1;                                                  
     while (atual!=ender){
     	if ((tab[atual].status='O'&&tab[atual].mes==mes))
     	    printf("\nlinha:%d status:%c nome:%s   dia:%d   mes:%d",atual,tab[atual].status,
	                                                   tab[atual].nome,tab[atual].dia,tab[atual].mes);
	        if (atual<TF)
			     atual++;
				 else atual=0;                                           
	 }
	 printf("\n acabou");
         
}
void consultaMaioresIdade(struct registro tab[TF]){//opcao 3
   printf("\n Precisa do ano na estrutura do registro do meu amigo");
   printf("\n se não declarar e ler o ano de aniversario não consegue calcular a idade");
}
void inserir(struct registro tab[TF]){// opcao 1
     registro reg;
     printf("\nEntre com nome do amigo a inserir:");
     fflush(stdin);
     gets(reg.nome);
     printf("\nEntre com dia do aniversario:");scanf("%d",&reg.dia);
     printf("\nEntre com mes do aniversario:");scanf("%d",&reg.mes);
     int ender = Hash(reg.mes);
     if (tab[ender].status=='L'){
     	reg.status='O';
     	tab[ender]=reg;
     	printf("\n inseriu sem colisao no ender correto %d   nome%s",ender,reg.nome);
	 } 
	 else { // colisao
	 	int atual = ender+1;
	 	while ((atual!=ender)&&(tab[atual].status!='L'))//procura uma posicao livre na tabela
               if (atual <TF)	
			        atual++;
					else atual=0;
		if (atual==TF)			
			printf("\n tabela cheia - nao inseriu seu amigo %s",reg.nome);
			else {
				reg.status='O';
				tab[atual]= reg;
				printf("\nInseriu apos colisao no ender %d o nome %s",atual,reg.nome);
			}		 	
	 }// fecha else do if da colisao
}//fehca funcao inserir
void excluirUm(struct registro tab[TF]){// opcao 4
    char nome[10];
	printf("\n Entre com o nome do amigo a ser removido:");
	fflush(stdin);
	gets(nome);
	int i;
	for (i=0;i<TF;i++){
		if (strcmp(nome, tab[i].nome)==0){ 
		       tab[i].status = 'R';
		       printf("\n Amigo removido na linha %d  nome%s",i,nome);
		}
	}
}
void excluirMes(struct registro tab[TF],int mes) {//opcao 5 
    int ender, atual;
    ender = Hash(mes);
    if ((tab[ender].mes==mes)&&(tab[ender].status='O')){
    	tab[ender].status='R';
    	printf("\nremoveu a linha %d  nome%s do mes%d",ender,tab[ender].nome,mes);
	}
	atual=ender+1;
	while ((atual!=ender)&&(tab[atual].status!='R')){
          if ((tab[atual].status=='O')&&(tab[atual].mes==mes)){
          	tab[atual].status='R';
    	    printf("\nremoveu a linha %d  nome%s do mes%d",atual,tab[atual].nome,mes);
		  }    
		  if (atual<TF)
		     atual++;
		     else atual=0;
	}
	printf("\n removeu todos com o mes %d",mes);
}
main(){
	int opcao=0; int mes;
	struct registro tab[TF];
	criar(tab);
	while (opcao!=7){
		printf("\n1 - Inserir Amigo (nome,dia,mes)");
        printf ("\n2 - Consultar aniversariantes do mes");
        printf ("\n3 - Contar maiores de idade 18 anos");
        printf("\n4 - Excluir uma pessoa pelo nome");
        printf ("\n5 - Excluir pessoas de um determinado mes");
        printf ("\n6 - EXIBIR TODOS");
        printf ("\n7 - Sair");
        printf ("\nOpcao?: ");
        scanf ("%d", &opcao);
        switch (opcao){
        case 1:
            inserir(tab);
            break;
        case 2:
        	printf("\nEntre com mes de consulta:");scanf("%d",&mes);
        	consultaMes(tab,mes);
            break;
        case 3:
		    consultaMaioresIdade(tab);
            break;
        case 4:
            excluirUm(tab);
            break;
        case 5:
        	printf("\nEntre com mes de exclusao:");scanf("%d",&mes);
        	excluirMes(tab,mes);
            break;
        case 6:
		    exibirTodos(tab);
            break;
        }
        
	}
}
