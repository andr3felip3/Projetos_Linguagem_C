#include<stdio.h> 
#include<string.h> 
#include <conio.h>
#define TF 40 
 
struct requisicao {
	int nroreq;  	
	char nome[20];
	char data[10]; 	
	int codexame; 
 	int crm; 
}; 
 
struct indice {  	
	int codigo; 
 	int posender; 
}; 
 
struct exame{  	
	int codexame;  	
	char descricao[80]; 
 	float preco; 
}; 
 
struct medico{  	
	int crm;  	
	char nome[40]; 
 	char especialidade[20]; 
}; 
void carregaTabelaRequisicao(requisicao TabReq[], int &tlr){  
	 FILE *arq = fopen("requisicao.txt","r");  	
	 int nu,ce,cc;  	
	 char data[10];
	 char nome[20];
	 tlr=0;
 	if (arq==NULL) 
       printf("\n erro. não achou o arquivo texto requisicao.txt"); 
 	   else {  	 	    
 	 	  while (!feof(arq)){  	 	 	    	   
			 fscanf(arq,"%d %s %s %d %d\n",&nu,&data,&nome,&ce,&cc);
 	 	 	 TabReq[tlr].nroreq = nu; 
 	 	 	 TabReq[tlr].codexame = ce;
			 strcpy(TabReq[tlr].data,data);
			 strcpy(TabReq[tlr].nome,nome);			 	 	    	   
			 TabReq[tlr].crm= cc;			 
 	 	 	 tlr++;
			} 
 	 	    fclose(arq);  
 	 	    printf("\n tlr qtdade requisicoes %d",tlr); 
 	 	    int i; 
 	 	    for (i=0;i<tlr;i++){  	 	 	    	     
		       printf("\n i=%d req=%d Data=%s nome=%s codexame=%d  crm=%d ",i,TabReq[i].nroreq,TabReq[i].data,TabReq[i].nome,
			                                       TabReq[i].codexame,TabReq[i].crm);
			}  
 	 	    printf("\n"); 
 	 	} 	 
} 
void exibeExames(){ 
 	 struct exame e; 
     FILE *arq = fopen("exames.bin","rb"); 
 	 printf("\n Exibe os EXAMES NO ARQUIVO (desordenado)"); 	
	  
 	 fread(&e,sizeof(exame),1,arq);  	
 	 while (!feof(arq)){ 
		printf("\n 	Codexame=%d descricao=%s preco=%5.2f",e.codexame,e.descricao,e.preco); 
 	 	fread(&e,sizeof(exame),1,arq); 
 		} 
 	fclose(arq); 
} 
void exibeExamesOrdenados(struct indice vetIndExame[],int tle){
	int i, posender;
	exame e;
	FILE *arq = fopen("exames.bin","rb");
	printf("\n Exibe os EXAMES NO ARQUIVO (ordenado pelo Codigo do Exame)"); 
	for (i=0;i<tle;i++){
		posender = vetIndExame[i].posender;
		fseek(arq,posender*sizeof(exame),SEEK_SET);
		fread(&e,sizeof(exame),1,arq);
		printf("\n CodExame=%d  descricao=%s  preco=%5.2f",e.codexame,e.descricao,e.preco);  
	}
	fclose(arq);
} 
 
void exibeMedicos(){  	
	struct medico m; 
 	FILE *arq = fopen("medicos.bin","rb"); 
 	printf("\n Exibe os MEDICOS NO ARQUIVO (desordenado)"); 
 	fread(&m,sizeof(medico),1,arq);  
 	while (!feof(arq)){   
	 	 printf("\n CRM=%d  nome=%s  Especialidade=%s",m.crm,m.nome,m.especialidade);   
		 fread(&m,sizeof(medico),1,arq); 
 		} 
 	fclose(arq); 
}
void exibeMedicosOrdenados(struct indice vetIndMedico[],int tlm){
	int i, posender;
	medico m;
	FILE *arq = fopen("medicos.bin","rb");
	printf("\n Exibe os MEDICOS NO ARQUIVO (ordenado pelo CRM)"); 
	for (i=0;i<tlm;i++){
		posender = vetIndMedico[i].posender;
		fseek(arq,posender*sizeof(medico),SEEK_SET);
		fread(&m,sizeof(medico),1,arq);
		printf("\n CRM=%d  nome=%s  Especialidade=%s",m.crm,m.nome,m.especialidade);  
	}
	fclose(arq);
}		 
 
