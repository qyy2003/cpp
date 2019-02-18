#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000000],an,x,y,fl;
const int MAXA=1e6;
int first[MAXA<<1],nxt[MAXA<<1],go[MAXA<<1],val[MAXA<<1],tot=1;
void add(int x,int y,int z){
    nxt[++tot]=first[x]; first[x]=++tot; go[tot]=y; val[tot]=z;
}
void add(int x,int y){
    nxt[++tot]=first[x]; first[x]=++tot; go[tot]=y;
}
int work(){
    return 0;
}
main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++){
	scanf("%lld%lld",&fl,&x);
	if(fl==1){
	    scanf("%lld",&y);
	    a[x]=y-an;
	}
	if(fl==2) an+=x;
	if(fl==3) printf("%lld\n",a[x]+an);
    }
    return 0;
}
