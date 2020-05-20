#include<stdio.h>

typedef struct{
	char nome[30];
	int dia;
	int mes;
	int ano;
	int hora;
	int minuto;
	int segundo;
}calendario;

void Leitura(calendario *atividade,int n);
void Agenda(calendario *atividade,int n);

int main(void){
	
	int i,n;
	
	scanf("%d",&n);
	calendario atividades[n];
	
	Leitura(atividades,n);
	
	Agenda(atividades,n);
	
}

void Leitura(calendario *atividade,int n){
	
	int i;
	
	for(i=0;i!=n;i++){
	
		scanf("%d", &atividade[i].dia);
	
		scanf("%d", &atividade[i].mes);
	
		scanf("%d", &atividade[i].ano);
		
		scanf("%d", &atividade[i].hora);
		
		scanf("%d", &atividade[i].minuto);
		
		scanf("%d", &atividade[i].segundo);
		
		fflush(stdin);
		fgets(atividade[i].nome, 30, stdin);
	}
	return;
}

void Agenda(calendario *atividade,int n){
	int i;
	
	for(i=0;i!=n;i++){
		printf("%02d/%02d/%02d - %02d:%02d:%02d\n%s",atividade[i].dia,atividade[i].mes,atividade[i].ano,atividade[i].hora,atividade[i].minuto,atividade[i].segundo,atividade[i].nome);
	}
}
