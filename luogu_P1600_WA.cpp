#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,x,y,fa[300005][25],sum1[600005],sum2[600005],f[300005];
long long ans;
int first[600005],nxt[600005],go[600005],deep[600005],w[600005],z,tot;
vector<pair<int,int> > v1[300005];
vector<pair<int,int> > v2[300005];
int add(int x,int y){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y;
}
int _dfs(int x,int father){
    deep[x]=deep[father]+1;
    fa[x][0]=father;
    for(int i=1;i<=20;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father)
	    _dfs(go[i],x);
}

int lca(int x,int y){
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=20;i>=0;i--)
	if(deep[fa[x][i]]>=deep[y])
	    x=fa[x][i];
    if(x==y) return x;
    for(int i=20;i>=0;i--)
	if(fa[x][i]!=fa[y][i])
	    x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}

int dfs(int x,int father){
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father)
	    dfs(go[i],x);
    for(int i=0;i<v1[x].size();i++)
	sum1[v1[x][i].first+deep[x]]+=v1[x][i].second;
    for(int i=0;i<v2[x].size();i++)
	sum2[v2[x][i].first-deep[x]+300000]+=v2[x][i].second;
    f[x]=sum1[w[x]+deep[x]];
    f[x]+=sum2[w[x]-deep[x]+300000];
    //printf("%d %d\n",x,f[x]);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
	scanf("%d%d",&x,&y);
	add(x,y);
	add(y,x);
    }
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    _dfs(1,0);
    for(int i=1;i<=m;i++){
	scanf("%d%d",&x,&y);
	z=lca(x,y);
	v1[x].push_back(make_pair(0,1));
	v2[y].push_back(make_pair(deep[x]+deep[y]-deep[z]*2,1));
	v1[z].push_back(make_pair(deep[x]-deep[z],-1));
	v2[fa[z][0]].push_back(make_pair(deep[x]-deep[z]-1,-1));
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) printf("%d ",f[i]);
}
