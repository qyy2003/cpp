#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m;
const int MAXN=1e9;
const int MAXA=2e6;
int a[MAXA],tree[MAXA<<2],trl[MAXA<<2],trr[MAXA<<2],t[MAXA],l[MAXA],r[MAXA];
int fl[MAXA],s[MAXA],topp,ans[MAXA];
pair<int,int>q[MAXA];
int pre(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n+m;i++){
	if(i<=n) fl[i]=1;
	else fl[i]=2;
	scanf("%d%d%d",&l[i],&r[i],&t[i]);
	a[i]=i;
	q[i]=make_pair(t[i],n+i);
    }
    sort(q+1,q+n+m+1);
    for(int i=1;i<=n+m;i++){
	if(s[topp]!=q[i].first) s[++topp]=q[i].first;
	q[i]=make_pair(q[i].second,topp);
    }
    sort(q+1,q+n+m+1);
    for(int i=1;i<=n+m;i++) t[i]=q[i].second;
}
int mysort(int x,int y){
    return l[x]<l[y]||(l[x]==l[y]&&fl[x]<fl[y]);
}
int maxx(int x,int y){
    if(x==-1) return y;
    if(y==-1) return x;
    if(r[x]>=r[y]) return x;
    return y;
}
int build(int x,int ll,int rr){
    tree[x]=-1;
    if(ll==rr) return 0;
    int mid=(ll+rr)>>1;
    return build(x<<1,ll,mid)+build(x<<1|1,mid+1,rr);
}
int ad(int x,int ll,int rr,int pos,int val){
    if(ll==rr){
	tree[x]=maxx(tree[x],val);
	return tree[x];
    }
    int mid=(ll+rr)>>1;
    if(pos<=mid) tree[x]=maxx(ad(x<<1,ll,mid,pos,val),tree[x<<1|1]);
    else tree[x]=maxx(tree[x<<1],ad(x<<1|1,mid+1,rr,pos,val));
    return tree[x];
}
int ask(int x,int ll,int rr,int pos,int val){
    if(pos>rr) return MAXN;
    if(maxx(tree[x],val)==val) return MAXN;
    //printf("%d %d %d %d\n",ll,rr,pos,val);
    if(ll==rr) return tree[x];
    int mid=(ll+rr)>>1;
    int xx=ask(x<<1,ll,mid,pos,val);
    if(xx==MAXN) xx=ask(x<<1|1,mid+1,rr,pos,val);
    return xx;
}
    
int main(){
    pre();
    build(1,1,topp);
    sort(a+1,a+n+m+1,mysort);
    int x;
    for(int i=1;i<=n+m;i++){
	x=a[i];
	if(fl[x]==1)
	    ad(1,1,topp,t[x],x);
	else
	    ans[x]=ask(1,1,topp,t[x],x);
    }
    for(int i=1;i<=m;i++) printf("%d ",(ans[n+i]==MAXN)?-1:ans[n+i]);
}
