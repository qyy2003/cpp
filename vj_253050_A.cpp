#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXA=1e5+100;
const int P=1e9+7;
int n,x,y,z;
long long ans;
int first[MAXA],go[MAXA<<1],nxt[MAXA<<1],tot,val[MAXA<<1];
void add(int x,int y,int z){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y; val[tot]=z;
}
int dfs(int x,int father){
    int size=1;int si;
    for(int i=first[x];~i;i=nxt[i])
        if(go[i]!=father)
        {
            si=dfs(go[i],x);
            ans+=1ll*si*(n-si)%P*val[i]%P*(n-1)%P;
            ans%=P;
            size+=si;
            //printf("%d %d %d %lld\n",go[i],x,val[i],ans);
        }
    return size ;
}
int main()
{
    while(scanf("%d",&n)==1){
    ans=0;
    memset(first,-1,sizeof(first));
    tot=0;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0);
    for(int i=2;i<=n-2;i++){
        ans=ans*i%P;
    }
    printf("%lld\n",ans*2%P);
    }
}
