#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long a,p,q,k,b,l,m,c,anss,ans,mu,bb;

long long mi(long long x,long long y){
    anss=1;
    while(y){
	if(y&1) anss=anss*x%p;
	x=x*x%p; y>>=1;
    }
    return anss;
}
int main(){
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&a,&p,&q,&k,&b,&l,&m,&c);
    q=(q/k)*k;a%=p;
    mu=k;
    for(int i=1;i<=q;i++){
	b=(m*b+c)%l;
	bb^=b;
	mu--;
	if(!mu){ 
	    ans^=mi(a,bb);
	    printf("%lld\n",ans); 
	    mu=k;
	}
    }
}
