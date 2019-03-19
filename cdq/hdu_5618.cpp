#include<bits/stdc++.h>
using namespace std;
const int MAXA=1e5+7;
int n;
class Fenwick{
    public:
    int tr[MAXA<<1];
    void clear(){
	memset(tr,0,sizeof tr);
    }
    void add(int x,int v){
	if(x>MAXA) return;
	tr[x]+=v;
	x+=x&(-x);
	add(x,v);
    }
    int ask(int x){
	if(x==0) return 0;
	return tr[x]+ask(x-(x&(-x)));
    }
}T;
class Node{
    public:
    int x,y,z,f,pos;
    Node(){x=0;y=0;z=0;}
    void read(int xx){
	scanf("%d%d%d",&x,&y,&z);f=0;pos=xx;
    }
}a[MAXA<<1],b[MAXA<<1];
int mysort(Node x,Node y){
    return x.x<y.x;
}
int mysort0(Node x,Node y){
    if(x.x!=y.x) return x.x<y.x;
    if(x.y!=y.y) return x.y<y.y;
    if(x.z!=y.z) return x.z<y.z;
    return x.f<y.f;
}
int mysort1(Node x,Node y){
    return x.pos<y.pos;
}
void work(int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1;
    work(l,mid);work(mid+1,r);
    int top=l-1,le=l;
    //printf("%d %d\n",l,r);
    //fflush(stdout);
    for(int i=mid+1;i<=r;i++){
	while(l<=mid&&a[l].y<=a[i].y){
	    T.add(a[l].z,1);
	    b[++top]=a[l];
	    l++;
	}
	a[i].f+=T.ask(a[i].z);
	b[++top]=a[i];
    }
    l=le;
    for(int i=mid+1;i<=r;i++){
	while(l<=mid&&a[l].y<=a[i].y){
	    T.add(a[l].z,-1);
	    l++;
	}
    }
    while(l<=mid) b[++top]=a[l++];
    //for(int i=le;i<=r;i++) printf("$%d %d %d\n",i,a[i].pos,a[i].f);
    for(int i=le;i<=r;i++) a[i]=b[i];
    //for(int i=le;i<=r;i++) printf("$$%d %d %d\n",i,a[i].pos,a[i].f);
}

void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) a[i].read(i);
    sort(a+1,a+n+1,mysort0);
    //for(int i=1;i<=n;i++) printf("%d ",a[i].x);
    work(1,n);
    sort(a+1,a+n+1,mysort0);
    for(int i=n-1;i;i--)
	if(a[i].x==a[i+1].x&&a[i].y==a[i+1].y&&a[i].z==a[i+1].z)
	    a[i].f=a[i+1].f;
    sort(a+1,a+n+1,mysort1);
    for(int i=1;i<=n;i++) printf("%d\n",a[i].f);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
	solve();
    }
}
