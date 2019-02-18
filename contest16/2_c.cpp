#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int MAXA=1e6;
const int P=1e9+7;
int n,x,f[MAXA<<1],a[MAXA<<1];
int add(int x,int y){
    y=(y-a[x]+P)%P;
    a[x]+=y;
    a[x]%=P;
    while(x<=MAXA){
	f[x]+=y;
	f[x]%=P;
	x+=x&(-x);
    }
}
int ask(int x){
    if(!x) return 0;
    return (ask(x-(x&(-x)))+f[x])%P;
}
	
main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
	scanf("%lld",&x);
	add(x,(ask(x)*x%P+x)%P);
    //printf("%lld\n",ask(MAXA));
    }
    printf("%lld",ask(MAXA));
}
