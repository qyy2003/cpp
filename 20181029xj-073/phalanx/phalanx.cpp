#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int n,m,x,y,visy[10000],mx[10000],my[10000];
vector<int> go[10000];
int dfs(int s){
    for(int i=0;i<go[s].size();i++){
	int t=go[s][i];
	if(visy[t]) continue;
	visy[t]=1;
	if(my[t]==-1||dfs(my[t])){
	    my[t]=s;
	    mx[s]=t;
	    return 1;
	}
    }
    return 0;
}
int max_match(){
    memset(mx,-1,sizeof(mx));
    memset(my,-1,sizeof(my));
    int ans=0;
    for(int i=1;i<=n;i++){
	memset(visy,0,sizeof(visy));
	if(dfs(i)) ans++;
    }
    return ans;
}
int main(){
    freopen("phalanx.in","r",stdin);
    freopen("phalanx.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
	scanf("%d%d",&x,&y);
	go[x].push_back(y);
    }
    printf("%d",n*(n*2-max_match()));
}
