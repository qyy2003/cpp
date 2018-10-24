#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,sz,son[10000][10],ID[300],sum[10000];
char s[100][100];
long long fact[20],ans;
int insert(char *s){
    int p=0,anss=0;
    for(;*s;s++){
	if(!son[p][ID[*s]]) son[p][ID[*s]]=++sz;
	p=son[p][ID[*s]];
	anss+=sum[p];
    }
    sum[p]++;
    return anss;
}
int main(){
    scanf("%d%d",&n,&m);fact[0]=1;
    for(int i=1;i<=n;i++) fact[i]=fact[i-1]*10;
    for(int i=0;i<=9;i++) ID[i+'0']=i;
    for(int i=1;i<=m;i++)
	scanf("%s",s[i]),insert(s[i]);
    for(int i=1;i<=m;i++)
	if(insert(s[i])==1) ans+=fact[n-strlen(s[i])];
    printf("%lld",fact[n]-ans);
}
