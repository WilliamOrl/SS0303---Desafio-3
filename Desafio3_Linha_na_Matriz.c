#include<stdio.h>
#define T 3
int main(){
	float m[T][T],res=0;
	int i,j,linha;
	char oper;
	scanf("%d",&linha);
	scanf("%s",&oper);
	if(linha>=0 && linha<=11){
		if(oper=='M' || oper=='S'){
			for(i=0;i!=T;i++){
				for(j=0;j!=T;j++)
					scanf("%f",&m[i][j]);
			}
			if(oper=='S'){
				for(j=0;j!=T;j++)
					res= res+m[linha][j];
			}
			if(oper=='M'){
				for(j=0;j!=T;j++)
					res= res+m[linha][j];	
				res = res/T;
			}		
		}
	}
	printf("%.1f\n",res);
	return 0;
}