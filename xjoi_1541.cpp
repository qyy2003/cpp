#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int n,fa[10000],ans,sum,x,y;
vector<pair<int,pair<int,int> > >q;
int find(int x){ return fa[x]=(x==fa[x])?x:find(fa[x]);}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;fa[i]=i,i++)
	for(int j=1;j<=n;j++){
	    scanf("%d",&x);
	    if(j>i)
		q.push_back(make_pair(x,make_pair(i,j)));
	    }
    sort(q.begin(),q.end());
    n=q.size();
    for(int i=0;i<n;i++){
	x=find(q[i].second.second);
	y=find(q[i].second.first);
	if(x==y) continue;
	if(q[i].first) sum++;
	ans+=q[i].first;
	fa[x]=y;
    }
    printf("%d\n%d",sum,ans);
}
