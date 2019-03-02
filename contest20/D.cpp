#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const long long P=1e9+7;
int n,m,t,k;
long long f[2000][2000],a[2000],inv[1000],ans;
long long pow(long long x,long long y){
    long long an=1;
    while(y){
	if(y&1) an=an*x%P;
	x=x*x%P;
	y>>=1;
    }
    return an;
}
int main(){
    int N=1000,K=1000;
    f[0][0]=1;
    for(int i=1;i<=K;i++)
	for(int j=i;j<=N;j++)
	    f[i][j]=(f[i][j-i]+f[i-1][j-i])%P;
    inv[0]=1;a[0]=1;
    for(int i=1;i<=N;i++){
	a[i]=a[i-1]*i%P;
	inv[i]=pow(a[i],P-2);
    }
    scanf("%d",&t);
    while(t--){
	scanf("%d%d",&n,&m);
	ans=0;
	for(int i=m*(m-1)/2;i<=n;i++)
	    ans=(ans+a[n-i+m]*inv[m]%P*inv[n-i]%P*f[m][i]%P)%P;
	ans=ans*a[m]%P;
	printf("%lld\n",ans);
    }
}
