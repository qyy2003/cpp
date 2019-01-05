#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,an[3000000],ans,P=998244353;
int main(){
    scanf("%lld",&n);
    an[0]=1;
    for(long long i=1;i<=n;i++) an[i]=an[i-1]*i%P;
    for(long long i=1;i<=n;i++){
	ans=ans*i%P;
	ans+=an[i]-1;
    }
    ans=(ans+1)%P;
    printf("%lld",ans);
}

