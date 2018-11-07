#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,nn,sum1,sum2;
char s[100],s2[100];
long long ans,f[50][30];

int check(){
    //printf("%s\n",s2);
    memset(f,0,sizeof(f));
    f[0][0]=1;
    for(int i=1;i<=n;i++)
	for(int j=1;j<=min(i,n/2);j++){
	    if(s[i-1]==s2[i-j-1]) f[i][j]+=f[i-1][j];
	    if(s[i-1]==s2[j-1]) f[i][j]+=f[i-1][j-1];
	}
    ans+=f[n][n/2];
}

int dfs(int x,int y){
    if(!(x+y)) check();
    if(x) {
	s2[x+y-1]='o';
	dfs(x-1,y);
    }
    if(y){
	s2[x+y-1]='x';
	dfs(x,y-1);
    }
}

int main(){
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++)
	if(s[i]=='o')
	    sum1++;
	else
	    sum2++;
    if(sum1&1) return printf("0"),0;
    dfs(sum1/2,sum2/2);
    printf("%lld",ans*2ll);
}

