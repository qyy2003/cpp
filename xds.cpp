#include<queue>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e5+100;
int a[MAXN],sw[MAXN],size[MAXN],lli[MAXN],llr[MAXN],tr[MAXN*350],son[MAXN*350][2],fa[MAXN];
int nc,n,m,l,x,y,z,tmp,tot;
long long ans;
vector<pair<int,pair<int,int> > >qq;
queue<int>q;
int find(int x){ return fa[x]=fa[x]==x?x:find(fa[x]);}
int New(){
    if(q.empty()) tmp=++tot;
    else tmp=q.front,q.pop();
    tr[tmp]=son[tmp][1]=son[tmp][2]=0;
    return tmp;
}
int query(int x,int l,int r,int ql,int qr){
    if(l>qr||r<ql) return 0;
    if(l<=ql&&r>=qr) return tr[x];
    return dfs(son[x][0],l,(l+r)>>1,ql,qr)+dfs(son[x][1],((l+r)>>1)+1,r,ql,qr);
}
int update(int &x,int l,int r,int ql){
    if(l>ql||r<ql) return 0;
    if(!x) x=New();
    if(l==r) return tr[x]++;
    tr[x]=update(son[x][0],1,(l+r)>>1,ql)+update(son[x][1],((l+r)>>1)+1,r,ql);
}
int dfs(int x,int l,int r,int y,int ww){
    if(!x) return 0;
    if(l==r) return ans+=1ll*tr[x]*ww*(size[y]-query(root[y],1,nc,lli[l],llr[l])),0;
    return dfs(son[x][0],l,(l+r)>>1,y,ww)+dfs(son[x][1],((l+r)>>1)+1,r,y,ww);
}
int merge(int &x,int y,int l,int r){
    if(!y) return 0;
    if(!x) x=New();
    tr[x]+=tr[y];
    if(l==r) return 0;
    return merge(son[x][0],son[y][0],l,(l+r)>>1)+merge(son[x][1],son[y][1],((l+r)>>1)+1,r);
}
int free(int x){
    if(!x) return 0;
    q.push(x);
    return free(son[x][0])+free(son[x][1]);
}
int main(){
    scanf("%d%d%d",&n,&m,&L);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sw[++nc]=a[i];
    sort(sw+1,sw+nc+1);
    nc=unique(sw+1,sw+cn+1)-sw-1;
    for(int i=1;i<=cn;i++)
	for(int &j=lli[i]+1;sw[j]-sw[i]>=L;j++);
    for(int i=1;i<=cn;i++)
	for(int &j=llr[i]+cn;sw[j]-sw[i]>=L;j--);
    for(int i=1;i<=cn;i++) c[i]=lowbound(sw+1,sw+nc+1,c[i])-num;
    for(int i=1;i<=m;i++){
	scanf("%d%d%d",&x,&y,&z);
	qq.push_back(make_pair(z,make_pair(x,y)));
    }
    sort(qq.begin(),qq.end());
    for(int i=1;i<=n;i++) update(root[i],1,nc,c[i]),size[i]=1;
    for(int i=1;i<=m;i++){
	x=find(qq[i].second.first);
	y=find(qq[i].second.second);
	if(x==y) continue;
	if(size[x]>size[y]) swap(x,y);
	fa[x]=y; 
	if(l==0) ans+=1ll*size[x]*size[y]*qq[i].first;
	size[y]+=size[x];
	if(l==0) continue;
	dfs(root[x],1,nc,y,qq[i].first);
	merge(root[y],root[x],1,nc);
	free(root[x]);
    }
    printf("%d",ans);
}