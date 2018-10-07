#pragma GCC optimize("Ofast",3,"inline")

#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,a[7000005],last;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    last=1;
    for(int i=2;i<=n;i++)
        if(a[i]!=a[i-1])
        {
            printf("%d %d\n",a[i-1],i-last);
            last=i;
        }
    printf("%d %d",a[n],n+1-last);
}
