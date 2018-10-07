#include<cstdio>
#include<iostream>
using namespace std;
long long seed;
inline long long rand(long long l, long long r) {
    static long long mo=1e9+7, g=78125;
    return l+((seed*=g)%=mo)%(r-l+1);
} 
int main(){
    int n,cnt;
    scanf("%d",&cnt);
    long long maxa,maxb,mina,minb,x,y;
    while(cnt--)
    {
        scanf("%d%lld",&n,&seed);
        maxa=-1e9; maxb=-1e9; mina=1e9; minb=1e9;
        for(int i=1;i<=n;i++)
        {
            x = rand(-1000000000, 1000000000),
              y = rand(-1000000000, 1000000000); 
            maxa=max(maxa,x+y);
            mina=min(mina,x+y);
            maxb=max(maxb,x-y);
            minb=min(minb,x-y);
        }
        printf("%lld\n",max(maxa-mina,maxb-minb));
    }
}

