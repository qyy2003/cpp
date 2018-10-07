#include<cstdio>
#include<algorithm>
using namespace std;
long long a,b,x,y;
int main(){
    scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
    long long xx=__gcd(x,y);
    x/=xx;
    y/=xx;
    printf("%lld",min(a/x,b/y));
}
