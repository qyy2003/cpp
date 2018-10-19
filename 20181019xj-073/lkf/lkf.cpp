#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXA=5000;
int n,m,x,y,a[MAXA],b[MAXA];
int nxt[MAXA<<1],first[MAXA],go[MAXA<<1],tot;
long long ans,P=19260817;
vector<pair<int,int> >q;
int add(int x,int y){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y;
}
int dfs(int x,int father,int z){
    long long anss=1;
    for(int i=first[x];~i;i=nxt[i])
	if(go[i]!=father&&b[go[i]]&&a[go[i]]>=z)
	    anss=anss*dfs(go[i],x,z)%P;
    //printf("%d %d %d %lld\n",x,father,z,anss);
    return (anss+1)%P;
}
int main(){
    freopen("lkf.in","r",stdin);
    freopen("lkf.out","w",stdout);
    memset(first,-1,sizeof(first));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	q.push_back(make_pair(a[i],i));
    }
    sort(q.begin(),q.end());
    for(int i=1;i<n;i++){
	scanf("%d%d",&x,&y);
	add(x,y);add(y,x);
    }
    for(int i=0;i<n;i++){
	if(m) ans=(ans+dfs(q[i].second,-1,q[i].first-m)-dfs(q[i].second,-1,q[i].first-m+1)+P)%P;
	else ans=(ans+dfs(q[i].second,-1,q[i].first)-1+P)%P;
	b[q[i].second]=1;
    }
    printf("%lld",ans);
}
