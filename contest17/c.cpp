#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[10000],b[10000],c[10000];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    for(int i=1;i<n;i++) printf("(");
    for(int i=1;i<=n;i++){
	if(i>1) printf("+");
	printf("(%d*((1-abs((t-%d)))+abs((abs((t-%d))-1))))",a[i]/2,i-1,i-1);
	if(i>1) printf(")");
    }
    printf("\n");
    for(int i=1;i<n;i++) printf("(");
    for(int i=1;i<=n;i++){
	if(i>1) printf("+");
	printf("(%d*((1-abs((t-%d)))+abs((abs((t-%d))-1))))",b[i]/2,i-1,i-1);
	if(i>1) printf(")");
    }
    printf("\n");
}
