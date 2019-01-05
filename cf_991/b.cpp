#include<cstdio>
#include<algorithm>
using namespace std;
double a[100000],sum;
int n;
int main(){
    scanf("%d",&n);
    double st=4.50*n;
    for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum+=a[i];
    if(st<=sum) return printf("%d",0),0;
    for(int i=1;i<=n;i++){
	sum-=a[i];
	sum+=5;
	if(st<=sum) return printf("%d",i),0;
    }
}

