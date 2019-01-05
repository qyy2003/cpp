#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,x,y,ansx,ansy;
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=2*n;i++){
	scanf("%lld%lld",&x,&y);
	ansx+=x;ansy+=y;
    }
    ansx/=n;ansy/=n;
    printf("%lld %lld",ansx,ansy);
}
