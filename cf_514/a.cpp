#include<cstdio>
#include<algorithm>
using namespace std;
long long m,n,st,x;
int main(){
    scanf("%lld",&n);
    m=n;
    st=1;
    while(st<=n){
	x=n%(st*10)/st;
	n-=x*st;
	x=min(x,9-x);
	n+=x*st;
	st*=10;
    }
    st/=10;
    if(st>n) n+=st*9;
    printf("%lld",n);
}
