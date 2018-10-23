#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    srand(time(NULL));
    n=1000;m=1000;
    printf("%d %d\n",n,m);
    for (int i=1;i<=n;++i)
	printf("%lld ",1ll*rand()*rand()%1000007);
    printf("\n");
    for (int i=1;i<=m;++i){
	printf("%d %lld\n",rand()%n+1,1ll*rand()*rand()%100000007);
    }
}
