#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[2000000],sum[2000000];
int s[2000000];
long long m;
int main(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int top=1;
    s[top]=a[1];
    sum[top]++;
    for(int i=2;i<=n;i++){
	if(a[i]!=s[top]) s[++top]=a[i];
	sum[top]++;
    }
    //for(int i=1;i<=top;i++) printf("%d %d\n",s[i],sum[i]);
    for(int i=1;i<=top;i++){
	if(m<=1ll*n*sum[i]){
	    for(int j=1;j<=n;j++){
		m-=sum[i];
		if(m<=0ll)
		    return printf("%d %d",s[i],a[j]),0;
		}
	}
	m-=1ll*n*sum[i];
    }
}
