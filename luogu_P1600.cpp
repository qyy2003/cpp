#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,x,y,fa[300005][25],f[300005],root1[600000],root2[600000],top;
int first[600005],nxt[600005],go[600005],deep[600005],w[600005],z,tot;
int son1[20000000][2],tr1[20000000],son2[20000000][2],tr2[20000000],sz1,sz2;
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

int insert1(int &x,int l,int r,int qi,int cha){
    son1[++sz1][0]=son1[x][0]; son1[sz1][1]=son1[x][1]; tr1[sz1]=tr1[x]; x=sz1;
    if(l==r) return tr1[x]+=cha;
    if(qi>((l+r)>>1)) return tr1[x]=tr1[son1[x][0]]+insert1(son1[x][1],((l+r)>>1)+1,r,qi,cha);
    return tr1[x]=tr1[son1[x][1]]+insert1(son1[x][0],l,(l+r)>>1,qi,cha);
}

int ask1(int x,int y,int l,int r,int qi){
    if(l==r) return tr1[x]-tr1[y];
    if(qi>((l+r)>>1)) return ask1(son1[x][1],son1[y][1],((l+r)>>1)+1,r,qi);
    return ask1(son1[x][0],son1[y][0],l,(l+r)>>1,qi);
}

int insert2(int &x,int l,int r,int qi,int cha){
    son2[++sz2][0]=son2[x][0]; son2[sz2][1]=son2[x][1]; tr2[sz2]=tr2[x]; x=sz2;
    if(l==r) return tr2[x]+=cha;
    if(qi>((l+r)>>1)) return tr2[x]=tr2[son2[x][0]]+insert2(son2[x][1],((l+r)>>1)+1,r,qi,cha);
    return tr2[x]=tr2[son2[x][1]]+insert2(son2[x][0],l,(l+r)>>1,qi,cha);
}

int ask2(int x,int y,int l,int r,int qi){
    if(l==r) return tr2[x]-tr2[y];
    if(qi>((l+r)>>1)) return ask2(son2[x][1],son2[y][1],((l+r)>>1)+1,r,qi);
    return ask2(son2[x][0],son2[y][0],l,(l+r)>>1,qi);
}

int dfs(int x,int father){
    int l=top;
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father)
	    dfs(go[i],x);
    ++top;
    root1[top]=++sz1;
    son1[root1[top]][0]=son1[root1[top-1]][0];
    son1[root1[top]][1]=son1[root1[top-1]][1];
    root2[top]=++sz2;
    son2[root2[top]][0]=son2[root2[top-1]][0];
    son2[root2[top]][1]=son2[root2[top-1]][1];
    for(int i=0;i<v1[x].size();i++)
	insert1(root1[top],1,600000,v1[x][i].first+deep[x],v1[x][i].second);
    for(int i=0;i<v2[x].size();i++)
	insert2(root2[top],1,600000,v2[x][i].first-deep[x]+300000,v2[x][i].second);
    f[x]=ask1(root1[top],root1[l],1,600000,w[x]+deep[x]);
    f[x]+=ask2(root2[top],root2[l],1,600000,w[x]-deep[x]+300000);
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
