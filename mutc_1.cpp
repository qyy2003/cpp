#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
long long ans;
int n,x;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d",&x);
	if(x%3==0) {
	    printf("%lld\n",1ll*(x/3)*(x/3)*(x/3));
	    continue;
	}
	if(x%4==0){
	    printf("%lld\n",1ll*(x/2)*(x/4)*(x/4));
	    continue;
	}
	printf("-1\n");
    }
}

