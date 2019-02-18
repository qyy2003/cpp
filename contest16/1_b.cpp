#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,pos,ans,f[10000],nxt[10000];
char s1[10000],s2[10000];
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    int x=strlen(s1+1),y=strlen(s2+1);
    for(int i=1;i<=y;i++){
	pos=i;
	for(int j=1;j<=x;j++){
	    if(s2[pos]==s1[j]) pos++;
	    if(pos==y+1) f[i]++,pos=1;
	}
	nxt[i]=pos;
    }
    pos=1;
    for(int i=1;i<=n;i++){
	ans+=f[pos];
	pos=nxt[pos];
    }
    printf("%d",ans/m);
}
