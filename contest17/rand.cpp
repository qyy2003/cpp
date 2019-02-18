#include<bits/stdc++.h>
using namespace std;
const long long MAXA=1e18;
int n=10,m=10;
int main(){
    srand(time(NULL));
    printf("%d %d\n",n,m);
    for(int i=2;i<=n;i++){
	printf("%d %d %lld\n",(rand()%(i-1))+1,i,1ll*rand()*rand()%MAXA+1);
    }
    for(int i=1;i<=m/2;i++){
	printf("2 %d %lld\n",rand()%n+1,1ll*rand()*rand()%MAXA+1);
    }
    for(int i=1;i<=m-m/2;i++){
	printf("1 %d %d %lld\n",rand()%n+1,rand()%n+1,1ll*rand()*rand()%MAXA+1);
    }
}
