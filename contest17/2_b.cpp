#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int MAXA=2e6;
int n,x1,x2,k[MAXA],b[MAXA],bb[MAXA],c[MAXA],d[MAXA],a[MAXA],e[MAXA];
int mysort1(int x,int y){
    return a[x]<a[y]||(a[x]==a[y]&&k[x]<k[y]);
}
int mysort2(int x ,int y){
    return b[x]<b[y]||(b[x]==b[y]&&k[x]>k[y]);
}
main(){
    scanf("%lld",&n);
    scanf("%lld%lld",&x1,&x2);
    for(int i=1;i<=n;i++){
	scanf("%lld%lld",&k[i],&bb[i]);
	a[i]=k[i]*x1+bb[i];
	b[i]=k[i]*x2+bb[i];
	c[i]=i;
	d[i]=i;
    }
    sort(c+1,c+n+1,mysort1);
    for(int i=1;i<=n;i++) e[c[i]]=i;
    sort(d+1,d+n+1,mysort2);
    //for(int i=1;i<=n;i++) printf("%lld %lld %lld\n",e[i],c[i],d[i]);
    for(int i=1;i<=n;i++){
	if(c[i]!=d[i]) return printf("YES\n"),0;
    }
    printf("NO");
}
