#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,x,maxa,fa[10000],deep[10000];
vector<int> go[1005];
vector<int> q;
int dfs(int x,int father){
    fa[x]=father;deep[x]=deep[father]+1;
    for(int i=0;i<go[x].size();i++)
	if(go[x][i]!=father)
	    dfs(go[x][i],x);
}
int redfs(int x){
    if(deep[x]==(deep[maxa]+1)/2||deep[x]==(deep[maxa]+2)/2) q.push_back(x);
    if(x!=0) redfs(fa[x]);
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
	scanf("%d",&x);
	go[x].push_back(i);
	go[i].push_back(x);
    }
    dfs(1,0);
    maxa=1;
    for(int i=1;i<=n;i++) 
	if(deep[maxa]>deep[i])
	    maxa=i;
    deep[maxa]=0;
    dfs(maxa,0);
    for(int i=1;i<=n;i++)
	if(deep[maxa]>deep[i])
	    maxa=i;
    printf("%d",(deep[maxa]+1)/2);
    redfs(maxa);
    sort(q.begin(),q.end());
    for(int i=0;i<q.size();i++)
	printf("%d ",q[i]);
}
