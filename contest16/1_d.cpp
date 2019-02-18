#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int MAXA=2e6;
const int INF=4e9+7;
const double DIV=2;
int n,x,y,c[MAXA];
int a[MAXA],b[MAXA],mina[MAXA],minb[MAXA],maxa[MAXA],maxb[MAXA];
int mysort(int x,int y){
    return a[x]<a[y];
}
int check(int y){
    int l=1,r=1;
    for(int i=1;i<=n;i++){
    for(;(a[c[r]]-a[c[i]])<=y&&r<=n;r++);
    //printf("%lld %lld\n",c[i],c[r]);
    //printf("$%lld %lld %lld %lld\n",maxb[r],maxa[i-1],minb[r],mina[i-1]);
    if(max(maxb[r],maxa[i-1])-min(minb[r],mina[i-1])<=y) return 1;
    }
    return 0;
}
main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
	scanf("%lld%lld",&x,&y);
	a[i]=x-y;
	b[i]=x+y;
	//printf("$%lld %lld\n",a[i],b[i]);
	c[i]=i;
    }
    sort(c+1,c+n+1,mysort);
    //for(int i=1;i<=n;i++) printf("%lld ",c[i]);
    c[0]=0;c[n+1]=n+1;
    maxa[0]=-INF;
    mina[0]=INF;
    maxb[n+1]=-INF;
    minb[n+1]=INF;
    for(int i=1;i<=n;i++){
	maxa[i]=max(maxa[i-1],b[c[i]]);
	mina[i]=min(mina[i-1],b[c[i]]);
	maxb[n-i+1]=max(maxb[n-i+2],b[c[n-i+1]]);
	minb[n-i+1]=min(minb[n-i+2],b[c[n-i+1]]);
    }
    int l=0,r=a[c[n]]-a[c[1]],mid,ans;
    //return printf("%lld ",check(0));
    while(l<=r){
	mid=(l+r)>>1;
	if(check(mid)) r=mid-1,ans=mid;
	else l=mid+1;
    }
    printf("%lf",(double)ans/DIV);
}
