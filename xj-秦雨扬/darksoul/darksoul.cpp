#include<cstdio>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
const int MAXA=1e6;
int n,flag=0;
map<pair<int,int>,int> ma;
pair<long long,int> st[MAXA];
int nxt[MAXA<<1],first[MAXA<<1],go[MAXA<<1],val[MAXA<<1],b[MAXA<<1],s[MAXA],top,tot,bo[MAXA],x,y,z,now,l,r;
long long ans,ff[MAXA],f[MAXA],ss[MAXA],sum[MAXA],summ;
int add(int x,int y,int z){
    nxt[++tot]=first[x]; first[x]=tot; go[tot]=y; val[tot]=z;
}
 
int predfs(int x,int father){
    b[x]=1;
    for(int i=first[x];i;i=nxt[i]){
    if(go[i]==father||go[i]==x) continue;
    int yy=(b[go[i]])?go[i]:predfs(go[i],x);
    if(!yy) continue;
    s[++top]=x;
    ss[top]=val[i];
    bo[x]=1;
    return (yy==x)?0:yy;
    }
}
 
int dfss(int x,int father,int y){
    if(bo[x]&&(x!=y)) return 0;
    if(ff[x]>ff[now]) now=x;
    for(int i=first[x];i;i=nxt[i]){
    if(go[i]==father) continue;
    ff[go[i]]=ff[x]+val[i];
    dfss(go[i],x,y);
    }
}
 
int work(int x){
    now=x;
    ff[x]=0;
    dfss(x,0,x);
    f[x]=ff[now];
    ff[now]=0;
    dfss(now,0,x);
    ans=max(ans,ff[now]);
}
 
int main(){
  //  freopen("darksoul2.in","r",stdin);
  //  freopen("darksoul.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    scanf("%d%d%d",&x,&y,&z);
    if(x==y) {flag=1;continue;}
    if(ma[make_pair(x,y)]) {
    if(val[ma[make_pair(x,y)]]>z) val[ma[make_pair(x,y)]]=z;
    if(val[ma[make_pair(y,x)]]>z) val[ma[make_pair(y,x)]]=z;
	flag=1;continue;}
    ma[make_pair(x,y)]=tot+1;
    ma[make_pair(y,x)]=tot+2;
    add(x,y,z);
    add(y,x,z);
    }
    if(flag){
    work(1);
    return printf("%lld",ans+1),0;
    }
    predfs(1,0);
    for(int i=1;i<=top;i++) work(s[i]),sum[i]=sum[i-1]+ss[i];
    for(int i=1;i<top;i++) s[top+i]=s[i],sum[top+i]=sum[top+i-1]+ss[i];
    summ=sum[top]/2;top=top*2-1;
    for(int i=1;i<=top;i++){
    while(l<r&&(sum[i]-sum[st[l].second])>summ) l++;
    ans=max(ans,st[l].first+sum[i]+f[s[i]]);
    while(l<r&&(st[r].first<f[s[i]]-sum[i])) r--;
    st[++r]=make_pair(f[s[i]]-sum[i],i);
    }
    printf("%lld",ans+1ll);
}
