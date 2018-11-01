#include<cstdio>
#include<iostream>
#include<time.h>
#include<algorithm>
using namespace std;
int main(){
    srand(time(NULL));
    freopen("pow.in","w",stdout);
    printf("%lld %lld %lld %lld\n%lld %lld %lld %lld",
    1ll*rand()*rand()%1000000000,
    1ll*rand()*rand()%1000000000,
    1ll*rand()*rand()%10000000,
    1ll*rand()*rand()%10000,
    1ll*rand()*rand()%1000000000000,
    1ll*rand()*rand()%1000000000000,
    1ll*rand()*rand()%1000000,
    1ll*rand()*rand()%1000000);
}
