#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[10000],ans,an;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	ans+=a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
	an+=a[i];
	ans-=a[i];
	if(an>ans)
	    return printf("%d",n-i+1),0;
    }
}

