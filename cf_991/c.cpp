#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,suma,sumb,x;
int check(long long k){
    suma=0; sumb=0;x=n;
    while(x>0){
	suma+=min(k,x);
	x-=min(x,k);
	if(x==0) break;
	sumb+=x/10ll;
	x-=x/10ll;
    }
    return suma>=sumb;
}

int main(){
    scanf("%lld",&n);
   long long l=1ll,r=n/10ll+1,mid,ans;
   while(l<=r){
       mid=(l+r)>>1;
       if(check(mid)) ans=mid,r=mid-1;
       else l=mid+1;
   }
   printf("%lld",ans);
}
