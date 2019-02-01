#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXA=100000;
int n,m,size[MAXA<<2],son[MAXA<<1],a[MAXA<<2],tree[MAXA<<3],tot,dfnn,df[MAXA<<2],x,y,z,dfn[MAXA<<2],topp[MAXA<<1],fa[MAXA<<2],fla[MAXA<<3];
int first[MAXA<<2],nxt[MAXA<<2],go[MAXA<<2];
int trl[MAXA<<3],trr[MAXA<<3],deep[MAXA<<2],ll[MAXA<<2],rr[MAXA<<2];

int add(int x,int y){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y;
    return 0;
}

int pre_dfs(int x,int father){
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father){
	    size[x]+=pre_dfs(go[i],x);
	    if(size[go[i]]>size[son[x]]) son[x]=go[i];
	}
    deep[x]=deep[father]+1;
    return ++size[x];
}

int predfs(int x,int father){
    dfn[x]=++dfnn;
    df[dfnn]=x;
    ll[x]=dfnn;
    fa[x]=father;
    if(son[x]){
	topp[son[x]]=topp[x];
	predfs(son[x],x);
    }
    for(int i=first[x];i;i=nxt[i])
	if((go[i]!=father)&&(go[i]!=son[x])){
	    topp[go[i]]=go[i];
	    predfs(go[i],x);
	}
    rr[x]=dfnn;
    return 0;
}

int build(int x,int l,int r){
    int mid=(l+r)>>1;
    trl[x]=l;trr[x]=r;
    if(l==r) return tree[x]=a[df[l]];
    return tree[x]=build(x<<1,l,mid)+build(x<<1|1,mid+1,r);
}

int ad(int x,int l,int r,int z){
    if(l>trr[x]||r<trl[x]) return tree[x];
    if(l<=trl[x]&&r>=trr[x]){
	fla[x]+=z;
	return tree[x]+=1ll*(trr[x]-trl[x]+1)*z;
    }
    int mid=(trl[x]+trr[x])>>1;
    fla[x<<1]+=fla[x];fla[x<<1|1]+=fla[x];
    tree[x<<1]+=1ll*(mid-trl[x]+1)*fla[x];
    tree[x<<1|1]+=1ll*(trr[x]-mid)*fla[x];
    fla[x]=0;
    return tree[x]=ad(x<<1,l,r,z)+ad(x<<1|1,l,r,z);
}

int ask(int x,int l,int r){
    if(l<=trl[x]&&r>=trr[x]) return tree[x];
    if(l>trr[x]||r<trl[x]) return 0;
    int mid=(trl[x]+trr[x])>>1;
    fla[x<<1]+=fla[x];fla[x<<1|1]+=fla[x];
    tree[x<<1]+=1ll*(mid-trl[x]+1)*fla[x];
    tree[x<<1|1]+=1ll*(trr[x]-mid)*fla[x];
    fla[x]=0;
    return ask(x<<1,l,r)+ask(x<<1|1,l,r);
}

int work(int x){
    long long ans=0;
    while(x){
	ans+=ask(1,dfn[topp[x]],dfn[x]);
	x=fa[topp[x]];
    }
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
	scanf("%d%d",&x,&y);
	add(x,y);
	add(y,x);
    }
    pre_dfs(1,0);
    topp[1]=1;
    predfs(1,0);
    build(1,1,n);
    for(int i=1;i<=m;i++){
	scanf("%d%d",&x,&y);
	if(x==3) printf("%d\n",work(y));
	else{
	    scanf("%d",&z);
	    if(x==1) ad(1,dfn[y],dfn[y],z);
	    if(x==2) ad(1,ll[y],rr[y],z);
	}
    }
}
