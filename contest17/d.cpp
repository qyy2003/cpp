#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXA=1e6;
const long long MAXN=1e18;
int n,m,x,y,fl,topp;
int first[MAXA<<1],go[MAXA<<1],nxt[MAXA<<1],tot=1,na[MAXA<<1];
long long tree[MAXA<<3],val[MAXA],f[MAXA];
int dfn[MAXA],df[MAXA],top[MAXA],dep[MAXA],fa[MAXA],son[MAXA],siz[MAXA];
int add(int x,int y,long long z){
    nxt[++tot]=first[x]; first[x]=tot; val[tot]=z; go[tot]=y; return 0;
}

long long che(long long x,long long y){
    if(x>MAXN/y) return MAXN*2ll;
    return x*y;
}

int predfs(int x,int father){
    fa[x]=father;dep[x]=dep[father]+1;
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father){
	    f[go[i]]=val[i];
	    na[i]=na[i^1]=go[i];
	    siz[x]+=predfs(go[i],x);
	    if(siz[go[i]]>siz[son[x]]) son[x]=go[i];
	}
    return ++siz[x];
}

void dfs(int x,int father){
    dfn[x]=++topp;
    df[topp]=x;
    top[son[x]]=top[x];
    if(son[x]) dfs(son[x],x);
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father&&go[i]!=son[x]){
	    top[go[i]]=go[i];
	    dfs(go[i],x);
	}
}

long long build(int x,int l,int r){
    int mid=(l+r)>>1;
    if(l==r) return tree[x]=f[df[l]];
    return tree[x]=che(build(x<<1,l,mid),build(x<<1|1,mid+1,r));
}

long long ask(int x,int l,int r,int ll,int rr){
    //printf("$%d %d %d %d %d\n",x,l,r,ll,rr);
    if(l>=ll&&r<=rr) return tree[x];
    if(r<ll||l>rr) return 1;
    int mid=(l+r)>>1;
    return che(ask(x<<1,l,mid,ll,rr),ask(x<<1|1,mid+1,r,ll,rr));
}

long long ad(int x,int l,int r,int pos,long long vall){
    if(!(l<=pos&&r>=pos)) return tree[x];
    if(l==r) return tree[x]=vall;
    int mid=(l+r)>>1;
    return tree[x]=che(ad(x<<1,l,mid,pos,vall),ad(x<<1|1,mid+1,r,pos,vall));
}

long long hld(int x,int y){
   // printf("%d %d\n",x,y);
    if(dep[top[x]]>dep[top[y]]||top[x]==top[y]&&dep[x]>dep[y]) swap(x,y);
    if(top[x]==top[y]) return ask(1,2,n,dfn[x]+1,dfn[y]);
    return che(ask(1,2,n,dfn[top[y]],dfn[y]),hld(x,fa[top[y]]));
}

int solve(){
    long long sum=0;
    scanf("%d",&fl);
    if(fl==1){
	scanf("%d%d",&x,&y);
	scanf("%lld",&sum);
	printf("%lld\n",sum/hld(x,y));
    }
    else{
	scanf("%d%lld",&x,&sum);val[x*2]=sum;
	ad(1,2,n,dfn[na[x*2]],val[x*2]);
    }
    return 0;
}

int main(){
    long long z; top[1]=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
	scanf("%d%d%lld",&x,&y,&z);
	add(x,y,z);
	add(y,x,z);
    }
    predfs(1,0);
    dfs(1,0);
    build(1,2,n);
    for(;m;m--) solve();
    return 0;
}
