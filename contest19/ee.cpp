#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXA=4e5;
int n,m,x,y,l,r,q[MAXA<<1],st[MAXA*5][20];
int first[MAXA<<1],nxt[MAXA<<1],go[MAXA<<1],dfn[MAXA<<3],tot;
int deep[MAXA<<1],f[MAXA<<1],dfnn;
int add(int x,int y){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y; return 0;
}
void dfs(int x,int father){
    dfn[x]=++dfnn;st[dfnn][0]=x;deep[x]=deep[father]+1; f[x]=deep[x]-1;
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father){
	    dfs(go[i],x);
	    st[++dfnn][0]=x;
	}
}

int maxA(int x,int y){
    if(deep[x]>deep[y]) return y;
    return x;
}

int workst(){
    for(int i=dfnn;i;i--){
	for(int j=1;j<=19;j++)
	    st[i][j]=maxA(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }
}

int stt(int x,int y){
    if(x>y) swap(x,y);
    int z=log2(y-x);
    //printf("%d %d %d %d %d\n",x,y,z,st[x][z],st[y-(1<<z)][z]);
    return maxA(st[x][z],st[y-(1<<z)][z]);
}

int solve_1(int x){
    //printf("s%d\n",x);
    int ans=f[x],z;
    for(int i=1;i<=r;i++){
	z=stt(dfn[q[i]],dfn[x]);
	ans=min(ans,deep[x]+deep[q[i]]-deep[z]*2);
    }
    return ans;
}

int bfs(){
    l=0;
    while(l<r){
	x=q[++l];
	for(int i=first[x];i;i=nxt[i])
	    if(f[go[i]]>f[x]+1){
		f[go[i]]=f[x]+1;
		q[++r]=go[i];
	    }
    }
    l=r=0;
}

int main(){
    scanf("%d%d",&n,&m);
    int li=sqrt(n);
    for(int i=1;i<n;i++){
	scanf("%d%d",&x,&y);
	add(x,y);
	add(y,x);
    }
    dfs(1,0);
    //for(int i=1;i<=dfnn;i++) printf("%d ",st[i][0]);
    workst();
    while(m--){
	scanf("%d%d",&x,&y);
	if(x==1){
	    q[++r]=y;
	    f[y]=0;
	    if(r==li) bfs();
	}
	else printf("%d\n",solve_1(y));
    }
    return 0;
}
