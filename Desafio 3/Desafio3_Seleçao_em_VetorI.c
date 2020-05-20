#include <stdio.h>

int main(void) {
  float A[100];
  int i;
  for(i=0;i!=100;i++){
    float a;
    scanf("%f",&a);
    A[i]=a;
  }
  for(i=0;i!=100;i++){
    if(A[i]<=10){
      printf("A[%d] = %.1f\n" ,i,A[i]);
    }
  }
  return 0;
}
