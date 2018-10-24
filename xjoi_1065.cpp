#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int s,t,n,m,x,y,z,tot;
const int MAXA=1e6+7;
int first[MAXA],nxt[MAXA<<1],go[MAXA<<1],val[MAXA<<1],fa[MAXA],b[MAXA],f[MAXA];
queue<int>q;
int print(int x){
    if(x^s) print(fa[x]);
    printf("%d ",x);
}
int add(int x,int y,int z){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y; val[tot]=z;
}
int main(){
    scanf("%d%d",&s,&t);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
	scanf("%d%d%d",&x,&y,&z);
	add(x,y,z);
    }
    q.push(s);
    while(!q.empty()){
	x=q.front(); q.pop();
	for(int i=first[x];i;i=nxt[i])
	    if(f[go[i]]<f[x]+val[i]){
		f[go[i]]=f[x]+val[i];
		fa[go[i]]=x;
		if(!b[go[i]]) b[go[i]]=1,q.push(go[i]);
	    }
	    else 
		if(f[go[i]]==f[x]+val[i]&&fa[go[i]]>x) fa[go[i]]=x;
	b[x]=0;
    }
    printf("%d\n",f[t]);
    print(t);
}
