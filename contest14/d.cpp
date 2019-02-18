#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
const int MAXA=2e6;
int a[MAXA],b[MAXA],c[MAXA],d[MAXA],ans[MAXA];
int first[MAXA],nxt[MAXA],go[MAXA],id[MAXA],low[MAXA],dfn[MAXA],sum[MAXA];
int fa[MAXA],bo[MAXA],s[MAXA];
int n,m,x,top,tot,tott;
int faa(int x){
    return (fa[x]==x)?x:fa[x]=faa(fa[x]);
}
int mysort(int x,int y){
    return c[x]<c[y];
}
int add(int x,int y,int z){
    nxt[++tot]=first[x];first[x]=tot; go[tot]=y; id[tot]=z;
}
int dfs(int x,int father){
    if(dfn[x]) return dfn[x];
    dfn[x]=low[x]=++tott;
    for(int i=first[x];i;i=nxt[i])
	if(go[i]==father&&sum[go[i]]==0)sum[go[i]]++;
	else{
	    sum[x]=0;
	    low[x]=min(low[x],dfs(go[i],x));
	    //printf("$%d %d %d %d %d\n",x,go[i],id[x],dfn[go[i]],low[go[i]]);
	    if(dfn[x]<low[go[i]]) ans[id[i]]=1;
	}
    //printf("%d %d %d\n",x,dfn[x],low[x]);
    return low[x];
}
int update(int x){
    first[x]=0; dfn[x]=0; low[x]=0;
}
int work(){
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
	x=d[i];
	a[x]=faa(a[x]);
	b[x]=faa(b[x]);
	//printf(" %d %d %d\n",x,a[x],b[x]);
	if(a[x]==b[x]) ans[x]=-1;
	else{
	add(a[x],b[x],x);
	add(b[x],a[x],x);
	s[++top]=x;
	}
	if(c[d[i]]!=c[d[i+1]]){
	  //  printf("----------------%d\n",x);
	    for(int i=1;i<=top;i++) dfs(a[s[i]],0);
	    for(int i=1;i<=top;i++) update(a[s[i]]),update(b[s[i]]);
	    for(int i=1;i<=top;i++)
		if(faa(a[s[i]])!=faa(b[s[i]]))
		    fa[faa(a[s[i]])]=faa(b[s[i]]);
	    tot=0;
	    tott=0;
	    top=0;
	}
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
	scanf("%d%d%d",&a[i],&b[i],&c[i]);
	d[i]=i;
    }
    sort(d+1,d+m+1,mysort);
    work();
    for(int i=1;i<=m;i++){
	if(ans[i]==-1) printf("none\n");
	else if(!ans[i]) printf("at least one\n");
	     else printf("any\n");
    }
}
