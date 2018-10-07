#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,p,q,x,y;
long long ans;
int predfs(int x,int father){
        fa[x][0]=father;
        deep[x]=deep[father]+1;
        for(int i=1;i<=20;i++)
                fa[x][i]=fa[fa[x][i-1]][i-1];
        for(int i=first[x];i;i=nxt[i])
                if(go[i]!=father)
                        predfs(go[i],x);
}
int lca(int x,int y){
        if(deep[x]<deep[y]) swap(x,y);
        for(int i=20;i>=1;i--)
                if(deep[fa[x][i]]>=deep[y])
                        x=fa[x][i];
        for(int i=20;i>=1;i--)
                if(fa[x][i]!=fa[y][i])
                        x=fa[x][i],y=fa[y][i];
        return fa[x][0];
}
                
int dfss(int x,int father,int y,int flp,int step){
        if(step==0) return f[lca(x,y)][flp]++,0;
        for(int i=first[x];i;i=nxt[i])
                if(go[i]!=father)
                        dfss(go[i],x,y,flp,step);
}
int ansdfss(int x,int father,int y,int flp,int step){
        if(step==0) return ans+=f[1][flp^1]-f[lca(x,y)][flp^1]+ff[x][flp^1]+ff[y][flp^1],0;
        for(int i=first[x];i;i=nxt[i])
                if(go[i]!=father)
                        dfss(go[i],x,y,flp,step);
}

        
int dfs(int x,int father){
        dfss(x,x,x,1,q);
        dfss(x,x,x,0,p);
        for(int i=first[x];i;i=nxt[i])
                if(go[i]!=father){
                        dfs(go[i],x);
                        f[i][1]+=f[go[i]][1];
                        f[i][0]+=f[go[i]][0];
                        ff[i][1]+=f[go[i]][1];
                        ff[i][0]+=f[go[i]][0];
                }
}

int ansdfs(int x,int father){
        ansdfss(x,x,x,q,q);
        ansdfss(x,x,x,p,p);
        for(int i=first[x];i;i=nxt[i])
                if(go[i]!=father){
                        dfs(go[i],x);
                }
}


int main(){
        scanf("%d%d%d",&n,&p,&q);
        for(int i=1;i<n;i++){
                scanf("%d%d",&x,&y);
                add(x,y);
                add(y,x);
            }
        predfs(1,0);
        dfs(1,0);
        ansdfs(1,0);
        printf("%lld",ans/2ll);
}
