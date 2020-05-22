#include <stdio.h>
#include <stdlib.h>


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
}sala;

//====================================================================
//		Lista de funções
//====================================================================

void criar_turma(/*classe* aluno,*/ sala* pessoas,int n_t);
int media(float n1, float n2, float tra, int n);
void notas(float *n1,float *n2,float *tra, int i);
void informando(char *nome, char *sobre,int *usp,int i);
void mostra(sala* pessoas);
//====================================================================
//		Inicio
//====================================================================

int main(void){
	
	int aux,n_t=0,i=0;
	int cod_turma[10];
	//classe *aluno;
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
				criar_turma(/*aluno,*/pessoas,n_t);
			//	pessoas[n_t].turma = aluno;
				n_t++;
			//	mostra(pessoas);
				break;
			case 2:
			//	procurar_aluno(aluno);
				break;	
			case 3:
				break;
			case 4:
				break;
			case 5:
				goto fim;
				break;
		}
	}
fim:
	return 0;

}
/*
void mostra(sala* pessoas) {
	int i;
	printf("a");
	for(i=0;i!=2;i++){
    			printf("Numero USP:\n %d\n", pessoas[0].turma[i].num_usp);
    			printf("Nome completo:\n %s %s\n", pessoas[0].turma[i].nome, pessoas[0].turma[i].sob);
    			printf("Primeira nota:\n %.2f\n", pessoas[0].turma[i].P1);
    			printf("Segunda nota:\n %.2f\n", pessoas[0].turma[i].P2);
    			printf("Nota no Trabalho:\n %.2f\n", pessoas[0].turma[i].N_tab);
    			printf("Media final:\n %.2f\n", pessoas[0].turma[i].med_fim);
  			}
  	getchar();
}
*/

//====================================================================
//		Criar Turma
//====================================================================

void criar_turma(/*classe* aluno,*/ sala* pessoas, int n_t){
	int n,i, *usp;
	float *n1, *n2, *tra;
	
	system("cls");
	printf("Digite o numero de Alunos: ");
	scanf("%d", &n);

	//aluno = (classe *)malloc(n*sizeof(classe));
	pessoas[n_t].turma = (classe *)malloc(n*sizeof(classe));
	
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

