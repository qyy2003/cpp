#include<cstdio>
#include<algorithm>
using namespace std;
int n,d,x,y,T;
int check(int x,int y){
    if(y-x>d) return 1;
    if(x+y<d) return 1;
    if(x-y>d) return 1;
    x=n-x; y=n-y;
    if(x+y<d) return 1;
    return 0;
}
int main(){
    scanf("%d%d",&n,&d);
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
	scanf("%d%d",&x,&y);
	if(check(x,y)) printf("NO\n");
	else printf("YES\n");
    }
}
