#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int b[100],map,n,k,tot,flag,ans,flag2,su;
vector<pair<int,int> > s[100];
int dfs(int x){
    b[x]=1;int sum=0;
    for(int i=0;i<s[x].size();i++)
	if(((1<<s[x][i].first)&map)&&(!b[s[x][i].second]))
	    sum+=dfs(s[x][i].second);
    return sum+1;
}
int main(){
    freopen("bomb2.in","r",stdin);
    freopen("bomb.out","w",stdout);
    scanf("%d%d",&n,&k);tot=-1;
    if(k==1) return printf("1"),0;
    for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	    s[i].push_back(make_pair(++tot,j)),
	    s[j].push_back(make_pair(tot,i));
    for(map=0;map<(1<<(tot+1));map++){
	memset(b,0,sizeof(b));
	flag=1;flag2=0;
	for(int j=1;j<=n;j++){
	    if(b[j]) continue;
	    su=dfs(j);
	    if(su>k) { flag=0; break;}
	    if(su==k) flag2=1;
	}
	ans+=flag&flag2;
	//printf("%d %d %d\n",map,flag,flag2);
    }
    printf("%d",ans);
}
