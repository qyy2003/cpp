#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,now,ans;
int main(){
scanf("%lld",&n);
ans=0;
while(n){
if(n%10<9&&n>=10){
n-=10;
ans+=10;
}
//printf("!%lld %lld",ans,n);
ans+=n%10;
n/=10;
//printf("%lld \n",ans);
}
printf("%lld",ans);
}
