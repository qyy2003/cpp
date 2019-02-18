#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,ans,an;
int main(){
    scanf("%d%d",&n,&m);
    ans+=n;an+=n;
    while(n>=m){
	ans+=n/m;
	n=(n/m)+n%m;
	}
    printf("%d",ans);
}
