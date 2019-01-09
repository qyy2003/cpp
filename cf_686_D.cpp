#include<cstdio>
#include<iostream>
using namespace std;
const int MAXA=1e6;
int n,m,x,tot,l,r,now;
int first[MAXA],nxt[MAXA],go[MAXA],que[MAXA],b[MAXA],fa[MAXA],zx[MAXA],siz[MAXA];
void add(int x,int y){
    nxt[++tot]=first[x];first[x]=tot;go[tot]=y;
}
int bfs(int x){
    que[++r]=x;
    b[x]=1;
    while(l<r){
	now=que[++l];;
	for(int i=first[now];i;i=nxt[i]){
	    if(!b[go[i]]){
		b[go[i]]=1;
		que[++r]=go[i];
		fa[go[i]]=now;
	    }
	}
    }
    for(int i=l;i>=1;i--){
	siz[que[i]]++;
	siz[fa[que[i]]]+=siz[que[i]];
	zx[que[i]]=que[i];
    }
    for(int i=l;i>=1;i--)
	if(siz[que[i]]*2>siz[fa[que[i]]]){
	    for(zx[fa[que[i]]]=zx[que[i]];siz[zx[fa[que[i]]]]*2<siz[fa[que[i]]];zx[fa[que[i]]]=fa[zx[fa[que[i]]]]);
	}
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++){
	scanf("%d",&x);
	add(x,i);
	add(i,x);
    }
    bfs(1);
    for(int i=1;i<=m;i++){
	scanf("%d",&x);
	printf("%d\n",zx[x]);
    }
    return 0;
}

