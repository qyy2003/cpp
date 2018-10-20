#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXA=1e6+7;
vector<int> q;
int first[MAXA],nxt[MAXA],go[MAXA],fa[MAXA],deep[MAXA],maxa,x,y,n,m,ans,tot;
int add(int x,int y){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y;
}
int dfs(int x,int father){
    fa[x]=father;
    deep[x]=deep[father]+1;
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father)
	    dfs(go[i],x);
}
int redfs(int x){
    if(deep[x]==0) return 0;
    if(deep[x]==(ans+1)/2||deep[x]==(ans+2)/2) q.push_back(x);
    return redfs(fa[x]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
	scanf("%d%d",&x,&y);
	add(x,y);
	add(y,x);
    }
    dfs(1,0);
    maxa=1;
    for(int i=1;i<=n;i++){
	if(deep[i]>deep[maxa])
	    maxa=i;
    }
    dfs(maxa,0);
    maxa=1;
    for(int i=1;i<=n;i++){
	if(deep[i]>deep[maxa])
	    maxa=i;
    }
    ans=deep[maxa];
    //for(int i=1;i<=n;i++) printf("%d ",deep[i]);
    redfs(maxa);
    sort(q.begin(),q.end());
    for(int i=0;i<q.size();i++) printf("%d ",q[i]);
}
