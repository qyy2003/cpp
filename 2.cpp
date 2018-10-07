#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const long long MAXA=1e18;
long long s,t,a,b,ans,sum=MAXA,sss,ss,step;
int main(){
        scanf("%lld%lld%lld%lld",&s,&t,&a,&b);
        long long r=log2(s)/log2(b);
        ss=s;
        if((t-ss)%a==0){
                sss=(t-ss)/a;
                ans=0;
                sum=sss;
        }
        for(int i=1;i<=r;i++){
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

