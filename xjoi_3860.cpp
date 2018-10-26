#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
long long seed,ans;
int n,m,a[800005],b[800005],f[800005];
const int MAXN=3e5;
int main(){
    scanf("%d%lld%d",&n,&seed,&m);
    for(int i=1;i<=n;i++){
	a[i]=(seed/(1<<16))%m;
	a[i]++;
	seed=(seed*1103515245+12345)%(1ll<<31);
//	printf("%d ",a[i]);
    }
    for(int i=1;i<=m;i++){
	memset(f,0,sizeof(f));
	for(int k=MAXN;k<=MAXN*2;k+=k&(-k)) f[k]++;
	for(int j=1;j<=n;j++){
	    if(a[j]==i) b[j]=b[j-1]+1;
	    else b[j]=b[j-1];
	    for(int k=2*b[j]-j+MAXN-1;k>0;k-=k&(-k)) ans+=f[k];
	    //ans-=f[2*b[j]-j+MAXN-1];
	    for(int k=2*b[j]-j+MAXN;k<=MAXN*2;k+=k&(-k)) f[k]++;
	    //printf("%lld %d\n",ans,j);
	}
//	for(int j=1;j<=n;j++) printf("%d ",b[j]);
  //  printf("%lld\n",ans);
    }
    printf("%lld",ans);
}
