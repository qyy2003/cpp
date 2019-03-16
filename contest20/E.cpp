#include<bits/stdc++.h>
using namespace std;
const int MAXA=1e6;
int q[2][MAXA];
int n,rr[2],flag=0;
class Tr{
    public:
    int n,fl;
    int first[MAXA],nxt[MAXA],go[MAXA],tot,e[MAXA];
    int deep[MAXA],son[MAXA],dfn[MAXA],top[MAXA],fa[MAXA],siz[MAXA],dfnn;
    int anss[MAXA],tops,b[MAXA];
    vector<int>v[MAXA<<2];
    void add(int x,int y){
	nxt[++tot]=first[x]; first[x]=tot; go[tot]=y;
    }
    int pre_dfs(int x,int father){
	for(int i=first[x];i;i=nxt[i]){
	    siz[x]+=pre_dfs(go[i],x);
	    if(siz[go[i]]>siz[son[x]]) son[x]=go[i];
	}
	return ++siz[x];
    }
    void dfs(int x,int father){
	deep[x]=deep[father]+1; dfn[x]=++dfnn; fa[x]=father;
	if(son[x]){ top[son[x]]=top[x]; dfs(son[x],x);}
	for(int i=first[x];i;i=nxt[i]){
	    if(go[i]==son[x]) continue;
	    top[go[i]]=go[i];
	    dfs(go[i],x);
	}
    }
    void test(){
//	for(int i=1;i<=n;i++) printf("$%d %d %d\n",fl, top[i],dfn[i]);
    }
    void scan(){
	for(int i=1;i<n;i++){
	    scanf("%d",&e[i]);
	    add(e[i],i+1);
	}
	pre_dfs(1,0);
	top[1]=1;
	dfs(1,0);
	test();
    }
    int ad(int x,int l,int r,int ll,int rr,int val){
	if(rr<l||ll>r) return 0;
	if(ll<=l&&rr>=r){
	    v[x].push_back(val);
	    return 0;
	}
	int mid=(l+r)>>1;
	return ad(x<<1,l,mid,ll,rr,val)+ad(x<<1|1,mid+1,r,ll,rr,val);
    }
    int ask(int x,int l,int r,int pos){
	int mid=(l+r)>>1,len=v[x].size();
	for(int i=0;i<len;i++) if(!b[v[x][i]]) q[fl^1][++rr[fl^1]]=v[x][i],b[v[x][i]]=1;
	v[x].clear();
	if(l==r) return 0;
	if(pos<=mid) ask(x<<1,l,mid,pos);
	else ask(x<<1|1,mid+1,r,pos);
    }
    int mark(int x,int y,int z){
	if(deep[top[x]]<deep[top[y]]||(top[x]==top[y]&&deep[x]<deep[y])) swap(x,y);
//	printf("%d %d %d\n",x,y,z);
	if(top[x]==top[y]) return ad(1,1,n,dfn[y]+1,dfn[x],z);
	ad(1,1,n,dfn[top[x]],dfn[x],z);
	return mark(fa[top[x]],y,z);
    }
    /*
    void del(){
	tops=0;
	ask(1,1,n,dfn[x]);
	if(!tops) return;
	sort(anss+1,anss+1+tops);
	if(fl^1) printf("Red\n"); else printf("Blue\n");
	for(int i=1;i<=tops;i++) printf("%d ",anss[i]);
	for(int i=1;i<=tops;i++) q[++r]=make_pair(fl^1,anss[i]);
	printf("\n");
    }*/
}tree[2];
int main(){
    scanf("%d",&n);
    tree[0].n=tree[1].n=n;tree[0].fl=0;tree[1].fl=1;
    tree[0].scan();
    tree[1].scan();
    for(int i=1;i<n;i++){
	tree[1].mark(i+1,tree[0].e[i],i);
	tree[0].mark(i+1,tree[1].e[i],i);
    }
    int x,x1,x2;
    scanf("%d",&x);
    tree[1].b[x]=1;
    q[0][++rr[0]]=x;
    while(1){
	if(flag) printf("Red\n"); else printf("Blue\n");
	for(int i=1;i<=rr[flag];i++) printf("%d ",q[flag][i]);
	printf("\n");
	//tree[flag^1].tops=0;
	rr[flag^1]=0;
	for(int i=1;i<=rr[flag];i++)
	    tree[flag].ask(1,1,n,tree[flag].dfn[q[flag][i]+1]);
	flag^=1;
	if(!rr[flag]) break;
	sort(q[flag]+1,q[flag]+1+rr[flag]);
    }
}
