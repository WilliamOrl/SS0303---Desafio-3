#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//====================================================================
//		Struct 
//====================================================================

typedef struct{
  char nome[15];
  char sob[15];
  int num_usp;
  float P1;
  float P2;
  float N_tab;
  float med_fim;
}classe;

typedef struct{
	classe* turma;
	int N_de_alunos;
}sala;

//====================================================================
//		Lista de fun��es
//====================================================================

void criar_turma(sala* pessoas,int n_t);
int media(float n1, float n2, float tra, int n);
void notas(float *n1,float *n2,float *tra, int i);
void informando(char *nome, char *sobre,int *usp,int i);
void Gerar_estatisticas(sala* pessoas,int n_t);
float Media_P1(sala* pessoas, int i);
float Media_P2(sala* pessoas, int i);
float Media_Trab(sala* pessoas, int i);
int Accept(sala* pessoas, int i);
void Gravar_info(sala* pessoas,int n_t);

//====================================================================
//		Inicio
//====================================================================

int main(void){
	
	int aux,n_t=0,i=0;
	int cod_turma[10];
	sala pessoas[20];
	
	while(1){
		
		system("cls");

		printf("1-Criar uma turma\n");
		printf("2-Procurar aluno\n");
		printf("3-Gerar estatistica das turmas\n");
		printf("4-Gravar informacoes de uma turma\n");
		printf("5-Encerrar sistema\n");
		
		printf("Digite uma da opcoes: ");
		scanf("%d",&aux);
		
		
		
		switch(aux){
			case 1:
				criar_turma(pessoas,n_t);
				n_t++;
				break;
			case 2:
			//	procurar_aluno(aluno);
				break;	
			case 3:
				Gerar_estatisticas(pessoas, n_t);
				break;
			case 4:
				Gravar_info(pessoas, n_t);
				break;
			case 5:
				printf("Encerrando o Sistema...");
				
				for(i=0;i!=20;i++){
					free(pessoas[i].turma);
				}
				
				goto fim;
				break;
		}
	}
fim:
	return 0;

}

//====================================================================
//		Criar Turma
//====================================================================

void criar_turma(sala* pessoas, int n_t){
	int n,i, *usp;
	float *n1, *n2, *tra;
	
	system("cls");
	printf("Digite o numero de Alunos: ");
	scanf("%d", &n);

	pessoas[n_t].turma = (classe *)malloc(n*sizeof(classe));
	pessoas[n_t].N_de_alunos = n;
	
	for(i=0;i!=n;i++){
		
		usp = &pessoas[n_t].turma[i].num_usp;
		informando(pessoas[n_t].turma[i].nome, pessoas[n_t].turma[i].sob, usp,i);
		n1=&pessoas[n_t].turma[i].P1;
		n2=&pessoas[n_t].turma[i].P2;
		tra=&pessoas[n_t].turma[i].N_tab;
		notas(n1, n2, tra,i);
		
	}
	
	for(i=0;i!=n;i++){
		n1=&pessoas[n_t].turma[i].P1;
    	n2=&pessoas[n_t].turma[i].P2;
    	tra=&pessoas[n_t].turma[i].N_tab;
    	pessoas[n_t].turma[i].med_fim = media(pessoas[n_t].turma[i].P1, pessoas[n_t].turma[i].P2, pessoas[n_t].turma[i].N_tab, i);
	}

	for(i=0;i!=n;i++){
    	printf("Numero USP:\n %d\n", pessoas[n_t].turma[i].num_usp);
    	printf("Nome completo:\n %s %s\n", pessoas[n_t].turma[i].nome, pessoas[n_t].turma[i].sob);
    	printf("Primeira nota:\n %.2f\n", pessoas[n_t].turma[i].P1);
    	printf("Segunda nota:\n %.2f\n", pessoas[n_t].turma[i].P2);
    	printf("Nota no Trabalho:\n %.2f\n", pessoas[n_t].turma[i].N_tab);
    	printf("Media final:\n %.2f\n", pessoas[n_t].turma[i].med_fim);
  	}
  	
  	sleep(10);
	
	return;
}

//====================================================================
//		medias
//====================================================================

int media(float n1, float n2, float tra, int n){
	int M[n];
	M[n] = (n1+n2+tra)/3;
	return M[n];
}

//====================================================================
//		notas
//====================================================================

void notas(float *n1,float *n2,float *tra, int i){
	
	printf("digite a nota da P1 do aluno %d: ",i+1);
	scanf("%f", &*n1);
	
	printf("digite a nota da P2 do aluno %d: ",i+1);
	scanf("%f", &*n2);
	
	printf("digite a nota da nota do trabalho do aluno %d: ",i+1);
	scanf("%f", &*tra);
}

//====================================================================
//		iformando
//====================================================================

