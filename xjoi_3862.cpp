#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int P=1e9+7;
int n,a[100],aa,sum;
long long ans,f[45][1605][45][2];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(~a[1]) f[1][a[1]][a[1]][0]=1;
    else for(int i=0;i<=40;i++) f[1][i][i][0]=1;
    for(int i=2;i<=n;i++)
	for(int aa=0;aa<=40;aa++){
	    if(~a[i]) aa=a[i];
	    for(int j=aa*(i-1);j<=1600-aa;j++){
		//f[i][j+aa][aa][0]=f[i-1][j][aa][0];
		for(int k=0;k<=aa;k++)
		    f[i][j+aa][aa][0]=((f[i-1][j][k][0]+f[i-1][j][k][1])%P+f[i][j+aa][aa][0])%P;
		for(int k=aa+1;k<=40;k++)
		    f[i][j+aa][aa][1]=(f[i-1][j][k][0]+f[i][j+aa][aa][1])%P;
	    }
	    if(~a[i]) break;
	}
    for(int i=0;i<=1600;i++)
	for(int j=0;j<=40;j++)
	    //if(f[n][i][j][0]) printf("%d %d %d %d\n",n,i,j,0);
	    ans=(ans+(f[n][i][j][0]+f[n][i][j][1])%P)%P;
    printf("%lld",ans);
}
