#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXA=200000;
int n,m,x,y,tot,top;
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
	    ans[++top]=dfs2(go[i],x);
	    f[x]^=ans[top];
	    if(ans[top]==0ll) mm++,top--;
	}
    return f[x];
}

int dfs(int x,int father){
    deep[x]=deep[father]+1;
    b[x]=1;
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father){
	    if(b[go[i]]){
		xx=rand();
		f[go[i]]^=xx;
		f[x]^=xx;
	    }
	   else dfs(go[i],x);
	}
    return f[x];
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
	scanf("%d%d",&x,&y);
	add(x,y);
	add(y,x);
    }
    dfs(1,0);
    memset(b,0,sizeof(b));
    dfs2(1,0);
   // for(int i=1;i<=top;i++) printf("%lld ",ans[i]);
   an=1ll*mm*(m-1)-1ll*(mm-1)*mm/2ll;
    sort(ans+1,ans+top+1);
    long long last=1;
    for(long long i=2;i<=top;i++)
	if(ans[i]!=ans[i-1]){
	    an+=1ll*(i-last+1)*(i-last)/2ll;
	    last=i;
	}
    an+=1ll*(top+2-last)*(top+1-last)/2ll;
    printf("%lld",an);
}