void criaArqExames(){ // cria o arquivo binario desordenado
	   FILE *arqnovo = fopen("exames.bin","wb");
	   struct exame e; 
	   printf("\n codigo de exame -0- finaliza\n"); 
	   scanf("%d",&e.codexame); 
	   while(e.codexame!=0){ 	   	
			printf("\n descricao do exame\n");    
			fflush(stdin); gets(e.descricao); 
			    
			printf("\n preco exame\n");     
			scanf("%f",&e.preco);
     		
	    	fwrite(&e, sizeof(exame),1,arqnovo);   	
			printf("\n codigo de exame -0- para finalizar\n");
			scanf("%d",&e.codexame); 
	   }
	 	fclose(arqnovo); 
	 	FILE *arq = fopen("exames.bin","rb"); 
	 	printf("\n Exibe os EXAMES CADASTRADOS NO ARQUIVO");  	
		fread(&e,sizeof(exame),1,arq);  	
		while (!feof(arq)){ 	
	  		printf("\n 	Codexame=%d   Descricao=%s	 preco=R$ %5.2f",e.codexame,e.descricao,e.preco); 
	 	 	fread(&e,sizeof(exame),1,arq); 
	 	} 
	 	fclose(arq);
		 printf("\n"); 
} 
void criaArqMedicos(){ // desordenado
 	 FILE *arqnovo = fopen("medicos.bin","wb");  	
	 medico m;  	
	 printf("\n crm do medico -0- para finalizar\n"); 
 	 scanf("%d",&m.crm);  	
	 while(m.crm!=0){  
	 	 printf("\n nome:");  	                   
		 fflush(stdin); gets(m.nome);
		 printf("\n especialidade:");  	               
		 fflush(stdin); gets(m.especialidade);
		 fwrite(&m, sizeof(medico),1,arqnovo);  	 	
		 printf("\n crm do medico -0- para finalizar\n");  	    
		 scanf("%d",&m.crm);  	    
		} 
		fclose(arqnovo); 
		FILE *arq = fopen("medicos.bin","rb"); 
		printf("\n Exibe os MEDICOS CADASTRADOS NO ARQUIVO\n"); 
		fread(&m,sizeof(medico),1,arq); 	
	   while (!feof(arq)){  
			printf("\n CRM=%d  nome=%s  Especialidade=%s",m.crm,m.nome,m.especialidade);  
			fread(&m,sizeof(medico),1,arq); 
		} 
		printf("\n");
		fclose(arq); 
}
 
 

void ordena(struct indice vetIndice[],int tl){ //bolha 	 	    
	 indice aux; 
	 int i; 	    
	 int fim=tl-1;     
	 while (fim > 0){          
	 	for (i=0;i<fim;i++){           
		 	if (vetIndice[i].codigo > vetIndice[i+1].codigo) {
		 	  aux=vetIndice[i];
 	 	 	  vetIndice[i]=vetIndice[i+1];  	 	 	  
			  vetIndice[i+1]=aux; 
      	 	}// fecha o if 
 	     }//fecha o for do i
 	     fim=fim-1;
      }
 	  printf("\n vetor de Indice ordenado");  	  
	  for (i=0;i<tl;i++)  	     
	   	printf("\n codigo %d   posender %d",vetIndice[i].codigo,vetIndice[i].posender); 
}
void criaIndiceMedico(struct indice vetIndMedico[], int &tlm){
	 FILE *arqm=fopen("medicos.bin","rb");  
	 medico m;  //tinha escrito struct 	
	 tlm=0; 
	  fread(&m,sizeof(medico),1,arqm); 
	  while(!feof(arqm)){ 
	 	vetIndMedico[tlm].codigo=m.crm; 
	 	vetIndMedico[tlm].posender=tlm; 
 	 	tlm++; 
 	 	fread(&m,sizeof(medico),1,arqm); 
 	  } 
 	 fclose(arqm);  	
	 for (int i=0;i<tlm;i++)  	  
		printf("\ni=%d Crm %d  posender %d",i,vetIndMedico[i].codigo,vetIndMedico[i].posender); 		
 	 printf("\n ORDENA O INDICE DO MEDICO");   
 	 ordena(vetIndMedico,tlm);
}	
void criaIndiceExame(struct indice vetIndExame[], int &tle){
	 FILE *arqe=fopen("exames.bin","rb");  	 		
	 exame e; //tinha escrito struct  		 
	 tle=0;  	
	 fread(&e,sizeof(exame),1,arqe);  	
	 while(!feof(arqe)){ 
 	 	 vetIndExame[tle].codigo=e.codexame; 
 	 	 vetIndExame[tle].posender=tle;  	 	
		 tle++; 
 	 	 fread(&e,sizeof(exame),1,arqe); 
 		} 
 	  fclose(arqe); 
 	  ordena(vetIndExame,tle);
	  int i; 
	  for (i=0;i<tle;i++) {
	  	printf("\n Codexame %d  posender %d",vetIndExame[i].codigo,vetIndExame[i].posender);
	  } 
	  printf("\n ORDENA O INDICE DO EXAME\n"); 	   
	  
}

int BuscaBinariaIndexada(int codigo, struct indice vetor[], int tl){  	
	int inicio,fim,meio;  	
	int posicao=-1;
	inicio=0;  	
	fim=tl-1;  	
	meio=(inicio+fim)/2;  	
	while ((inicio<fim)&&(vetor[meio].codigo !=codigo)){ 
 	 	if (codigo < vetor[meio].codigo) 
 	 	    fim=meio;  	 	    
			  else inicio = meio+1;  	 	
		 meio=(inicio+fim)/2;     
 		} 
 	if (vetor[meio].codigo ==codigo){
	 	posicao=vetor[meio].posender; 
		return posicao;} 
 	   else return posicao; // nao encontrou 
} 
 
