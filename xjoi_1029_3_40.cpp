#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<cstdio>
#include<iostream>
using namespace std;
int n,m;
long long anss,ans,x,sum,f[1<<24],sta;
int change(long long x){
    return (x==0ll)?0:(x%10+(change(x/10)<<1));
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%lld",&x); sta=change(x);
    for(int i=0;i<n;i++) scanf("%lld",&x),f[1<<i]=change(x);
    //for(int i=0;i<n;i++) printf("%lld\n",f[1<<i]);
	sum=0;x=sta;
	while(x){sum++; x-=x&(-x);}
	ans=sum,anss=1;
    for(int i=1;i<=(1<<n)-1;i++){
	f[i]=f[i-(i&(-i))]^f[i&(-i)];
	sum=0;x=f[i]^sta;
	while(x){sum++; x-=x&(-x);}
	if(sum>ans) ans=sum,anss=1;
	else if(sum==ans) anss++;
	//printf("%d %lld %lld\n",i,f[i],sum);
    }
    printf("%lld %lld",ans,anss);
}

