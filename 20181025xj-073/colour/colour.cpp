#include<cstdio>
#include<iostream>
using namespace std;
long long c[1000];
int n;
int sol2(){
    long long mina=min(c[1],min(c[2],c[3])),suma=c[1]+c[2]+c[3];
    return printf("%lld",mina*(suma-mina));
}
int sol(){
    long long mina=c[1],suma=c[1];
    for(int i=2;i<=n;i++) mina=min(mina,c[i]),suma=suma+c[i];
    return printf("%lld",mina*(suma-mina));
}
int solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
    if(n==0||n==1) return printf("0");
    if(n==2) return printf("%lld",(c[1]==c[2])?0:c[1]*c[2]);
    if(n==3) return sol2();
    return sol();
}
int main(){
freopen("colour.in","r",stdin);
freopen("colour.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--) solve();
}
