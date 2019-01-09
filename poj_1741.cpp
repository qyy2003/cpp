#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXA=1e5;
const int MAXN=1e7+1e4;
long long ans;
int n,m,x,tot,l,r,top1,top2;
int first[MAXA],nxt[MAXA],val[MAXA],go[MAXA],que[MAXA],b[MAXA],fa[MAXA],zx[MAXA],siz[MAXA],tree[MAXN+10],bb[MAXA],que1[MAXA],que2[MAXA];
void add(int x,int y,int z){
    nxt[++tot]=first[x];first[x]=tot;go[tot]=y;val[tot]=z;
}
int ask(int x){
    if(x<0) return 0;
    int ans=1;
    while(x>0){
	ans+=tree[x];
	x-=x&(-x);
    }
    return ans;
}
void ad(int x,int y){
    if(x<=0) return;
    while(x<=MAXN){
	//printf("$%d ",x);
	//fflush(stdout);
	tree[x]+=y;
	x+=x&(-x);
    }
}
int dfs(int x,int father,int y){
    if(bb[x]) return 0;
    //printf("!%d %d %d\n",x,father,y);
    //fflush(stdout);
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father)
	    dfs(go[i],x,y+val[i]);
    ans+=ask(m-y);
    que1[++top1]=y;
    que2[++top2]=y;
    return 0;
}
int bfs(int x);
int work(int x,int father){
    if(bb[x]) return 0;
    x=bfs(x);
    //printf("%d %d\n",x,father);
    //fflush(stdout);
    bb[x]=1;
    for(int i=first[x];i;i=nxt[i]){
	if(go[i]==father) continue;
	dfs(go[i],x,val[i]);
	while(top2){
	    ad(que2[top2],1);
	    top2--;
	}
    }
    while(top1){
	ad(que1[top1],-1);
	top1--;
    }
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father)
	    work(go[i],x);
    return 0;
}
int bfs(int x){
    int now;
    l=r=0;
    que[++r]=x;
    b[x]=1;
    while(l<r){
	now=que[++l];;
	siz[now]=0;
	for(int i=first[now];i;i=nxt[i]){
	    if((!bb[go[i]])&&(!b[go[i]])){
		b[go[i]]=1;
		que[++r]=go[i];
		fa[go[i]]=now;
	    }
	}
    }
    for(int i=l;i>=1;i--){
	b[que[i]]=0;
	siz[que[i]]++;
	siz[fa[que[i]]]+=siz[que[i]];
	zx[que[i]]=que[i];
    }
    for(int i=l;i>=1;i--)
	if(siz[que[i]]*2>siz[fa[que[i]]]){
	    for(zx[fa[que[i]]]=zx[que[i]];siz[zx[fa[que[i]]]]*2<siz[fa[que[i]]];zx[fa[que[i]]]=fa[zx[fa[que[i]]]]);
	}
    return zx[x];
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF&&(n+m!=0)){
    memset(first,0,sizeof(first));
    memset(bb,0,sizeof(bb));
    tot=0; ans=0;
    int x,y,z;
    for(int i=2;i<=n;i++){
	scanf("%d%d%d",&x,&y,&z);
	add(x,y,z);
	add(y,x,z);
    }
    work(1,0);
    printf("%lld\n",ans);
    }
    return 0;
}
