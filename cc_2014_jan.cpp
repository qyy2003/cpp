#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXA=400000;
int n,m,x,y,tot,top,cnt;
long long xx,b[MAXA],f[MAXA<<1],ans[MAXA<<3],mm=0;
int first[MAXA],nxt[MAXA<<1],go[MAXA<<1],val[MAXA],deep[MAXA];
long long an;
void add(int x,int y){
    nxt[++tot]=first[x];first[x]=tot; go[tot]=y;
}
int dfs2(int x,int father){
    deep[x]=deep[father]+1;
    b[x]=1;
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father&&b[go[i]]==0){
	    f[x]^=dfs2(go[i],x);
	}
    ans[++top]=f[x];
    if(ans[top]==0ll) mm++,top--;
  //  printf("%d %lld\n",x,f[x]);
    return f[x];
}

int dfs(int x,int father){
    deep[x]=++cnt;b[x]=1;
   // printf("%d ",x);
    fflush(stdout);
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father){
	    if(b[go[i]]){
		if(deep[x]<deep[go[i]]) continue;
		xx=rand();
		f[go[i]]^=xx;
		f[x]^=xx;
		ans[++top]=xx;
	    }
	   else dfs(go[i],x);
	}
    return f[x];
}

int main(){
    srand(time(NULL));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
	scanf("%d%d",&x,&y);
	add(x,y);
	add(y,x);
    }
    dfs(1,0);
    memset(b,0,sizeof(b));
    //for(int i=1;i<=n;i++) ans[++top]=f[i];
    //for(int i=1;i<=n;i++) printf("!%lld ",f[i]);
    //printf("\n");
    //unique(f+1,f+top+1);
    //for(int i=1;i<=top;i++) printf("%lld ",ans[i]);
    //printf("\n");
    dfs2(1,0);
    mm--;
   an=1ll*mm*(m-1)-1ll*(mm-1)*mm/2ll;
    sort(ans+1,ans+top+1);
    //for(int i=1;i<=top;i++) printf("%lld ",ans[i]);
    long long last=1;
    for(long long i=2;i<=top;i++)
	if(ans[i]!=ans[i-1]){
	    an+=1ll*(i-last)*(i-last-1)/2ll;
	    last=i;
	}
    an+=1ll*(top+1-last)*(top-last)/2ll;
    printf("%lld",an);
}


