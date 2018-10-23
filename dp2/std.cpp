#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int aa,bb,x,y,last;
int a[1000000],b[1000000];
int search(int *a,int len,int n) {
    int right=len,left=0,mid=(left+right)/2;
    while(left<=right) {
	if (n>a[mid]) left=mid+1;
	else if (n<a[mid]) right=mid-1;
	else return mid;
	mid=(left+right)/2;
    }
    return left;
}
int main() {
    //freopen("kite1.in","r",stdin);
    //freopen("kite.out","w",stdout);
    int n,i,j,mid,len;
    scanf("%d%d",&n,&aa);
    for (int i=1; i<=n; ++i)scanf("%d",&a[i]);
    for (int l=1; l<=aa; ++l) {
	scanf("%d%d",&x,&y);
	last=a[x]; a[x]=y;
	memset(b,0,sizeof(b));
	b[1]=a[1];
	b[0]=-1;
	len=1;
	for (i=1; i<=n; i++) {
	    j=search(b,len,a[i]);
	    b[j]=a[i];
	    if (j>len) len=j;
	}
	printf("%d\n",len);
	a[x]=last;
    }
    return 0;
}
