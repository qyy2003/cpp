#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,l,r,k;
long long P=1e9+7,c[500100][50],ans[500100];
int main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    scanf("%d%d",&n,&m);
    c[0][0]=1;
    for(int i=1;i<=n+40;i++){
	c[i][0]=1;
	for(int j=1;j<=40;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%P;
    }
    for(int i=1;i<=m;i++){
	scanf("%d%d%d",&l,&r,&k);
	for(int j=l;j<=r;j++)
	    ans[j]=(ans[j]+c[j+k-l][k])%P;
	}
    for(int i=1;i<=n;i++)
	printf("%lld\n",ans[i]);
}


