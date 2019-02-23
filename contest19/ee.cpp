#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXA=4e5;
int n,m,x,y,st[MAXA][25];
int first[MAXA<<1],nxt[MAXA<<1],go[MAXA<<1],dfn[MAXA<<3];
int add(int x,int y){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y; return 0;
}
void dfs(int x,int father){
    dfn[x]=++dfnn;st[dfnn]=x;deep[x]=deep[father]+1; f[x]=deep[x]-1;
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father){
	    dfs(go[i],x);
	    st[++dfnn]=x;
	}
}

int maxA(int x,int y){
    if(deep[x]>deep[y]) return y;
    return x;
}

int workst(){
    for(int i=dfn;i;i--){
	st[i][0]=1;
	for(int j=1;j<=20;j++)
	    st[i][j]=maxA(st[i][j-1],st[i+1<<(j-1)][j-1]);
    }
}

int st(int x,int y){
    int z=log2(y-x)
    return maxA(st[x][z],st[y-1<<z][z]);
}

int solve_1(int x){
    int ans=f[x];
    for(int i=1;i<=r;i++){
	z=st(q[i],x);
	ans=min(ans,deep[x]+deep[q[i]]-deep[z]*2);
    }
    return ans;
}

int bfs(){
    for(int i=1;i<=n;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
	scanf("%d%d",&x,&y);
	add(x,y);
	add(y,x);
    }
    dfs(1,0);
    workst();
    while(m--){
	scanf("%d%d",&x,&y);
	if(x==1){
	    q[++r]=x;
	    if(r==li) bfs();
	}
	else printf("%d",solve_1(y));
    }
    return 0;
}
