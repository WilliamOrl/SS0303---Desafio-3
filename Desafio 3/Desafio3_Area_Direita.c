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
          if(j==7){
            if(i==5||i==6){
              res= res+m[i][j];
            }
          }
          if(j==8){
            if(i>=4&&i<=7){
              res= res+m[i][j];
            }
          }
          if(j==9){
            if(i>=3&&i<=8){
              res= res+m[i][j];
            }
          }
          if(j==10){
            if(i>=2&&i<=9){
              res= res+m[i][j];
            }
          }
          if(j==11){
            if(i>=1&&i<=10){
              res= res+m[i][j];
            }
          }
        }
      }
		}
		else if(op=='M'){
			for(i=0;i!=T;i++){
        for(j=0;j!=T;j++){
          if(j==7){
            if(i==5||i==6){
              res= res+m[i][j];
            }
          }
          if(j==8){
            if(i>=4&&i<=7){
              res= res+m[i][j];
            }
          }
          if(j==9){
            if(i>=3&&i<=8){
              res= res+m[i][j];
            }
          }
          if(j==10){
            if(i>=2&&i<=9){
              res= res+m[i][j];
            }
          }
          if(j==11){
            if(i>=1&&i<=10){
              res= res+m[i][j];
            }
          }
        }
      }
      res=res/30;
		}
		printf("%.1f\n",res);
	}
	return 0;
}