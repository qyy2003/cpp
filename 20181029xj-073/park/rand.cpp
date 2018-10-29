#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
int n,x,y,m,q;
int main(){
    freopen("park.in","w",stdout);
    srand(time(NULL));
    scanf("%d%d",&n,&m);
    printf("%d %d\n",n,m);
    for(int i=1;i<=n;i++) printf("%d ",rand()%10001);
    printf("\n");
    for(int i=1;i<=n;i++) printf("%d ",rand()%1000001);
    printf("\n");
    for(int i=1;i<=m;i++){
	x=rand()%n+1;
	y=rand()%n+1;
	if(x>y) swap(x,y);
	printf("%d %d %d\n",x,y,rand()%1000001);
    }
}
