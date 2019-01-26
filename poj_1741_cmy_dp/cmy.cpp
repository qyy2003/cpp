#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
template<class T1>
T1 read(){
    T1 ans=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){ans=ans*10+ch-'0';ch=getchar();}
    return ans;
}
const int MaxS=21000;
class Tree{
public:
    void init(){
        getN(read<int>());
        getD(read<int>());
        if(n==d&&d==0)exit(0);
        memset(vis,0,sizeof vis);
        memset(vis1,0,sizeof vis1);
        memset(fir,0,sizeof fir);
        memset(node,0,sizeof node);
        tot=0;
        for(int i=1;i<n;i++)addEdge(read<int>(),read<int>(),read<int>());
    }
protected:
    int n,d;
    int tot,fir[MaxS],nex[MaxS<<1],to[MaxS<<1],va[MaxS<<1];
    bool vis[MaxS];
    int Q[MaxS],h,t;
    bool vis1[MaxS];
    struct Node{
        int size,f,maxson;
    }node[MaxS];
    int core(int x){
        h=t=0;
        Q[++t]=x;
        vis1[x]=1;
        do{
            int u=Q[++h];
            node[u].size=1;
            for(int i=fir[u];i;i=nex[i]){
                int v=to[i];
                if(vis[v]||vis1[v])continue;
                vis1[v]=1;
                Q[++t]=v;
                node[v].f=u;
            }
        }while(h<=t);
        int MS=x;
        for(int i=t;i>=1;i--){
            if(node[Q[i]].maxson*2<t&&node[Q[i]].size*2>=t)MS=Q[i];
            node[node[Q[i]].f].maxson=max(node[node[Q[i]].f].maxson,node[Q[i]].size);
            node[node[Q[i]].f].size+=node[Q[i]].size;
        }
        return MS;
    }
private:
    void getN(int _n){n=_n;}
    void getD(int _d){d=_d;}
    void addEdge(int v,int y,int x){
        nex[++tot]=fir[x];fir[x]=tot;to[tot]=y;va[tot]=v;
        nex[++tot]=fir[y];fir[y]=tot;to[tot]=x;va[tot]=v;
    }
};
int sum[MaxS],temp[MaxS],stop,ttop;
class Divi:public Tree{
public:
    int main(){
        ans=0;
        dv(core(1));
        return ans;
    }
protected:
    int ans;
    void dfs(int x,int f,int dis){
        temp[++ttop]=dis;
        vis1[x]=0;
        node[x].f=node[x].maxson=node[x].size=0;
        for(int i=fir[x];i;i=nex[i]){
            int v=to[i];
            if(v==f||vis[v])continue;
            dfs(v,x,dis+va[i]);
        }
    }
    void upd(){
        sort(temp+1,temp+1+ttop);
        for(int j=1,k=ttop;j<=ttop;j++){
            while(temp[k]+temp[j]>d&&k>0)k--;
            if(k<=j)break;
            ans-=k-j;
        }
        for(int i=1;i<=ttop;i++){
            if(temp[i]>d)break;
            sum[++stop]=temp[i];
        }
        ttop=0;
    }
    void dv(int x){
        vis[x]=1;
        for(int i=fir[x];i;i=nex[i]){
            int v=to[i];
            if(vis[v])continue;
            dfs(v,x,va[i]);
            upd();
        }
        sort(sum+1,sum+1+stop);
        int j,k=stop;
        ans+=k;
        for(j=1;j<=stop;j++){
            while(sum[j]+sum[k]>d&&k>0)k--;
            if(k<=j)break;
            ans+=k-j;
        }
        stop=ttop=0;
        for(int i=fir[x];i;i=nex[i]){
            int v=to[i];
            if(vis[v])continue;
            dv(core(v));
        }
    }
}T;
int main(){
    while(1){
        T.init();
        printf("%d\n",T.main());
    }
}