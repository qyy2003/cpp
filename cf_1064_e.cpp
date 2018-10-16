#include<cstdio>
#include<algorithm>
using namespace std;
int n,mid,midd;
char s[1000];
int main(){
	scanf("%d",&n);
	int l=0,r=1e9,ll=0,rr=1e9/3;
	for(int i=1;i<=n;i++){
			mid=(l+r)>>1;
		if(l<r-2){
			printf("%d 0\n",mid);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='w')
				l=mid+1;
			else
				r=mid-1;
		}
		else{
			midd=(ll+rr)>>1;
			printf("%d %d\n",mid,midd);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='b')
				ll=midd+1;
			else
				rr=midd-1;
			}
	}
	mid=(l+r)>>1;midd=(ll+rr)>>1;
	printf("%d %d %d %d\n",mid,midd,mid+1,midd*2+1);
}
