#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int t,n,a[10000];
int main()
{
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int ans=0;
        for(int i=n;i>=2;i--)
            a[i]=a[i]-a[i-1];
        for(int i=n;i>=1;i-=2)
            ans^=a[i];
        if(ans) printf("TAK\n");
        else
            printf("NIE\n");
    }
}


