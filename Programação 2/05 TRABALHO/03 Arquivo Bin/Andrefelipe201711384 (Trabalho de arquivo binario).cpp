#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct req{
int numreq;
int d;
char mes[10];
int ano;
char nome[10];
int codex;	
int crm;
};

struct ind{
	int codigo;
	int posender;
};

struct exames{
int codex;
char desc[10];
float preco;	
};

struct medicos{
int crm;
char nome[10];
char espec;
};

void carrega(struct req tabreq[10],int tl){
	FILE *arq=fopen("REQUISICAO.TXT","w");
	if(arq==NULL)
	printf("\nNao encontrou o arquivo");
	else{
		while(!feof(arq)){
				fscanf(arq,"%d %d %s %d %s %d %d",&tabreq[tl].numreq,
				&tabreq[tl].d,&tabreq[tl].mes,&tabreq[tl].ano,&tabreq[tl].nome,
				&tabreq[tl].codex,&tabreq[tl].crm);
				tl++;
			}
			fclose(arq);
		}
	}
	
int buscaBinariaIndexada(int codigo, struct ind vetindice[10],int tl){
   int i=0,f=tf-1;
   int m=(i+f)/2;
   while((codigo!= vetindice[m].codigo)&&(i<f)){
	if(codigo>vetindice[m].codigo)
   	 i=m+1;
    else f=m;
    
   	 m=(i+f)/2;
   }
   if(codigo==vetindice[m].codigo)
   	  return vetindice[m].posender;
   	 else return -1;
}
	
 void RelatRequisita(struct ind vetindice[10],int tl){
 	int codigo,crm,posex,posmed;
 	char mes[10],paciente[10];
 	int dia,ano;
	float total;
 	exames e;
 	medicos m;
 	strcpy(paciente,tabreq[0].nome);
 	printf("\nPaciente: %s Data: %d / %s / %d",tabreq[0].nome,
	               tabreq[0].d,tabreq[0].mes,tabreq[0].ano);
	for(int i=0;i<tl;i++){
		
		if(stcmp(paciente,tabreq[0].nome)!=0){ //mudou
			strcpy(paciente,tabreq[i].nome);
			printf("\nPaciente: %s Data: %d / %s / %d",tabreq[i].nome,
	                     tabreq[i].d,tabreq[i].mes,tabreq[i].ano);
		    }
 	codigo=tabreq[i].codex; crm=tabreq[i].crm;
 	
 	posex=buscaBinariaIndexada(codigo,vetindice,tl);
 	posmed=buscaBinariaIndexada(crm,vetindice,tl);
	if (posex==-1)
 	   printf("\nExame não encontrado");
 	else{ FILE *arqE=fopen("EXAMES.dat","rb");  
 	    fseek(arqE,pos1*sizeof(exames),SEEK_SET);
 	    fread(&e,sizeof(exames),1,arqE);
 	    total+=e.preco;
		 }
	if (posmed==-1)
 	   printf("\nMedico não encontrado");
 	else{ FILE *arqM=fopen("MEDICOS.dat","rb");  
 	    fseek(arqM,pos2*sizeof(medicos),SEEK_SET);
 	    fread(&m,sizeof(medicos),1,arqM);
	  }
print("\nExame: %s - Preco: %.f | Medico: %s - Especialidade: %s",
	                e.desc,e.preco,m.nome,m.espec);	
	}
	printf("\nValor total: %.f",total);
	flcose(arqE);
	flcose(arqM);
}
	
main(){
	struct req tabreq[10];
	struct ind vetindice[10];
	int tl=0;
	int posicao,codigo;
	int opcao=;
	while(opcao!= ){
		printf("\n1-Carrega tabela pelo arquivo texto");
		printf("\n2-Busca binaria indexada ");
		printf("\nRelatorio de requisicao");
		printf("\nQual sua opcao?:");
		scanf("%d",&opcao);
		switch(opcao){
			
			case 1: carrega(tabreq,tl);
			      break;
			      
			case 2: printf("\nEntre com o codigo a ser procurado no indice:")
			        scanf("%d",&codigo);
                    posicao=buscaBinariaIndexada(codigo,vetindice,tl);
                    if(posicao==-1)
                    printf("\nCodigo nao encontrado no indice");
					else printf("\nCodigo: %d com Posender:%d",codigo,posicao);
					break;
					
			case 3: RelatRequisita(vetindice,tl);
			       break;
			       
				}
		
	    }
}
	