void relatorio(struct requisicao TabReq[],int tlr,struct indice vetIndExame[], int tle,
                                                  struct indice vetIndMedico[],int tlm){ 
	 float total=0.0;
	 exame e;
	 FILE *arqe=fopen("exames.bin","rb");  	
	 FILE *arqm=fopen("medicos.bin","rb");  	
 	 struct medico m;  		
	 struct requisicao req;  	
	 printf("\n Relatorio ");  	
	  	
	 char nome[20],descricao[10], nomemed[10],especial[10];  	
	 float preco; 
 	 int cod,crm,posicaoex,posicaomed;
	 int i; 
 	 
 	 strcpy(nome,TabReq[0].nome);   	
	 printf("\n Paciente: %s  Requisicao:%d ",TabReq[0].nome,TabReq[0].nroreq); 
 	 
 	for (i=0;i<tlr;i++){  	
	    //printf("\nNOME:%s  Paciente requis%s",nome,TabReq[i].nome); 	
	 	if (strcmp(nome,TabReq[i].nome) !=0 ){// mudou o nome  	 	 	
		 	 printf("\n Total..... $%5.2f\n",total);  	 	 	
			 total = 0.0; 
 	 	 	 strcpy(nome,TabReq[i].nome); 
 	 	 	 printf("\n\n Paciente: %s  Requisicao:%d ",TabReq[i].nome,TabReq[i].nroreq); 
 	 		} 
 	 	 cod = TabReq[i].codexame;  	 	
		 posicaoex = BuscaBinariaIndexada(cod,vetIndExame,tle);  	 	
		 if (posicaoex==-1) printf("\n ERROOO"); 
 	 	    else {  	 	     	
		         fseek(arqe,posicaoex*sizeof(exame),SEEK_SET); 
 	 	         fread(&e, sizeof(exame), 1, arqe);  	 	     	
				 strcpy(descricao,e.descricao);  	 	     	
				 preco = e.preco; 
 	 	     	 total += preco; 
 	 	 		} 
 	 	crm = TabReq[i].crm; 
 	 	posicaomed = BuscaBinariaIndexada(crm,vetIndMedico,tlm);  	
		 if (posicaomed==-1) printf("\n ERROOO");  	    
		   else {  	     	
			   fseek(arqm,posicaomed*sizeof(medico),SEEK_SET); 
 	           fread(&m, sizeof(medico), 1, arqm);  	     	
			   strcpy(nomemed,m.nome);  	     	
			   strcpy(especial,m.especialidade); 
	 	 	} 
        printf("\n Exame:%s  Preco:$%5.2f  Medico:%s %s",descricao,preco,nomemed,especial); 
 	    strcpy(nome,TabReq[i].nome); 
 	} 
 	printf("\n Total..... $%5.2f\n",total); 
 	fclose(arqe); 
 	fclose(arqm); 
}
 
 
 
main(){ 
	 indice vetIndExame[20]; 
	 indice vetIndMedico[20];
 	 requisicao TabReq[20];
 	 int tlr=0,tlm=0,tle=0;
	 int opcao=0;
	   	
	 while (opcao != 10){  	 	
	 printf("\n 1 - Leitura texto e carrega Tabela requisicao");  	 		 
	 printf("\n 2 - Cria arquivo binario de medicos - desordenado");   	 	
	 printf("\n 3 - Cria arquivo binario de exames - desordenado"); 
	 printf("\n 4 - Cria os indices Medico e Exame (ordenados)"); 	 	
	 printf("\n 5 - Exibe exames cadastrados no arquivo (desordenado)");  	 		  	 	
	 printf("\n 6 - Exibe medicos cadastrados no arquivo (desordenado)");  	 	
	 printf("\n 7 - Relatorio");
	 printf("\n 8 - exibe os medicos cadastrados em ordem crescente CRM");
	 printf("\n 9 - exibe os exames cadastrados em ordem crescente CODIGO"); 
 	 printf("\n10 - sair\n");  	 	
	 scanf("%d",&opcao);  	 	
	 switch(opcao){  	 	 	
	 case 1: carregaTabelaRequisicao(TabReq,tlr); //ok
 	 	 	 break;  	 	 	
	           	 	 	
	 case 2: criaArqMedicos();//ok
	 		 break;
	 case 3: criaArqExames();  //ok
	 		 break;
	 
	 
	 case 4: criaIndiceExame(vetIndExame,tle);
	         criaIndiceMedico(vetIndMedico,tlm); 
	 		 break; 
	  	 	 	        
	 		 	 	 	
	 case 5: exibeExames() ;  	 	 	        
	 		 break;         	 	 	
	 case 9: exibeExamesOrdenados(vetIndExame,tle);
	         break;  	 	 	        
	 		  	 	 	
	 case 6: exibeMedicos();  	 	 	        
	 		break; 
	 case 8: exibeMedicosOrdenados(vetIndMedico,tlm);
	         break;	
 	 case 7: relatorio(TabReq,tlr,vetIndExame,tle,vetIndMedico,tlm); 
 	 	 	break;  	 	 	         
 	 	} 
 	} 
} 

