#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
double f[3000][3000],xx,xxx;
int main(){
    scanf("%d%d",&n,&m);n*=m;
   // memset(f,-1,sizeof(f));
    for(int i=0;i<=n/2;i++)
	for(int j=0;j<=n/2-i;j++){
	    if(f[i][j]==0.0&&(i||j)) continue;
	    printf("%d %d %lf\n",i,j,f[i][j]);
	    xx=n/2-i-j; xxx=n-i*2-j;
	    if(xxx==1)  
	    if(n-i*2-j-1>0) f[i][j+2]+=(f[i][j]+1.0)*xx/xxx*(xx-1)/(xxx-1)*4.0;
	    if(n-i*2-j>0&&j) f[i+1][j-1]+=(f[i][j]+1.0)*((double)(j)/xxx);
	    if(n-i*2-j-1>0) f[i+1][j]+=(f[i][j]+1.0)*xx/xxx*((double)1.0/(xxx-1))*2.0;
	    if(n-i*2-j-1>0) f[i+1][j]+=(f[i][j]+2.0)*xx/xxx*((double)j/(xxx-1))*2.0;
	}
    printf("%lf",f[n/2][0]);
}
