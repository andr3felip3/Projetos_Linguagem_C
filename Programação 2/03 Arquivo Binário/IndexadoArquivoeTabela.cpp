#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>

struct funcionario{
	int matricula;
	char nome[10];
	char depto[15];
	float salario;
};
struct partab{
	int chave;
	int posicao;
};

void leTecladoGravaArq(){
    funcionario f;
	FILE *arquivo = fopen("Funcionarios.dat","ab");// adiciono novo funcionario no final
	if (arquivo==NULL) // pergunto se o arquivo existe
	   FILE *arquivo = fopen("Funcionarios.dat","wb"); // cria o arquivo se ele não existir e permite gravacao fwrite
	printf("\nEntre com a matricula:"); scanf("%d",&f.matricula);
	printf("\nEntre com o nome.....:");fflush(stdin); gets(f.nome);
	printf("\nEntre com o depto....:");fflush(stdin); gets(f.depto);
	printf("\nEntre com o salario..:");scanf("%f",&f.salario);
	fwrite(&f, sizeof(funcionario),1, arquivo);
	printf("\n sucesso ao gravar o novo funcionario f %s",f.nome);
	fclose(arquivo);
}
void exibeArquivoDesord(){
	funcionario f;
	int posicao=0;
	FILE *arquivo = fopen("Funcionarios.dat","rb");
	if (arquivo==NULL)
	   printf("\n Arquivo nao existe");
	   else {
	   	   fread(&f,sizeof(funcionario),1,arquivo);
	   	   while (!feof(arquivo)){
	   	   	     printf("\nPosicao %d  Matricula%d  Nome%s  Depto%s  Salario %5.2f",
					     posicao, f.matricula,f.nome, f.depto,f.salario);
				 posicao++;
				 fread(&f,sizeof(funcionario),1,arquivo);	     
			  }
		   fclose(arquivo);	  
	   }
}
void criaIndice(struct partab vetIndice[], int &tl){// opcao 3 do menu para criar a tabela de indice
    funcionario f;
    partab par;
    int posicao=0;
    FILE *arquivo = fopen("Funcionarios.dat","rb");
    if (arquivo==NULL)
        printf("\n Arquivo Funcionarios.dat inexistente");
        else {
           fread(&f,sizeof(funcionario),1,arquivo);
		   while (!feof(arquivo)){
		   	     par.chave = f.matricula;
				 par.posicao=posicao;
				 vetIndice[posicao]= par;	  
		   	     posicao++;
		   	     fread(&f,sizeof(funcionario),1,arquivo);
		   }	
		   fclose(arquivo);
		   printf("\n Tabela de Indice vetIndice foi criada mas esta desordenada");
		   // a tabela de indice foi criado, no entanto ela esta desordenada
		   int i, tam;
           tam=posicao;
           while (tam>1)  {
              for (i=0;i<tam;i++)  {
                 if(vetIndice[i].chave>vetIndice[i+1].chave)   {
                     partab aux=vetIndice[i];
                     vetIndice[i]=vetIndice[i+1];
                     vetIndice[i+1]=aux;
                 }
              }   //for do i
              tam=tam-1;
           } // while do tam
           // ordenou a tabela de indice pela Bolha.(vetIndice)
           printf("\n Tabela de Indice vetIndice foi ordenada");
           tl = posicao;
		}
}
void exibeIndiceArquivo(struct partab vetIndice[], int tl){//opcao 4 do menu para exibir a tabela e o arquivo de dados
      funcionario f;
      int posicao=0;
      FILE *arquivo = fopen("Funcionarios.dat","rb");
      if (arquivo==NULL)
        printf("\nArquivo inexistente");
        else {
           printf("\n vetIndice            Arquivo Binario Funcionarios.dat");	
           fread(&f,sizeof(funcionario),1,arquivo);
		   while (!feof(arquivo)){
		   	   printf("\nCHAVE:%d Posicao:%d         Matricula:%d Nome:%s Depto:%s Salario:%5.2f",
				         vetIndice[posicao].chave, vetIndice[posicao].posicao,
						 f.matricula,f.nome,f.depto,f.salario);
			   posicao++;
			   fread(&f,sizeof(funcionario),1,arquivo);			 
		   }	
		   fclose(arquivo);
		}
}
void relatorioOrdenado(struct partab vetIndice[], int tl){
	funcionario f;
	int posicao,i;
	FILE *arquivo = fopen("Funcionarios.dat","rb");
	if (arquivo==NULL)
	  printf("\nArquivo Inexistente");
	  else {
	  	// relatorio ordenado
	  	printf("\nRelatorio Ordenado pela Matricula");
	  	for (i=0;i<tl;i++){
	  		posicao = vetIndice[i].posicao;
	  		fseek(arquivo,posicao*sizeof(funcionario),SEEK_SET);
	  		fread(&f,sizeof(funcionario),1,arquivo);
	  		printf("\nPosicao %d  Matricula%d  Nome%s  Depto%s  Salario %5.2f",
					     posicao, f.matricula,f.nome, f.depto,f.salario);
		}
	  	fclose(arquivo);
	  }
}
int buscaBinaria(struct partab vetIndice[], int tl, int matricula){
	int inicio, fim, meio;
	inicio=0;
	fim=tl-1;
	meio=(inicio+fim)/2;
	while ((matricula != vetIndice[meio].chave)&& (inicio<fim)){
	     if (matricula > vetIndice[meio].chave)
	           inicio=meio+1;
	           else 
	           fim = meio;
	     meio=(inicio+fim)/2;
	 }
	 if ((meio<tl)&&(matricula == vetIndice[meio].chave))
	     return meio;
	     else return -1;
}
void consultaUm(struct partab vetIndice[], int tl){
	int matricula;
	funcionario f;
	int posicao, posdado;
	printf("\nEntre com a matricula a ser consultada:");
	scanf("%d",&matricula);
	posicao = buscaBinaria(vetIndice, tl, matricula);
	if (posicao==-1)
	   printf("\n Matricula nao existe %d",matricula);
	   else {
	   	   FILE *arquivo = fopen("Funcionarios.dat","rb");
	   	   if (arquivo==NULL)
	   	      printf("\n arquivo inexistente");
	   	      else {
	   	          posdado = vetIndice[posicao].posicao;
	   	          fseek(arquivo,posdado*sizeof(funcionario),SEEK_SET);
	   	          fread(&f,sizeof(funcionario),1,arquivo);
	   	          printf("\nPosicao no arq.dados:%d  Matricula%d  Nome%s  Depto%s  Salario %5.2f",
					     posdado, f.matricula,f.nome, f.depto,f.salario);
				  fclose(arquivo);
			}
	   }
}
main(){
	int opcao=0;
	int tl=0;
	struct partab vetIndice[30];
	while (opcao!=7){
		printf("\n\n1 - le do teclado e grava no final do arquivo Binario funcionario.dat");
		printf("\n2 - Exibe todos funcionarios do arquivo binario desordenado");
		printf("\n3 - Criacao da tabela ordenada vetIndice a partir da leitura do arquivo funcionario.dat");
		printf("\n4 - Exibe a tabela vetIndice e o arquivo de dados funcionario.dat");
		printf("\n5 - Relatorio ordenado pela matriculas mas contendo todas as informacoes do funcionario");
		printf("\n6 - Consulta um funcionario pela Matricula");
		printf("\n7 - Sair");
		printf("\nOpcao?");
		scanf("%d",&opcao);
		switch (opcao){
			case 1: leTecladoGravaArq();
			        break;
			case 2: exibeArquivoDesord();
			        break;
			case 3: criaIndice(vetIndice,tl);
			        break;
			case 4: exibeIndiceArquivo(vetIndice,tl);
			        break;
		    case 5: relatorioOrdenado(vetIndice, tl);
			        break;			
			case 6: consultaUm(vetIndice,tl);
			        break;						        
		}
	}
}
