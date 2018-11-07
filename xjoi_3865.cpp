#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
long long a,b,c,d,ans,MAXA=5e6,last,x,y;
vector<pair<long long,long long> > v;
int bruteforce(){
    ans=d-c+b-a+2ll;
    for(long long i=a;i<=b;i++)
	for(long long j=c;j<=d;j++)
	    if(j%i==0){
		ans--;
		break;
	    }
    printf("%lld",ans);
}
int solve(){
    last=a-1;
    for(long long i=MAXA;i>=1;i--){
	if(d/i<a||c/i>b) continue;
	//printf("%lld %lld %lld\n",i,d/i,c/i);
	x=max(((c%i)?c/i+1ll:c/i),a);y=min(d/i,b);
	if(x>y) continue;
	if(x>last+1ll) ans+=x-last-1ll;
	last=max(last,y);
    }
    printf("%lld",ans+d-c+b-last+1ll);
}
int main(){
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    a=max(a,b/2ll+1ll);
    c=max(c,d/2ll+1ll);
    if(d/a>=MAXA) bruteforce();
    else solve();
}

