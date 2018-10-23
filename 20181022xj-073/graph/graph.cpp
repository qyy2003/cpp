#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,x,y,q,l,r,ans,b[105],falg;
int first[10000],nxt[10000],go[10000],tot;
int add(int x,int y){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y;
}
int dfs(int x,int father){
    if(x<l||x>r) return 1;
    b[x]=1;
    int flag=1;
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father){
	    if(b[go[i]]) return 0;
	    flag&=dfs(go[i],x);
	}
    return flag;
}
int main(){
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
	scanf("%d%d",&x,&y);
	add(x,y);
	add(y,x);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
	scanf("%d%d",&x,&y);
	ans=0;
	for(l=x;l<y;l++)
	    for(int r=l+1;r<=y;r++)
	    {
		memset(b,0,sizeof(b));
		b[0]=0;
		falg=1;
		for(int j=l;j<=r;j++)
		    if(!b[j]&&falg) falg&=dfs(j,0);
		ans+=(falg)?1:0;
	    }
	printf("%d\n",ans);
    }
}
