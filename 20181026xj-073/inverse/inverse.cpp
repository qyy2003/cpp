#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int P=998244353;
int fs[10000005],f[10000005],n,x,t,ans;
int mi(int x,int y){
    int anss=1;
    while(y){
	if(y&1) anss=1ll*anss*x%P;
	x=1ll*x*x%P; y>>=1;
    }
    return anss;
}
int main(){
    freopen("inverse.in","r",stdin);
    freopen("inverse.out","w",stdout);
    fs[0]=1;
    for(int i=1;i<=10000000;i++) fs[i]=1ll*fs[i-1]*i%P;
    //for(int i=1;i<=10000000;i++) printf("%d ",fs[i]);
    //f[0][0]=1;
    for(int i=1;i<=10000000;i++){
//	f[i][0]=1;
//	for(int j=1;j<=i;j++) f[i][j]=(1ll*f[i-1][j-1]*(i-1)%P+f[i-1][j])%P;
	f[i]=(1ll*i*f[i-1]%P+1ll*(i-1)*fs[i-1]%P)%P;
    }
    /*for(int i=0;i<=10;i++){
	for(int j=0;j<=i;j++) printf("%d ",f[i][j]);
	printf("\n");
    }*/
    scanf("%d",&t);
    while(t--){
	ans=0;
	scanf("%d",&x);
	//for(int i=1;i<=x;i++) ans=(ans+1ll*f[x][i]*i%P)%P;
	printf("%lld\n",1ll*f[x]*mi(fs[x],P-2)%P);
    }
}
