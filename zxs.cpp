#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXA=2e5+100;
int n,m,a[MAXA<<1],sw[MAXA<<1],opt1[MAXA],opt2[MAXA],opt3[MAXA],opt4[MAXA];
int root[MAXA<<1],tr[MAXA*100],son[MAXA*100][2],cnt,tmp,tot,xx;
queue<int>q;

int free(int x,int l,int r,int del){
    if(!x) return 0;
    if(del<l||del>r) return 0;
    q.push(x);
    if(l==r) return 0;
    return free(son[x][0],l,(l+r)>>1,del)+free(son[x][1],((l+r)>>1)+1,r,del);
}

int New(){
    if(q.empty()) tmp=++tot;
    else tmp=q.front(),q.pop();
    tr[tmp]=son[tmp][0]=son[tmp][1]=0;
    return tmp;
}
int newmerge(int &x,int y,int l,int r,int ad){
    if(ad<l||ad>r) return x=y,0;
    x=New();
    tr[x]=tr[y]+1;
    if(l==r) return 1;
    return newmerge(son[x][0],son[y][0],l,(l+r)>>1,ad)+newmerge(son[x][1],son[y][1],((l+r)>>1)+1,r,ad);
}

int find(int x,int y,int l,int r,int &ad){
    if(tr[y]-tr[x]<ad) return ad-=tr[y]-tr[x],-1;
    if(l==r) return l;
    int ans=find(son[x][0],son[y][0],l,(l+r)>>1,ad);
    if(~ans) return ans;
    return find(son[x][1],son[y][1],((l+r)>>1)+1,r,ad);
}

int main(){
    freopen("pigeon2.in","r",stdin);
    freopen("pigeon.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sw[++cnt]=a[i];
    for(int i=1;i<=m;i++){
	scanf("%d",&opt1[i]);
	if(opt1[i]==2){
	    scanf("%d",&opt2[i]);
	    sw[++cnt]=opt2[i];
	}
	if(opt1[i]==3) scanf("%d%d%d",&opt2[i],&opt3[i],&opt4[i]);
    }
    sort(sw+1,sw+cnt+1);
    cnt=unique(sw+1,sw+cnt+1)-sw-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(sw+1,sw+cnt+1,a[i])-sw;
    for(int i=1;i<=n/2;i++) swap(a[i],a[n-i+1]);
    for(int i=1;i<=n;i++) newmerge(root[i],root[i-1],1,cnt,a[i]);
    for(int i=1;i<=m;i++){
	if(opt1[i]==1) free(root[n],1,cnt,a[n]),root[n]=0,n--;
	if(opt1[i]==2) xx=lower_bound(sw+1,sw+cnt+1,opt2[i])-sw,newmerge(root[n+1],root[n],1,cnt,xx),a[n+1]=xx,n++;
	if(opt1[i]==3) printf("%d\n",sw[find(root[n-opt3[i]],root[n-opt2[i]+1],1,cnt,opt4[i])]);
    }
}
