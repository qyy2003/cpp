#include<bits/stdc++.h>
using namespace std;
int n,x;
int kkk[200];
vector<int>a,b;
bool vis[20];
void dfs(vector<int> now){
    if (now.size()==1){
	vis[now[0]]=true;
	return;
    }
    for (int i=0;i<now.size()-1;++i){
	b.clear();
	for (int j=0;j<i;++j) b.push_back(now[j]);
	b.push_back((now[i]+now[i+1])/2);
	for (int j=i+2;j<now.size();++j) b.push_back(now[j]);
	dfs(b);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&x),a.push_back(x);
    dfs(a);
    for (int i=0;i<=7;++i) if (vis[i]) printf("%d ",i);
}
