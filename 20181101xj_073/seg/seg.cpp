#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXA=2e5,P=998244353;
long long a[MAXA],ans,kk;
int m,n,opt,l,r;

int main(){
    //freopen("seg.in","r",stdin);
    //freopen("seg.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    scanf("%d",&m);
    while(m--){
	scanf("%d%d%d",&opt,&l,&r);
	if(opt==1){
	    scanf("%lld",&kk);
	    for(int i=l;i<=r;i++) a[i]&=kk;
	}
	if(opt==2){
	    ans=0;
	    for(int i=l;i<=r;i++) ans+=a[i];
	    printf("%lld\n",ans);
	}
	if(opt==3){
	    ans=0;
	    for(int i=l;i<=r;i++) 
		for(int j=l;j<=r;j++)
		    ans=(ans+(a[i]+a[j])*(a[i]+a[j])%P)%P;
	    printf("%lld\n",ans);
	}
    }
}

