#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,c,flag;
int main(){
    scanf("%d%d",&n,&c);
    int l=1,r=n,mid,ans=1,rest=1000;
    while(l<=r){
	if(c<=0) break;
	mid=(r+l)>>1;
	printf("1 %d\n",mid);
	fflush(stdout);
	rest--;
	scanf("%d",&flag);
	rest-=c;
	if(rest>=0) printf("%d\n",2);
	fflush(stdout);
	if(flag) r=mid-1;
	else ans=mid,l=mid+1;
    }
    printf("3 %d\n",ans);
    fflush(stdout);
}
