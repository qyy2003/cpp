#include<cstdio>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
int f[1000][1000],a[1000],d[1000],b[1000],n,ans;
queue<pair<int,int> > v;
priority_queue<pair<int,int> > q;
pair<int,int> x;
int dfs(int x){
    b[x]=1;
    for(int i=1;i<=n;i++)
	if(f[x][i]&&(!b[i]))
	    dfs(i);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	    f[i][j]=1;
    for(int i=1;i<=n/2;i++) swap(a[i],a[n-i+1]);
    for(int i=1;i<=n;i++) {d[i]=n-i-a[i]; if(d[i]>0)q.push(make_pair(d[i],i));}
    for(int i=1;i<=n;i++){
	    while(d[i]<0){
		x=q.top(); q.pop(); 
		if(f[x.second][i]==0) {v.push(x); continue;}
		v.push(make_pair(x.first-1,x.second));
		f[i][x.second]=1; f[x.second][i]=0; d[i]++;
	    }
	    while(!v.empty()) q.push(v.front()),v.pop();
	}
//    for(int i=1;i<=n;i++,printf("\n"))
//	for(int j=1;j<=n;j++)
//	    printf("%d ",f[i][j]);
    for(int i=1;i<=n;i++){
	dfs(i);
	for(int i=1;i<=n;i++)
	    ans+=b[i],b[i]=0;
    }
    printf("%d",ans);
}

