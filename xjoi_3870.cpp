#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
double f[3000][3000];
int main(){
    scanf("%d%d",&n,&m);n*=m;
   // memset(f,-1,sizeof(f));
    for(int i=0;i<=n/2;i++)
	for(int j=0;j<=n/2-i;j++){
	    if(f[i][j]==0&&(i||j)) continue;
	    if(n-i*2-j-1>0) f[i][j+2]+=(f[i][j]+1.0)*((double)(n/2-i-j))/(double)(n-i*2-j)*((double)(n/2-i-j-1)/(double)(n-i*2-j-1))*4.0;
	    if(n-i*2-j>0&&j) f[i+1][j-1]+=(f[i][j]+1.0)*((double)(j)/(double)(n-i*2-j));
	    if(n-i*2-j-1>0) f[i+1][j]+=(f[i][j]+1.0)*((double)(n/2-i-j))/(double)(n-i*2-j)*((double)1.0/(double)(n-i*2-j-1))*2.0;
	    if(n-i*2-j-1>0) f[i+1][j]+=(f[i][j]+2.0)*((double)(n/2-i-j))/(double)(n-i*2-j)*((double)j/(double)(n-i*2-j-1))*2.0;
	}
    printf("%lf",f[n/2][0]);
}
