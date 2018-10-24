#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXA=5*1e4;
int n,x,y,s,t,deep[MAXA],fa[MAXA][25],first[MAXA],nxt[MAXA<<1],go[MAXA<<1],tot,ans;
int lca(int x,int y){
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=20;i>=0;i--)
	if(deep[fa[x][i]]>=deep[y])
	    x=fa[x][i];
    if(x==y) return x;
    for(int i=20;i>=0;i--)
	if(fa[x][i]!=fa[y][i])
	    x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int dfs(int x,int father){
    deep[x]=deep[father]+1;
    fa[x][0]=father;
    for(int i=1;i<=20;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father)
	    dfs(go[i],x);
}
int add(int x,int y){
    nxt[++tot]=first[x];first[x]=tot;go[tot]=y;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
	scanf("%d%d",&x,&y);
	add(y,x);
	add(x,y);
    }
    dfs(1,0);
    int m;
    scanf("%d",&m);
    s=1;
    for(int i=1;i<=m;i++){
	scanf("%d",&t);
	ans+=deep[s]+deep[t]-deep[lca(s,t)]*2;
	//printf("%d %d %d %d %d\n",deep[s],deep[t],deep[lca(s,t)],t,lca(s,t));
	s=t;
    }
    printf("%d",ans);
}
