#include<cstdio>
#include<algorithm>
using namespace std;
int n,maxa,a[100000];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),maxa=max(maxa,a[i]);
    for(int j=1;j<=maxa;j++){
	    if(a[1]>=j) printf("P");
	    for(int i=2;i<=n;i++){
		printf("R");
		if(a[i]>=j) printf("P");
	    }
	    for(int i=1;i<n;i++) printf("L");
	}
}

