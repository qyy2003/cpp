#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define inf 2147483640
#define Pi acos(-1.0)
#define free(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout);
using namespace std;
   
const int maxn=20010;
struct tree {int l,r,len,ls,rs,num,cov;}tr[maxn<<2];
struct data {int x,l,r,val;}a[maxn];
int n;
  
void build(int k,int s,int t) {
    tr[k].l=s;tr[k].r=t;
    if (s==t) return;
    int mid=(s+t)>>1;
    build(k<<1,s,mid);
    build(k<<1|1,mid+1,t);
}
void merge(int k) {
    int l=tr[k].l,r=tr[k].r;
    if (tr[k].cov) {
        tr[k].ls=tr[k].rs=1;
        tr[k].num=2;
        tr[k].len=r-l+1;
    }
    else if (l==r) tr[k].ls=tr[k].rs=tr[k].len=tr[k].num=0;
    else {
        tr[k].num=tr[k<<1].num+tr[k<<1|1].num;
        tr[k].len=tr[k<<1].len+tr[k<<1|1].len;
        tr[k].ls=tr[k<<1].ls;tr[k].rs=tr[k<<1|1].rs;
        if (tr[k<<1].rs && tr[k<<1|1].ls) tr[k].num-=2;
    }
}
void update(int k,int s,int t,int val) {
    int l=tr[k].l,r=tr[k].r,mid=(l+r)>>1;
    if (s<=l && t>=r) {tr[k].cov+=val;merge(k);return;}
    if (s<=mid) update(k<<1,s,t,val);
    if (t>mid) update(k<<1|1,s,t,val);
    merge(k);
}
bool cmpx(data a,data b) {
    return a.x<b.x;
}
int main() {
    scanf("%d",&n);
    int m=0,l=inf,r=-inf;
    for (int x1,x2,y1,y2,i=1;i<=n;i++) {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        l=min(l,y1);r=max(r,y2);
        a[++m]=(data){x1,y1,y2,1};a[++m]=(data){x2,y1,y2,-1};
    }
    n=m;
    build(1,l,r-1);
    sort(a+1,a+1+n,cmpx);
    int ans=0;
    for (int i=1;i<=n;i++) {
        int tmp=tr[1].len;
        //if (i!=1) ans+=tr[1].num*(a[i].x-a[i-1].x);
        update(1,a[i].l,a[i].r-1,a[i].val);
        ans+=abs(tr[1].len-tmp);
	printf("%d %d\n",tmp,ans);
    }
    printf("%d",ans);
    return 0;
}
