#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXA=2000000;
int n,m,x,f[MAXA],fa[5000],q[MAXA],l,r,ru[MAXA];
char map[2000][2000];
int first[MAXA],go[MAXA],nxt[MAXA],tot;
int faa(int x){
    return fa[x]=(fa[x]==x)?x:faa(fa[x]);
}
int add(int x,int y){
    ru[y]++;nxt[++tot]=first[x];first[x]=tot; go[tot]=y; return 0;
}
int bfs(){
    while(l<r){
	x=q[++l];
	for(int i=first[x];i;i=nxt[i]){
	    ru[go[i]]--;
	    if(ru[go[i]]==0){
		f[go[i]]=f[x]+1;
		q[++r]=go[i];
	    }
	}
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",map[i]+1);
    for(int i=1;i<=n+m;i++) fa[i]=i;
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	    if(map[i][j]=='=')
		fa[faa(i)]=fa[faa(n+j)];
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	    if(map[i][j]=='<')
		add(faa(i),faa(n+j));
	    else if(map[i][j]=='>')
		add(faa(n+j),faa(i));
    for(int i=1;i<=n+m;i++)
	if(ru[faa(i)]==0&&faa(i)==i)
	    f[faa(i)]=1,q[++r]=faa(i);
    bfs();
    for(int i=1;i<=n+m;i++)
	if(f[faa(i)]==0)
	    return printf("No\n"),0;
    printf("Yes\n");
    for(int i=1;i<=n;i++) printf("%d ",f[faa(i)]);
    printf("\n");
    for(int i=n+1;i<=n+m;i++) printf("%d ",f[faa(i)]);
}
