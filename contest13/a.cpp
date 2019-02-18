#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x,ans;
int main(){
    scanf("%d%d%d",&n,&m,&x);
    x*=2;
    if((n>=x)&&(m>=x)) printf("Second");
    else printf("First");
}

