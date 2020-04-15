#include<stdio.h>
#define T 12
int main(){
	float m[T][T],res=0;
	int i,j;
	char op;
	scanf("%s",&op);
	if(op=='M' || op=='S'){
		for(i=0;i!=T;i++){
			for(j=0;j!=T;j++)
				scanf("%f",&m[i][j]);
		}
		if(op=='S'){
			for(i=0;i!=T;i++){
        for(j=0;j!=T;j++){
          if(j>i){
            res= res+m[i][j];
          }
        }
      }
		}
		else if(op=='M'){
			for(i=0;i!=T;i++){
        for(j=0;j!=T;j++){
          if(j>i){
            res= res+m[i][j];
          }
        }
      }
      res=res/66;
		}
				printf("%.1f\n",res);
	}
	return 0;
}