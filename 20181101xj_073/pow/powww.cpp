//#pragma GCC optimize(2,3,"Ofast","inline","-ffast-math")
//#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long a,p,q,k,b,l,m,c,anss,ans,mu,pos,x[100],mii[1000005],miii[1000005];

long long mi(long long y){
    anss=1;pos=0;
    while(y){
	if(y&1) anss=anss*x[pos]%p;
	pos++; y>>=1;
    }
    return anss;
}

int main(){
    freopen("pow.in","r",stdin);
    freopen("pow.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&a,&p,&q,&k,&b,&l,&m,&c);
    q=(q/k)*k;a%=p;
    mu=k;x[0]=a;
    for(int i=1;i<=40;i++) x[i]=x[i-1]*x[i-1]%p; 
    mii[0]=1;
    for(int i=1;i<=1000000;i++) mii[i]=mii[i-1]*a%p;
    miii[0]=1;
    for(int i=1;i<=1000000;i++) miii[i]=miii[i-1]*mii[1000000]%p;
    for(register int i=1;i<=q;i++){
	b=(m*b+c)%l;
	ans^=miii[b/1000000]*mii[b%1000000]%p;
	//printf("%lld ",mi(a,b));
	mu--;
	if(!mu){ 
	printf("%lld\n",ans); 
	mu=k;
	}
    }
}
