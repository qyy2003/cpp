#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXA=1e6;
const int MAXN=1e7;
int first[MAXA],nxt[MAXA],go[MAXA],siz[MAXA],fa[MAXA],son[MAXA],tot,ll[MAXA],rr[MAXA],top[MAXA],deep[MAXA],dfn[MAXA],dfnn;
int trmin[MAXA<<1],trmax[MAXA<<1];
int n,m,x,y;
int add(int x,int y){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y; return 0;
}

int predfs(int x,int father){
    deep[x]=deep[father]+1;
    for(int i=first[x];i;i=nxt[i]){
	if(go[i]==father) continue;
	siz[x]+=predfs(go[i],x);
	if(siz[son[x]]<siz[go[i]]) son[x]=go[i];
    }
    return ++siz[x];
}

void dfs(int x,int father){
    fa[x]=father;
    dfn[x]=++dfnn;
    ll[x]=dfnn;
    if(son[x]){
	top[son[x]]=top[x];
	dfs(son[x],x);
    }
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father&&go[i]!=son[x]){
	    top[go[i]]=go[i];
	    dfs(go[i],x);
	}
    rr[x]=dfnn;
}

void build(int x,int l,int r){
    if(l==r){
	trmin[x]=MAXN;trmax[x]=-1;
	return;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);build(x<<1|1,mid+1,r);
    trmin[x]=MAXN;trmax[x]=-1;
}

int askmin(int x,int trl,int trr,int l,int r){
    if(l>trr||r<trl) return MAXN;
    if(l<=trl&&r>=trr) return trmin[x];
    int mid=(trl+trr)>>1;
    return min(askmin(x<<1,trl,mid,l,r),askmin(x<<1|1,mid+1,trr,l,r));
}

int askmax(int x,int trl,int trr,int l,int r){
    if(l>trr||r<trl) return -1;
    if(l<=trl&&r>=trr) return trmax[x];
    int mid=(trl+trr)>>1;
    return max(askmax(x<<1,trl,mid,l,r),askmax(x<<1|1,mid+1,trr,l,r));
}

void change(int x,int l,int r,int pos,int val){
    if(l==r){
	trmin[x]=trmax[x]=val;
	return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) change(x<<1,l,mid,pos,val);
    else change(x<<1|1,mid+1,r,pos,val);
    trmin[x]=min(trmin[x<<1],trmin[x<<1|1]);
    trmax[x]=max(trmax[x<<1],trmax[x<<1|1]);
}

int work(int x){
    //return 0;
    int y=askmax(1,1,n,dfn[top[x]],dfn[x]);
    if(y!=-1) return y;
    return work(fa[top[x]]);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
	scanf("%d%d",&x,&y);
	add(x,y);
	add(y,x);
    }
    predfs(1,0);
    top[1]=1;
    dfs(1,0);
    build(1,1,n);
    //for(int i=1;i<=n;i++) printf("%d %d %d\n",dfn[i],top[i],deep[i]);
    change(1,1,n,dfn[1],deep[1]);
    while(m--){
	scanf("%d%d",&x,&y);
	if(x==1) change(1,1,n,dfn[y],deep[y]);
	if(x==2){
	    //printf("%d\n",askmin(1,1,n,ll[y],rr[y]));
	    printf("%d\n",min(askmin(1,1,n,ll[y],rr[y])-deep[y],deep[y]-work(y)));
	}
    }
}
