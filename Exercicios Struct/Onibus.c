#include <stdio.h>

void criaRegistro(char *nome, char *cpf, int *idade);
void trans(char *nome, char *cpf, int *idade, int n, char *v,int i,int j);

typedef struct {
  char nome[15];
  char cpf[5];
  int idade;
}Pessoal;

int main(void) {
  int i, n, aux, j=0,m;
  int *idade;
  scanf("%d", &n);
  scanf("%d", &m);

  char v[n];
  for(i=0;i!=n;i++){
    v[i]=-1;
  }

  Pessoal ind[m];

  //quantos passageiros
  for(i=0;i!=m;i++){
    idade=&ind[i].idade;
    criaRegistro(ind[i].nome,ind[i].cpf,idade);
  }

  //comprando passagem
  for(i=0;i!=m;i++){
    printf("Escolha sua poltrona\n");
    outra:
    scanf("%d", &aux);
    if(v[aux]== -1){
      v[aux]= j;
      j++;
    }
    else{
      printf("Poltrona %d ocupada\n", aux);
      goto outra;
    }
  }

  //mostrando os lugares
  for(i=0;i!=n;i++){
    for(j=0;j!=m;j++){
      idade=&ind[j].idade;
      trans(ind[j].nome,ind[j].cpf,idade, n, v, i, j);
    }
  }
  
  return 0;
}

//cadastra as pessoas
void criaRegistro(char *nome, char *cpf, int *idade){
  printf("Seu primeiro nome?\n");
  scanf("%s", nome);
  printf("Qual seu cpf?\n");
  scanf("%s", cpf);
  printf("Qual sua idade?\n");
  scanf("%d", &*idade);
  return;
}

//lugar em pessoa
void trans(char *nome, char *cpf, int *idade, int n,char *v,int i,int j){
  if(v[i]==j-1 && j-1==-1){
    printf("Poltrona %d - NULL\n",i);
  }
  else if(v[i]==j){
    printf("-Poltrona %d\n", i);
    printf("--NOME: %s\n",nome);
    printf("--CPF: %s\n", cpf);
    printf("--IDADE: %d\n", *idade);
  }
  return;
}
