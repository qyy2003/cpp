#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
long long mina,n,sum,a[10000],ans,m;
int main(){
    scanf("%lld%lld",&n,&m);
    mina=1e9+7;
    for(int i=1;i<=n;i++){
	scanf("%lld",&a[i]);
	mina=min(mina,a[i]);
	sum+=a[i];
    }
    m-=sum-mina*n;
    if(m>0) mina-=(m%n)?(m/n+1ll):m/n;
    if(mina<0) return printf("-1"),0;
    printf("%lld",mina);
    return 0;
}
