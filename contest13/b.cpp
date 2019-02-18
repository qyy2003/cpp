#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a,b,x;
int main(){
    scanf("%d%d",&n,&m);
    scanf("%d",&a);
    if(n<m) return printf("0/1"),0;
    for(int i=1;i<=n;i++) scanf("%d",&x);
    scanf("%d",&b);
    for(int i=1;i<=m;i++) scanf("%d",&x);
    if(a*b<0) printf("-");
    a=abs(a);
    b=abs(b);
    x=__gcd(a,b);
    a/=x;
    b/=x;
    if(n>m) return printf("Infinity"),0;
    printf("%d",a);
    putchar('/');
    printf("%d",b);
}
