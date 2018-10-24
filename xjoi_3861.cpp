#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n,m,cost,f[10][20000],x,p[100][100],sum,ans,nn;
char ch;
vector<int> q;
int main(){
    scanf("%d%d%d",&n,&m,&cost);
    for(int i=1;i<=n;i++){getchar();
	for(int j=1;j<=m;j++){
	    ch=getchar();
	    if(ch>='0'&&ch<='9') p[i][j]=ch-'0';
	    if(ch>='A'&&ch<='Z') p[i][j]=ch-'A'+10;
	    if(ch>='a'&&ch<='z') p[i][j]=ch-'a'+36;
	}}
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=7;f[i][0]=0,i++)
	for(int j=1;j<=m;j++){
	    q.clear();sum=0;
	    for(int k=i;k<=n;k+=7) q.push_back(p[k][j]);
	    nn=q.size();
	    //sort(q.begin(),q.end());
	    for(int k=0;k<nn;k++){
		sum+=q[k];
		f[i][k+1]=min(f[i][k+1],sum);
	    }
	}
    sum=0;
    for(int i=1;i<=n;i++){
	x=i%7; if(!x) x=7; if(i%7==1) sum++;
	cost=cost-f[x][sum]+f[x][sum-1];
	//printf("%d %d\n",sum,cost);
	if(cost<0)
	    return printf("%d",i-1),0;
    }
    printf("%d",n);
}


