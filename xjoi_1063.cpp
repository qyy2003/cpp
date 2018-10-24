#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;
const int MAXA=5*1e6+7;
int s,t,n,m,x,y,z,tot,cnt[MAXA];
int f[MAXA],first[MAXA],nxt[MAXA<<1],go[MAXA<<1],val[MAXA<<1],b[MAXA],fa[MAXA];
queue<int>q;
int add(int x,int y,int z){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y; val[tot]=z;
}
int print(int x){
    if(x!=s) print(fa[x]);
    printf("%lld ",x);
}
main(){ 
    scanf("%lld%lld",&s,&t);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++){
	scanf("%lld%lld%lld",&x,&y,&z);
	add(x,y,z);
//	add(y,x,z);
    }
    memset(f,0x3f,sizeof(f));
    f[s]=0;b[s]=1;
    q.push(s);
    while(!q.empty()){
	x=q.front();q.pop();b[x]=0;
if(++cnt[x]>n) return printf("You show me the wrong map!"),0;
	for(int i=first[x];i;i=nxt[i])
	    if(f[go[i]]>f[x]+val[i]){
		f[go[i]]=f[x]+val[i];//cnt[go[i]]++;
		fa[go[i]]=x;//cnt[go[i]]=max(cnt[x]+1,cnt[go[i]]);
		if(!b[go[i]]) b[go[i]]=1,q.push(go[i]);
	    }
	    else
	    if(f[go[i]]==f[x]+val[i])
		fa[go[i]]=min(fa[go[i]],x);
	
    }
    printf("%lld\n",f[t]);
    print(t);
}
