#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m,l,c[200005],cmax,x,y,z,fa[200005],col[200005][55],colz[200005][55];
long long sum,ans;
vector<pair<int,pair<int,int> > > q;
int find(int x){ return fa[x]=(fa[x]==x)?x:find(fa[x]); }
int spfa(){
    for(int i=1;i<=n;i++){}
}
int main(){
//freopen("graph.in","r",stdin);
//freopen("graph.out","w",stdout);
    scanf("%d%d%d",&n,&m,&l);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]),cmax=max(cmax,c[i]);
    for(int i=1;i<=m;i++) {
	scanf("%d%d%d",&x,&y,&z);
	q.push_back(make_pair(z,make_pair(x,y)));
    }
    if(cmax>50&&l) return spfa();
    sort(q.begin(),q.end());
    int size[200005];
    memset(col,0,sizeof(col));
    for(int i=1;i<=n;i++){
	size[i]=1;
	if(cmax<=50) {
	    col[i][c[i]]=1;
	    for(int j=c[i];j<=cmax;j++) colz[i][j]=1;
	}
	fa[i]=i;
    }
    for(int i=0;i<m;i++){
	x=find(q[i].second.first);
	y=find(q[i].second.second);
	if(x==y) continue;
	fa[x]=y;
	if(cmax<=50){
	    long long sum=0;
	    for(int j=l;j<=cmax;j++)
		sum+=1ll*colz[y][j-l]*col[x][j],
		sum+=1ll*colz[x][j-l]*col[y][j],
		sum-=1ll*col[x][j]*col[y][j];
	    ans+=1ll*q[i].first*sum;
	    for(int j=0;j<=cmax;j++)
		col[y][j]+=col[x][j],
		colz[y][j]+=colz[x][j];
	    continue;
	}
	if(l==0)  ans+=1ll*q[i].first*size[x]*size[y];
	size[y]+=size[x];
    }
    printf("%lld",ans);
}
