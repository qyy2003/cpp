#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,x,y,z,fa[100100];
long long ans;
vector<pair<int,pair<int,int> > >q;
int find(int x) { return fa[x]=(x==fa[x])?x:find(fa[x]);}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
	scanf("%d%d%d",&x,&y,&z);
	q.push_back(make_pair(z,make_pair(x,y)));
    }
    sort(q.begin(),q.end());
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=0;i<m;i++){
	x=find(q[i].second.first);
	y=find(q[i].second.second);
	if(x==y) continue;
	fa[x]=y;
	ans+=q[i].first;
    }
    printf("%lld",ans);
}
