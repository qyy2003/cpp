#include<bits/stdc++.h>
using namespace std;
int n;
const int MAXA=2e6;
int nxt[MAXA<<1],go[MAXA<<1],first[MAXA<<1],tot,m,x,y,b[MAXA<<1];
long long ff[MAXA],f[MAXA],ans=0,suma;
int add(int x,int y){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y; return 0;
}
int dfs(int x,int father){
    b[x]=1;
    int siz=f[x]+ff[x];
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father&&!b[go[i]])
	    siz+=dfs(go[i],x);
    return siz;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
	scanf("%d%d",&x,&y);
	if(x==y) {ff[x]++;ff[y]++;suma++;continue;}
	else f[x]++,f[y]++;
	add(x,y);
	add(y,x);
    }
    if(dfs(x,0)/2!=m) return printf("0\n"),0;
    for(int i=1;i<=n;i++){
	ans+=1ll*f[i]*(f[i]-1)/2ll;
	//ans+=1ll*ff[i]*f[i];
    }
    printf("%lld",ans+suma*(m-1)-(suma)*(suma-1)/2ll);
    return 0;
}
