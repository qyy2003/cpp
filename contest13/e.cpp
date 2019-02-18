#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,x,y,a[10000],b[10000],c[10000],siz[10000],ans[10000];
int first[10000],nxt[10000],go[10000],tot,top;
int add(int x,int y){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y;
}
int pre_dfs(int x,int father){
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father)
	    siz[x]+=pre_dfs(go[i],x);
    return ++siz[x];
}

int askx(int x){
    return a[x]-a[c[top]];
}

int asky(int x){
    return b[x]-b[c[top]];
}

int mysort(int x,int y){
    return 1ll*askx(x)*asky(y)<1ll*askx(y)*asky(x);
}

int dfs(int x,int father){
    top++;
    for(int i=1;i<siz[x];i++)
	if(a[c[top]]>a[c[top+i]])
	    swap(c[top],c[top+i]);
    ans[c[top]]=x;
    if(siz[x]==1) return 0;;
    //for(int i=1;i<=n;i++) printf("%d ",c[i]);
    sort(c+top+1,c+top+siz[x],mysort);
    //for(int i=1;i<=n;i++) printf("%d ",c[i]);
    //printf("| %d %d %d\n",x,top,siz[x]);
    for(int i=first[x];i;i=nxt[i])
	if(go[i]!=father){
	    dfs(go[i],x);
	}
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
	scanf("%d%d",&x,&y);
	add(x,y);
	add(y,x);
    }
    for(int i=1;i<=n;i++){
	scanf("%d%d",&a[i],&b[i]);
	c[i]=i;
//	if(a[i]<a[c[1]]) swap(c[i],c[1]);
    }
    //return 0;
    pre_dfs(1,0);
    dfs(1,0);
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}
