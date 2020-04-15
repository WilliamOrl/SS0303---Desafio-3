#include <stdio.h>

int main(void) {
  int par[5], impar[5];
  int i;
  int j=0,k=0;
  for(i=0;i!=15;i++){
    int a,resto;
    scanf("%d",&a);
    resto=a%2;
    if(resto==0){
      par[j]=a;
      j++;
    }
    else{
      impar[k]=a;
      k++;
    }
    if(j==5){
      int b;
      for(b=0;b!=5;b++){
        printf("par [%d] = %d\n",b,par[b]);
      }
      j=0;
    }
    else if(k==5){
      int b;
      for(b=0;b!=5;b++){
        printf("impar [%d] = %d\n",b,impar[b]);
      }
      k=0;
    }
  }
  int c;
  for(c=0;c!=k;c++){
    printf("impar [%d] = %d\n",c,impar[c]);
  }
  for(c=0;c!=j;c++){
    printf("par [%d] = %d\n",c,par[c]);
  }
  return 0;
}