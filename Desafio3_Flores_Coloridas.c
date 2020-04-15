#include <stdio.h>
#include<math.h>
int main(void) {
  double a,b,c;
  double ag,av,ar,p,at,r,R;
  while(scanf("%lf %lf %lf" ,&a,&b,&c) != EOF){
    p=(a+b+c)/2;
    if(a<b+c && a>c-b && b<a+c && b>c-a && c<a+b && c>b-a){
      if(0<a && a<=b && b<=c && c<=1000){
        at=sqrt(p*(p-a)*(p-b)*(p-c));
        R=a*b*c/(4*at);
        r=at/p;
        ag=(R*R*M_PI)-at;
        av=at-(r*r*M_PI);
        ar=(r*r*M_PI);
        printf("%.4f ",ag);
        printf("%.4f ",av);
        printf("%.4f\n",ar);
      }
    }
  }
  return 0;
}