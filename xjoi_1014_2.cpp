#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const long long MAXA=1e18;
long long s,t,a,b,ans,sum=MAXA,sss,ss,step;
double x;
int main(){
    scanf("%lld%lld%lld%lld",&s,&t,&a,&b);
    if(a==0&&b==0) return printf("%d",(s==t)?0:-1),0;
    if(b==0) return printf("%d",((t-s)%a)?-1:(t-s)/a),0;
    if(a==0){
	x=log(t/s)/log(b);
	if(fabs(x-floor(x))<1e-8)
	    printf("%lld",(long long)x);
	else
	    printf("-1");
	return 0;
    }
    ss=s;
    if((t-ss)%a==0){
	sss=(t-ss)/a;
	ans=0;
	sum=sss;
    }
    for(int i=1;;i++){
	ss=ss*b;
	if(ss>t) break;
	if((t-ss)%a) continue;
	sss=(t-ss)/a;
	ans=i;step=i;
	while(sss){
	    if(step==0) break;
	    ans+=sss%b;
	    sss/=b;
	    step--;
	}
	ans+=sss;
	sum=min(ans,sum);
    }
    if(sum==MAXA) printf("-1");
    else printf("%lld",sum);
}
