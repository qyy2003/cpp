#pragma GCC optimize("2,Ofast,inline")
#include<queue>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=4e5+100;
int c[MAXN],sw[MAXN],size[MAXN],lli[MAXN],llr[MAXN],tr[MAXN*40],son[MAXN*40][2],fa[MAXN],root[MAXN];
int nc,n,m,l,x,y,z,tmp,tot,jj;
long long ans;
vector<pair<int,pair<int,int> > >qq;
queue<int>q;
int find(int x){ return fa[x]=(fa[x]==x)?x:find(fa[x]);}
int New(){
    if(q.empty()) tmp=++tot;
    else tmp=q.front(),q.pop();
    tr[tmp]=son[tmp][0]=son[tmp][1]=0;
    return tmp;
}
int query(int x,int l,int r,int ql,int qr){
    if(l>qr||r<ql) return 0;
    if(!x) return 0;
    if(l>=ql&&r<=qr) return tr[x];
    return query(son[x][0],l,(l+r)>>1,ql,qr)+query(son[x][1],((l+r)>>1)+1,r,ql,qr);
}
int dfs(int x,int l,int r,int y,int ww){
    if(!x) return 0;
    if(l==r) return ans+=1ll*tr[x]*ww*(size[y]-query(root[y],1,nc,lli[l],llr[l])),0;
    return dfs(son[x][0],l,(l+r)>>1,y,ww)+dfs(son[x][1],((l+r)>>1)+1,r,y,ww);
}
int update(int &x,int l,int r,int ql){
    if(l>ql||r<ql) return 0;
    if(!x) x=New();
    if(l==r) return ++tr[x];
    return tr[x]=update(son[x][0],l,(l+r)>>1,ql)+update(son[x][1],((l+r)>>1)+1,r,ql);
}
int merge(int &x,int y,int l,int r){
    if(!y) return 0;
    if(!x) x=New();
    tr[x]+=tr[y];
    if(l==r) return tr[y];
    return merge(son[x][0],son[y][0],l,(l+r)>>1)+merge(son[x][1],son[y][1],((l+r)>>1)+1,r);
}
int free(int x){
    if(!x) return 0;
    q.push(x);
    return free(son[x][0])+free(son[x][1]);
}

void read(int &x) {
    x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9')
	x = (x << 3) + (x << 1) + c - '0', c = getchar();
}

int main(){
    freopen("graph1.in","r",stdin);
    freopen("graph.out","w",stdout);
    read(n); read(m); read(l);
    for(int i=1;i<=n;i++) read(c[i]),sw[++nc]=c[i];
    sort(sw+1,sw+n+1);
    nc=unique(sw+1,sw+n+1)-sw-1;
    for(int i=1;i<=nc;i++){lli[i]=1;
	for(int &j=lli[i];sw[i]-sw[j]>=l;j++);}
    for(int i=1;i<=nc;i++){llr[i]=nc;
	for(int &j=llr[i];sw[j]-sw[i]>=l;j--);}
    for(int i=1;i<=n;i++) c[i]=lower_bound(sw+1,sw+nc+1,c[i])-sw;
    //for(int i=1;i<=n;i++) printf("%d %d %d\n",c[i],lli[c[i]],llr[c[i]]);
    for(int i=1;i<=m;i++){
	read(x); read(y); read(z);
	qq.push_back(make_pair(z,make_pair(x,y)));
    }
    sort(qq.begin(),qq.end());
    for(int i=1;i<=n;i++) update(root[i],1,nc,c[i]),size[i]=1;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=0;i<m;i++){
	x=find(qq[i].second.first);
	y=find(qq[i].second.second);
	if(x==y) continue;
	if(size[x]>size[y]) swap(x,y);
	fa[x]=y; 
	if(l==0){
	    ans+=1ll*size[x]*size[y]*qq[i].first;
	    size[y]+=size[x];
	    continue;
	}
	dfs(root[x],1,nc,y,qq[i].first);
	//printf(" %d %d\n",size[y],c[x]);
	merge(root[y],root[x],1,nc);
	free(root[x]);
	size[y]+=size[x];
    }
    printf("%lld",ans);
}
