#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,t,x,y,z,tot;
const int MAXA=1e5;
int first[MAXA],b[MAXA],cnt[MAXA],nxt[MAXA],go[MAXA],val[MAXA],f[MAXA];
queue<int> q;
int add(int x,int y,int z){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y; val[tot]=z;
}

int spfa(){
    f[1]=0;cnt[1]=0;
    q.push(1);
    while(!q.empty()){
	x=q.front(); q.pop();
	for(int i=first[x];i;i=nxt[i])
	    if(f[go[i]]>f[x]+val[i]){
		f[go[i]]=f[x]+val[i];
		cnt[go[i]]=cnt[x]+1;
		if(cnt[go[i]]>=n) return printf("YE5\n"),0;
		if(!b[go[i]]) q.push(go[i]),b[go[i]]=1;
	    }
	b[x]=0;
    }
    return 1;
}

int main(){
    scanf("%d",&t);
    while(t--){
	scanf("%d%d",&n,&m);
	memset(first,0,sizeof(first)); tot=0;
	memset(cnt,0,sizeof(cnt));
	memset(b,0,sizeof(b));
	memset(f,0x3f,sizeof(f)); while(!q.empty()) q.pop();
	for(int i=1;i<=m;i++){
	    scanf("%d%d%d",&x,&y,&z);
	    add(x,y,z);
	    if(z>=0) add(y,x,z);
	}
	if(spfa()) printf("N0\n");
    }
}
