#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[1000000],f[1000000];
long long sum;
int main(){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
                f[i]=min(i,n-i+1)+min(i-1,n-i+1);
                sum=sum+f[i];
        }
        sum=sum/2+1;
        for(int i=1;i<=n;i++){
                sum-=f[i];
                if(sum<=0){
                        printf("%d",a[i]);
                        return 0;
                }
        }
}
