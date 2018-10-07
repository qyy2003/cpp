#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int n=1e6;
const int P=998244353;
int bo[n+1000],s[n+100],top,bb[n*10+1000];
long long l,r,b[n*10+1000],ans,ansb;
int main(){
    scanf("%lld%lld",&l,&r);
    for(int i=2;i<=n;i++)
    {
        if(!bo[i]) s[++top]=i;
            for(int j=1;j<=top;j++){
                if(1ll*i*s[j]>n) break;
                bo[i*s[j]]=1;
		if(i%s[j]==0) break;
            }
    }
    for(int i=top;i>=1;i--)
        for(long long j=(l%s[i])?(l/s[i])+1:l/s[i];j<=r/s[i];j++)
            if(1<j)
                b[1ll*j*s[i]-l]=s[i],bb[1ll*j*s[i]-l]=1;
    for(int i=0;i<=r-l;i++)
        ans+=b[i],ans%=P,ansb+=bb[i];
    printf("%lld %lld",ansb,ans);
}
//846786265990 846786266025

