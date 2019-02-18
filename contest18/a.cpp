#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,suma,sumb,x,maxa,a[1000000],mina,minb;
main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=2;i<n;i++){
	x=abs(a[i]-a[i+1]);
	if(i&1) suma-=x;
	else suma+=x;
	if(suma<=0) suma=0;
	ans=max(ans,suma);
    }
    suma=0;
    for(int i=1;i<n;i++){
	x=abs(a[i]-a[i+1]);
	if(i&1) suma+=x;
	else suma-=x;
	if(suma<=0) suma=0;
	ans=max(ans,suma);
    }
    printf("%lld",ans);
    return 0;
}
