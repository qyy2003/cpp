#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
double EPS=-1e-6;
int ask(){
    double x=m%n,y=n;y=y/2.0;
    if(x>EPS+y*sqrt(3.0)) return 2;
    if(x>EPS+y) return 1;
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    printf("%d",(m/n)*2+1+ask());
}
