#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,k,x,y,flag;
int main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    if(k&1) flag=1;
    else k/=2;
    if(n*m%k) return printf("NO\n"),0;
    k=n*m/k;
    x=__gcd(m,k);
    y=k/x;
    if(flag){
    if(x*2ll<=m) x=x*2ll;
    else y=y*2ll;
    if(y>n) return printf("NO\n"),0;
    }
    printf("YES\n");
    printf("0 0\n");
    printf("0 %lld\n",x);
    printf("%lld 0\n",y);
}



