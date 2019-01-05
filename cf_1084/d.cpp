#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
long long n,w[1000000],x,y,z,tot,nxt[1000000],val[1000000],go[1000000],first[1000000],maxa;
void add(long long x,long long y,long long z){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y; val[tot]=z;
}
int dfs(int x,int father){
    long long sum=0;
    for(long long i=first[x];i;i=nxt[i]){
	if(go[i]==father) continue;
	dfs(go[i],x);
	//if(w[go[i]]-val[i]>0ll) w[x]+=w[go[i]]-val[i];
	//sum=max(sum,w[go[i]]-val[i]);
	maxa=max(maxa,w[x]+sum+w[go[i]]-val[i]);
	sum=max(sum,w[go[i]]-val[i]);
    }
    w[x]+=sum;
    return 0;
}
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
    for(int i=1;i<n;i++){
	scanf("%lld%lld%lld",&x,&y,&z);
	add(x,y,z);
	add(y,x,z);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) maxa=max(maxa,w[i]);
    printf("%lld",maxa);
    return 0;
}
