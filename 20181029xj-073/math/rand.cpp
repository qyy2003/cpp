#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
int n;
int main(){
    freopen("math.in","w",stdout);
    srand(time(NULL));
    //scanf("%d",&n);
    n=10;
    printf("%d\n",n);
    for(int i=1;i<=n;i++) printf("%d ",rand()%8);
}