void informando(char *nome, char *sobre,int *usp,int i){
  
  printf("digite o primeiro nome do aluno %d: ",i+1);
  scanf("%s", nome);
  
  printf("digite o sobrenome do aluno %d: ",i+1);
  scanf("%s",sobre);
  
  printf("digite numero usp do aluno %d: ",i+1);
  scanf("%d", &*usp);
}

//====================================================================
//		Cria Estatisticas das Turmas
//====================================================================

void Gerar_estatisticas(sala* pessoas, int n_t){
	
	system("cls");
	
	if(n_t == 0){
		printf("Nenhuma turma registrada");
	}
	
	else{
	
		int i;	
		float med_P1[n_t];
		float med_P2[n_t];
		float med_trab[n_t];
		int aprovados[n_t];
		
		for(i=0;i!=n_t;i++){
			med_P1[i] = Media_P1(pessoas,i);
			med_P2[i] = Media_P2(pessoas,i);
			med_trab[i] = Media_Trab(pessoas,i);
			aprovados[i] = Accept(pessoas,i);
		}
		
		for(i=0;i!=n_t;i++){
			printf(" Turma %d          ",i+1);
		}
			
		printf("\n");
		
		for(i=0;i!=n_t;i++){
			printf("Medias P1 %.2f    ",med_P1[i]);
		}			
		
		printf("\n");
		
		for(i=0;i!=n_t;i++){
			printf("Medias P2 %.2f    ",med_P2[i]);
		}			
		
		printf("\n");
		
		for(i=0;i!=n_t;i++){
			printf("Medias Trab %.2f   ",med_trab[i]);
		}
		
		printf("\n");
		
		for(i=0;i!=n_t;i++){
			printf("N de aprovados %d    ",aprovados[i]);
		}
				
	}
	sleep(10);	
}

//====================================================================
//		Media da P1
//====================================================================

float Media_P1(sala* pessoas, int i){
	
	int j;
	float aux=0;
	
	for(j=0;j!=pessoas[i].N_de_alunos;j++){
		aux = aux + pessoas[i].turma[j].P1;	
	}
	aux = aux/pessoas[i].N_de_alunos;
	return aux;
}

//====================================================================
//		Media da P2
//====================================================================

float Media_P2(sala* pessoas, int i){
	int j;
	float aux=0;
	
	for(j=0;j!=pessoas[i].N_de_alunos;j++){
		aux = aux + pessoas[i].turma[j].P2;	
	}
	aux = aux/pessoas[i].N_de_alunos;
	return aux;
}

//====================================================================
//		Media do Trabalho
//====================================================================

float Media_Trab(sala* pessoas, int i){
	int j;
	float aux=0;
	
	for(j=0;j!=pessoas[i].N_de_alunos;j++){
		aux = aux + pessoas[i].turma[j].N_tab;	
	}
	aux = aux/pessoas[i].N_de_alunos;
	return aux;
}

//====================================================================
//		Numero de Aprovados
//====================================================================

int Accept(sala* pessoas, int i){
	int j;
	int aux=0,contador=0;
	
	for(j=0;j!=pessoas[i].N_de_alunos;j++){
		aux = pessoas[i].turma[j].med_fim;
		
		if(aux>=5)
			contador++;	
	}

	return contador;
}


//====================================================================
//		Gravar Inform��es
//====================================================================

void Gravar_info(sala* pessoas,int n_t){
	
	system("cls");
	
	if(n_t == 0){
		printf("Nenhuma turma registrada");
	}
	
	else{
		
		int i,j;
		char nome[30];
		
		printf("Digite o Nome do Arquivo: ");
		setbuf(stdin, NULL);
		scanf("%[^\n]s",&nome);
		setbuf(stdin, NULL);
		
		printf("Criando Arquivo...");
		strcat(nome,".txt");
		
		FILE *arquivo = fopen (nome,"w");
		
		for(i=0;i!=n_t;i++){
			fprintf(arquivo,"Turma %d\n",i+1);
		
			for(j=0;j!=pessoas[i].N_de_alunos;j++){
				fprintf(arquivo,"Nome completo: %s %s\n", pessoas[i].turma[j].nome, pessoas[i].turma[j].sob);
				fprintf(arquivo,"Numero USP: %d\n", pessoas[i].turma[j].num_usp);
    			fprintf(arquivo,"Primeira nota: %.2f\n", pessoas[i].turma[j].P1);
    			fprintf(arquivo,"Segunda nota: %.2f\n", pessoas[i].turma[j].P2);
    			fprintf(arquivo,"Nota no Trabalho: %.2f\n", pessoas[i].turma[j].N_tab);
    			fprintf(arquivo,"Media final: %.2f\n", pessoas[i].turma[j].med_fim);
    			printf("\n");
    			}
    		fprintf(arquivo,"\n\n");
  		}	
		fclose(arquivo);
		printf("Arquivo Criado com Sucesso...");
	}
	
	sleep(5);
}

