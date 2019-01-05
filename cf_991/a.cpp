#include<cstdio>
#include<algorithm>
using namespace std;
int x,y,z,n;
int main(){
    scanf("%d%d%d%d",&x,&y,&z,&n);
    if(max(x,max(y,z))>n) return printf("-1"),0;
    if(x+y-z<0) return printf("-1"),0;
    if(min(x,y)<z) return printf("-1"),0;
    if(x+y-z>=n) return printf("-1"),0;
    printf("%d",(n-(x+y-z)));
}

