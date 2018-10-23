#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long a[100006],b[100005],c[100005];
int n,flag,flag1,flag2;
int solve(int pos,int mul){
    if(pos>n) return 1;
    flag1=(a[pos]&(1ll<<mul))?1:0;
    flag2=(b[pos]&(1ll<<mul))?1:0;
    if(flag2&&(!flag1)) return 0;
    if(flag1&&flag2){
	if(c[pos-1]&(1ll<<mul))
	    c[pos]|=1ll<<mul;
	else
	    return 0;
    }
    if(flag1&&(!flag2))
	if(!(c[pos-1]&(1ll<<mul)))
	    c[pos]|=1ll<<mul;
    if((!flag1)&&(!flag2)&&(c[pos-1]&(1ll<<mul))) return 0;
    // printf("!%d %d\n",pos,c[pos]);
    return solve(pos+1,mul);
}
int main(){
    scanf("%d",&n);flag=1;n++;
    for(int i=2;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=2;i<=n;i++) scanf("%lld",&b[i]);
    for(int i=2;i<=n;i++) b[i]-=a[i];
    for(int j=0;j<=60;j++)
    if(!solve(2,j)){
	for(int i=1;i<=n;i++) c[i]&=((1ll<<61)-1)^(1ll<<j);
	c[1]|=1ll<<j;
	if(!solve(2,j)) return printf("Impossible"),0;
    }
    printf("Possible\n");
}
//a+b=(a&b)+(a|b);
