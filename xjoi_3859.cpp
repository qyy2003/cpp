#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int n,nxt[1000],last[1000],flag;
char map[1000][1000];
int add(int x,int y){
    nxt[last[x]]=y;
    last[y]=last[x];
    last[x]=y;
    nxt[y]=x;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){getchar();
	for(int j=1;j<=n;j++)
	    scanf("%c",&map[i][j]);}
    nxt[0]=n+1;
    last[n+1]=0;
    add(n+1,1);
    if(map[1][2]=='+') add(n+1,2); else add(1,2);
    for(int j=3;j<=n;j++){
	flag=1;
    for(int i=nxt[0];i!=n+1;i=nxt[i])
	if(map[j][i]=='+'){
	    flag=0;
	    add(i,j);
	    break;
	}
	if(flag) add(n+1,j);
    }
    for(int i=nxt[0];i!=n+1;i=nxt[i])printf("%d ",i-1);
}



    
