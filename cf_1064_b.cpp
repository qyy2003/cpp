#include<cstdio>
#include<algorithm>
using namespace std;
int n,yy;
int sum(int x){
	int ans=0;
	while(x){
		if(x&1) ans++;
		x>>=1;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&yy);
		printf("%d\n",1<<sum(yy));
	}
}
