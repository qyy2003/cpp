#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const long long MAXA=1e18;
long long s,t,a,b,ans=MAXA,sum=0,sss,ss,step,x;
int main(){
    scanf("%lld%lld%lld%lld",&s,&t,&a,&b);
    if(s==t) return printf("0"),0;
    if(b==0){
	if(a==0) return printf("%lld",((t==0)?1ll:-1ll)),0;
        if(((t-s)%a)==0&&t>s)printf("%lld",(t-s)/a);
	else if(t%a==0ll) printf("%lld",t/a+1ll);
		else printf("-1");
	return 0;	
    }
    if(a==0){
	if(b==1)  return printf("%lld",(s==t)?0ll:(-1ll)),0;
	if(s==0) return printf("-1"),0;
	x=s;
	while(x<t) x=x*b,sum++;
	if(x==t) printf("%lld",sum);
	else printf("-1");
	return 0;
    }
    if(s>t) return printf("-1"),0;
    if(b==1) return printf("%lld",((t-s)%a)?-1ll:(t-s)/a),0;
    if((t-s)%a==0) ans=(t-s)/a;
    if(s==0){
	sum=0;x=t/a;
	while(x) sum+=x%b+1,x/=b;
	ans=min(ans,sum-1);
	if(ans==MAXA) printf("-1");
    	else printf("%lld",ans);
	return 0;
    }
    for(int i=1;i;i++){
	s*=b;
	if(s>t) break;
	if((t-s)%a) continue;
	sum=0;x=(t-s)/a;
	for(int j=1;j<=i;j++)
	    sum+=x%b,x/=b;
	sum+=x;
	ans=min(ans,sum+i);
    }
    if(ans==MAXA) printf("-1");
    else printf("%lld",ans);
}
