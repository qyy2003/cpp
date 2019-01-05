#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int a[1000],tot,sum,n,ans,an,top;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
    }
    ans=1e8; 
    for(int i=1;i<=n;i++){
	sum=0;
	for(int j=1;j<=n;j++){
	    sum+=abs(i-j)*a[j]+i*a[j]-a[j];
	}
	ans=min(ans,sum);
    }
    printf("%d",ans*4);
    return 0;
}
