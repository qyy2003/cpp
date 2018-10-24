#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,q,a,b,last,ans;
int main(){
    scanf("%d%d%d",&n,&m,&q);
    last=0;
    for(int i=1;i<=n;i++){
	scanf("%d%d",&a,&b);
	ans+=(a-last)/q;
	last=a+b;
    }
    ans+=(m-last)/q;
    printf("%d",ans);
}
