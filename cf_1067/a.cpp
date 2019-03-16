#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long P=998244353;
const int MAXA=1e5+100;
const int MAXN=200;
int n,a[MAXA];
long long f[2][MAXA][205],ans;
void check(int x,int y){
    if(a[y]==-1) return ;
    for(int i=1;i<=MAXN;i++)
	if(i!=a[y])
	    f[x][y][i]=0;
}
void print(int x){
    printf("%d\n",x);
    for(int i=1;i<=n;i++,printf("\n")) 
	for(int j=1;j<=MAXN;j++)
	    printf("%lld ",f[x][i][j]);
    printf("\n");
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    //for(int i=1;i<=MAXN;i++) f[0][1][i]=1;
    f[0][0][0]=1;
    a[n+1]=1;
    for(int i=1;i<=n+1;i++){
	for(int j=1;j<=MAXN;j++)
	    f[0][i][j]=((f[0][i][j-1]+f[0][i-1][j-1])%P+f[1][i-1][j-1])%P;
	for(int j=MAXN;j>=1;j--)
	    f[1][i][j]=(f[1][i][j+1]+f[1][i-1][j])%P;
	for(int j=MAXN;j>=1;j--)
	    f[1][i][j]=(f[1][i][j]+f[0][i-1][j])%P;
	check(1,i);
	check(0,i);
    }
    if(0){
    print(0);
    print(1);
    }
    printf("%lld",f[1][n+1][1]);
    return 0;
    for(int i=1;i<=n;i++) 
	for(int j=1;j<=MAXN;j++)
	    ans=(ans+f[0][i][j]*f[1][i][j]%P)%P;
    printf("%lld",ans);
}

