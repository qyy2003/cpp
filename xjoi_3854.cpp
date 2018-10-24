#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100],ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=30;~i;i--)
	for(int j=1;j<=n;j++)
	    if(a[j]>=(1<<i)){
		ans|=1<<i;
		a[j]-=(1<<i);
		break;
	    }
    printf("%d",ans);
}
