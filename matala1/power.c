#define e 2.71828
double Exp(int x){
double ans=1;
int i=0;
for (i=0; i<x; i++){
ans*=e;
}
return ans;
}
double Pow(double x, int y){
double ans=1;
int i=0;
for (i=0; i<y; i++){
ans*=x;
}
return ans;
}
