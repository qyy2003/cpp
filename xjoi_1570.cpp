#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n1,n2,m,vv,x,y,visy[1000],my[1000],mx[1000];
vector<int> go[1000];
int dfs(int x){
    int nn=go[x].size();
    for(int i=0;i<nn;i++){
	int v=go[x][i];
	if(visy[v]!=-1) continue;
	visy[v]=1;
	if((my[v]==-1)||dfs(my[v])){
	    mx[x]=v;
	    my[v]=x;
	    return 1;
	}
    }
    return 0;
}
int max_match(){
    memset(my,-1,sizeof(my));
    memset(mx,-1,sizeof(mx));
    int ans=0;
    for(int i=1;i<=n1;i++){
	memset(visy,-1,sizeof(visy));
	if(dfs(i))
	    ans++;
    }
    return ans;
}
int main(){
    scanf("%d%d%d%d",&vv,&n1,&n2,&m);
    for(int i=1;i<=m;i++){
	scanf("%d%d",&x,&y);
	go[x].push_back(y);
    }
    printf("%d",min(n1+n2-max_match(),vv+1));
}
