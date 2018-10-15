#include<cstdio>
#include<algorithm>
using namespace std;
long long n,l,r,k,ans;
int work(long long x){
	if(n*x*2+sum*2<k) return 0;
	if(n*x+sum>k) return -1;
	return 1;
}
int main(){
	scanf("%lld%lld%lld%lld",&n,&l,&r,&k);
	sum=(l<=r)?r-l+1:r-l+1+n;
	long long ll=0,rr=k/n,mid,now;
	ans=-1;
	while(ll<=rr){
		mid=(ll+rr)>>1;
		now=work(mid);
		printf("!%lld %lld!",now,mid);
		if(now>=0){
			if(now==1)ans=mid; rr=mid-1;
		}
		else ll=mid+1;
	}
	if(ans==-1) return printf("-1"),0;
	
}
