#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXA=1e5+7;
int n,m,fa[MAXA][25],e[MAXA],faa[MAXA],x,y,z,deep[MAXA],ans[MAXA];
vector<pair<int,pair<int,int> >  >q; 
vector<pair<int,int> >go[MAXA];
int dfs(int x,int father){
    deep[x]=deep[father]+1;
    fa[x][0]=father;
    faa[x]=father;
    for(int i=1;i<=20;i++)
	fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=0;i<go[x].size();i++)
	if(go[x][i].first!=father)
	    dfs(go[x][i].first,x),e[go[x][i].first]=go[x][i].second;
}

int find(int x){
    if(~ans[e[x]])  x=faa[x]=find(faa[x]);
    return x;
}

int LCA(int x,int y){
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

int lca(int x,int y,int z){
    int father=LCA(x,y);
   // printf("%d %d %d!\n",x,y,father);
    x=find(x);
    while(deep[x]>deep[father]){
//	printf("%d ",x);
	ans[e[x]]=z;
	faa[x]=father;
	x=fa[x][0];
	x=find(x);
    }
    y=find(y);
  //  printf("!\n");
    while(deep[y]>deep[father]){
//	printf("%d ",y);
	ans[e[y]]=z;
	faa[y]=father;
	y=fa[y][0];
	y=find(y);
    }
  //  printf("!\n");
}

int main(){
    freopen("worry.in","r",stdin);
    freopen("worry.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
	scanf("%d%d",&x,&y);
	go[x].push_back(make_pair(y,i));
	go[y].push_back(make_pair(x,i));
    }
    dfs(1,0);
    for(int i=0;i<m;i++){
	scanf("%d%d%d",&x,&y,&z);
	q.push_back(make_pair(z,make_pair(x,y)));
    }
    sort(q.begin(),q.end());
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<m;i++)lca(q[i].second.first,q[i].second.second,q[i].first);
    for(int i=1;i<n;i++)printf("%d\n",ans[i]);
}
