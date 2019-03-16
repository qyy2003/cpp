#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXA=4e6;
int tr[MAXA<<3],trr[MAXA<<3],trl[MAXA<<3],tot;
int a[MAXA],pos[MAXA],root[MAXA],c[MAXA];
int n;
int neww(){
    tr[++tot]=0;trl[tot]=0;trr[tot]=0;return tot;
}
int neww(int x){
    tr[++tot]=tr[x];trl[tot]=trl[x];trr[tot]=trr[x];return tot;
}
int build(int &x,int l,int r){
    x=neww();
    if(l==r) return 0;
    int mid=(l+r)>>1;
    return build(trl[x],l,mid)+build(trr[x],mid+1,r);
}
int ad(int &x,int y,int l,int r,int val){
    x=neww(y);tr[x]=tr[y]+1;
    //printf("%d %d %d %d %d %d %d\n",tr[x],tr[y],trl[y],trr[y],l,r,val);
    if(l==r) return tr[x];
    int mid=(l+r)>>1;
    if(val<=mid) ad(trl[x],trl[y],l,mid,val);
    else ad(trr[x],trr[y],mid+1,r,val);
    return tr[x];
}
int ask(int x,int y,int l,int r,int val){
    //printf("%d %d %d %d %d %d %d\n",tr[x],tr[y],tr[trl[x]],tr[trl[y]],l,r,val);
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(tr[trl[x]]-tr[trl[y]]>=val) return ask(trl[x],trl[y],l,mid,val);
    else return ask(trr[x],trr[y],mid+1,r,val-tr[trl[x]]+tr[trl[y]]);
}
int mysort(int x,int y){
    return a[x]<a[y];
}
void solve(){
    int m,ll,rr,k;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) c[i]=i;
    sort(c+1,c+n+1,mysort);
    for(int i=1;i<=n;i++) pos[c[i]]=i;
    //for(int i=1;i<=n;i++) printf("%d ",pos[i]);
    sort(a+1,a+n+1);
    build(root[0],1,n);
    for(int i=1;i<=n;i++){
	ad(root[i],root[i-1],1,n,pos[i]);
    }
    while(m--){
	scanf("%d%d%d",&ll,&rr,&k);
	printf("%d\n",a[ask(root[rr],root[ll-1],1,n,k)]);
    }
    tot=0;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}
