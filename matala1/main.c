#include <stdio.h>
#include "myMath.h"


int main(){

double ans = 0;

printf("Enter a number");
scanf("%lf",&ans);
double finalSum=0;
float value1=0;
float value2=0;
value1=Exp(ans);
value2=Pow(ans,3);
finalSum=add(value1,value2);
finalSum=sub(finalSum,2);

printf("The value of: f(x)=e^x+x^3-2 at the point %f is: %.4lf ",ans, finalSum);

 finalSum=0;
 value1=0;
 value2=0;
value1=mul(ans,3);
value2=Pow(ans,2);
value2=mul(2,value2);
finalSum=add(value1,value2);

printf("The value of: f(x)=3x+2x^2 at the point %f is: %.4lf ",ans,finalSum);

 finalSum=0;
 value1=0;
 value2=0;
value1=Pow(ans,3);
value1=mul(4,value1);
value1=div(value1,5);
value2=mul(2,ans);
finalSum=sub(value1,value2);

printf("The value of: f(x)=(4x^3)/5-2x at the point %f is: %.4lf ",ans,finalSum);




return 0;
}
