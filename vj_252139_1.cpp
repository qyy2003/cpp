#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;
int l,r;
long long sum,x,y,f,n,m;
pair<long long,long long> s[1000005];
int  cross(int xx1,int yy1,int xx2,int yy2,int xx3,int yy3){
    return (xx2-xx1)*(yy3-yy1)-(xx3-xx1)*(yy2-yy1);
}
int cal(int k,int x,int y){
    return y-k*x;
}
int worse(int k,int xx1,int yy1,int xx2,int yy2){
    if(cal(k,xx1,yy1)<cal(k,xx2,yy2)) return 0;
    return 1;
}
main()
{
    while(scanf("%lld%lld",&n,&m)==2)
    {
        l=0; r=0;f=0;sum=0;
        s[l]=make_pair(0,0);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x); sum+=x;
            while(l<r&&worse(sum,s[l].first,s[l].second,s[l+1].first,s[l+1].second)) l++;
            f=cal(sum,s[l].first,s[l].second)+m+sum*sum;
            x=2*sum; y=f+sum*sum;
            while(l<r&&cross(s[r-1].first,s[r-1].second,x,y,s[r].first,s[r].second)>0) r--;
            s[++r]=make_pair(x,y);
        }
        printf("%lld\n",f);
    }
}
