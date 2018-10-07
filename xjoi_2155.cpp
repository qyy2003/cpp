#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
#define int long long
using namespace std;
const int MAXE=1*1e7;
const int MAXN=5000;
int n,m,kk,x,y,z,tot,first[MAXN],nxt[MAXE],b[MAXN],g[MAXE],go[MAXE],cur[MAXN];
queue<int> q;
long long val[MAXE],f[MAXN];
void add(int x,int y,int z,int zz){
    nxt[++tot]=first[x]; first[x]=tot; g[tot]=z; go[tot]=y; val[tot]=zz;
}
int dij(){
//  cout << "dij begin" << endl;
    int x;
    memset(f,-1,sizeof(f));
    f[0]=0;
    q.push(0);
//  cout<<"he"<<endl;
    while(!q.empty()){
//      cout << "Hx CAI" << endl;
        int x=q.front(); q.pop();
//      printf("%d ",x);
        for(int i=first[x];i;/*printf("&%d %d ",go[i],val[i]),*/i=nxt[i])
            if(g[i]>0&&f[go[i]]<f[x]+val[i]){
                f[go[i]]=f[x]+val[i];
                if(!b[go[i]])
                q.push(go[i]);
                b[go[i]]=1;
            }b[x]=0;
    //  return 0;
    }
    if(f[n+m+1]==-1) return 0;
    return 1;
}
int dfs(int x,int y){
    if(x==0) return y;
    int ans=0;
    //printf("%lld %lld\n",x,y);
    for(int &i=cur[x];i;i=nxt[i])
        if((f[go[i]]==f[x]+val[i])&&g[i]==0)
            if((ans=dfs(go[i],min(y,g[i^1])))>0){
                g[i^1]-=ans;
                g[i]+=ans;
                return ans;
            }
    return 0;
}
main()
{
    long long ans=0;
    scanf("%lld%lld%lld",&n,&m,&kk);tot=1;
    for(int i=1;i<=n;i++){
        add(0,i,1,0);
        add(i,0,0,0);
    }
    for(int i=1;i<=m;i++){
        add(n+i,n+m+1,1,0);
        add(n+m+1,n+i,0,0);
    }
    for(int i=1;i<=kk;i++){
        scanf("%lld%lld%lld",&x,&y,&z);
        add(x,n+y,1,z);
        add(n+y,x,0,-z);
    }
//  int t = 0;
    while(dij()){
        //cout << "t = " << ++ t << endl;
        //printf("#");
        for(int i=0;i<=n+m+1;i++) cur[i]=first[i];
        for(int x=dfs(n+m+1,2);x;ans+=f[n+m+1],x=dfs(n+m+1,2));
    }
    printf("%lld",ans);
}
