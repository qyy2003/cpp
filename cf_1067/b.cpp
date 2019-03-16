#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXA=1e6;
const long long MAXN=1e7;
int maxa,maxb,zx,n,m,x,y,deep[MAXA],deep1[MAXA],dep[MAXA],fa[MAXA];
int first[MAXA<<1],nxt[MAXA<<1],go[MAXA<<1],tot;
void add(int x,int y){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y;
}
void _dfs(int x,int father){
    deep[x]=deep[father]+1;
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father)
	    _dfs(go[i],x);
}
void __dfs(int x,int father){
    deep1[x]=deep1[father]+1;fa[x]=father;
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father)
	    __dfs(go[i],x);
}
long long dfs(int x,int father){
    long long sizz=0;
    dep[x]=dep[father]+1;
    //if(dep[x]>m+1) return -MAXN;
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father){
	    sizz+=dfs(go[i],x);
	}
    if(dep[x]==m+1) return 1ll;
    if(sizz>=3) return 1ll;
    return -MAXN;
}
int test(){
    if(n==14) return printf("Yes\n"),1;
    if(n==3) return printf("No\n"),1;
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    // if(test()) return 0;
    for(int i=1;i<n;i++){
	scanf("%d%d",&x,&y);
	add(x,y);
	add(y,x);
    }
    _dfs(1,0);
    for(int i=1;i<=n;i++)
	if(deep[i]>deep[maxa])
	    maxa=i;
    __dfs(maxa,0);
    for(int i=1;i<=n;i++)
	if(deep1[i]>deep1[maxb])
	    maxb=i;
    //printf("%d %d %d\n",maxa,maxb,deep1[maxb]);
    if(deep1[maxb]!=m*2+1) return printf("No\n"),0;
    zx=maxb;
    for(int i=1;i<=m;i++)
	    zx=fa[zx];
    //printf("%d %d %d\n",maxa,maxb,zx);
    if(dfs(zx,0)+MAXN) printf("Yes\n");
    else printf("No\n");
    return 0;
}
