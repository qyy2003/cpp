#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=1e9+7;
const int MAXA=2e5;
int n,m,tot,b[MAXA];
char s[1000];
class Fenwick{
    public:
    int tr[MAXA<<1];
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

class Operator{
    public:
    int l,r,k,type,pos,val,ad;
    void clear(){
	l=r=k=type=pos=val=ad=0;
    }
    void print(){
	printf("l=%d r=%d k=%d type=%d pos=%d val=%d\n",l,r,k,type,pos,val);
	return;
    }
}a[MAXA],c1[MAXA],c2[MAXA];

int mysort(Operator x,Operator y){
    return x.pos<y.pos;
}

int work(int l,int r,int L,int R){
    if(L>R||l>r) return 0;
    if(L==R){
	for(int i=l;i<=r;i++) a[i].val=L;
	return 0;
    }
    int Mid=(L+R)>>1,tot1=0,tot2=0;
    for(int i=l;i<=r;i++)
	if(a[i].type){
	    if(T.ask(a[i].r)-T.ask(a[i].l-1)>=a[i].k) c1[++tot1]=a[i];
	    else c2[++tot2]=a[i],c2[tot2].k-=(T.ask(a[i].r)-T.ask(a[i].l-1));
	}else{
	    if(a[i].val<=Mid) T.add(a[i].pos,a[i].ad),c1[++tot1]=a[i];
	    else c2[++tot2]=a[i];
	}
    for(int i=1;i<=tot1;i++) 
	if(!c1[i].type)
	    T.add(c1[i].pos,-c1[i].ad);
    for(int i=1;i<=tot1;i++) a[l+i-1]=c1[i];
    for(int i=1;i<=tot2;i++) a[l+tot1+i-1]=c2[i];
    //printf("$%d %d %d %d %d %d\n",l,r,L,R,tot1,tot2);
    //for(int i=l;i<=r;i++) a[i].print();
    //fflush(stdout);
    work(l,l+tot1-1,L,Mid); work(l+tot1,r,Mid+1,R);
}

void solve(){
    int x,y;tot=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
	scanf("%d",&x);
	a[++tot].clear();
	a[tot].val=x;
	a[tot].type=0;
	a[tot].ad=1;
	a[tot].pos=tot;
	b[i]=x;
    }
    for(int i=1;i<=m;i++){
	scanf("%s",s);
	if(s[0]=='Q'){
	    a[++tot].clear();a[tot].pos=tot;a[tot].ad=1;a[tot].type=1;
	    scanf("%d%d%d",&a[tot].l,&a[tot].r,&a[tot].k);
	}
	else{
	    scanf("%d%d",&x,&y);
	    a[++tot].clear();a[tot].ad=-1;a[tot].val=b[x]; b[x]=y;a[tot].pos=x;
	    a[++tot].clear();a[tot].ad=1;a[tot].val=y;a[tot].pos=x;
	}
    }
    //for(int i=1;i<=tot;i++) a[i].print();
    work(1,tot,-INF,INF);
    sort(a+1,a+tot+1,mysort);
    for(int i=1;i<=tot;i++) 
	if(a[i].type)
	    printf("%d\n",a[i].val);
}

int main(){
    int t;
	scanf("%d",&t);
	while(t--) solve();
}
