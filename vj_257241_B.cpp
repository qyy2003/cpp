#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,ans,g[300][300],flag,nn,nxt;
char s[1000];

void gauss(){
    for(int i=n+1;i<=nn;i++){
	nxt=i;
	while(g[nxt][i]==0&&nxt<=nn) nxt++;
	if(nxt>nn) continue;
	for(int j=n+1;j<=nn+1;j++)
	    swap(g[i][j],g[nxt][j]);
	for(int j=n+1;j<=nn;j++)
	    if(g[j][i]&&j!=i)
		    g[j][i]^=1,g[j][nn+1]^=1;
    }
}

int main(){
    scanf("%d",&t);
    while(t--){
	memset(g,0,sizeof(g));
	ans=0;flag=0;
	scanf("%d",&n);
	nn=n*n+n;
	for(int i=1;i<=n;i++){
	    scanf("%s",s);
	    for(int j=1;j<=n;j++)
		g[i*n+j][nn+1]=(s[j-1]=='w')?1:0;
	}
	for(int i=1;i<n;i++)
	    for(int j=1;j<=n;j++)
		g[i*n+j][(i+1)*n+j]=1,g[(i+1)*n+j][i*n+j]=1;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<n;j++)
		g[i*n+j][i*n+j+1]=1,g[i*n+j+1][i*n+j]=1;
	for(int i=n+1;i<=nn;i++) g[i][i]=1;
	for(int i=n+1;i<=nn;printf("\n"),i++)
	    for(int j=n+1;j<=nn+1;j++)
		printf("%d ",g[i][j]);
	printf("\n\n\n");
	gauss();
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
		if(g[i*n+j][nn+1])
		    ans++;
		else
		    for(int k=n+1;k<=nn;k++)
			if(g[i*n+j][k]) 
			    flag=1;
	for(int i=n+1;i<=nn;printf("\n"),i++)
	    for(int j=n+1;j<=nn+1;j++)
		printf("%d ",g[i][j]);
	if(flag) printf("inf\n");
	else printf("%d\n",ans);
    }
}
