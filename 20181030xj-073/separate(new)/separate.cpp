#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[2005][2005],sum1[2005][2005],maxa,mina;
int check(int x){
    int flag=1;
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	    if(a[i][j]>mina+x)
		sum1[i][j]=sum1[i][j-1]+1;
	    else
		sum1[i][j]=sum1[i][j-1];
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		sum1[i][j]+=sum1[i-1][j];
    /*
    for(int i=1;i<=n;i++,printf("\n"))
	for(int j=1;j<=m;j++)
	    printf("%d ",sum1[i][j]);
	    */
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	    if(a[i][j]<maxa-x)
		if(sum1[i][j]){
		    flag=0;
		    break;
		}
    if(flag) return 1;
    flag=1;
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	    if(a[i][j]<maxa-x)
		if(sum1[i][m]-sum1[i][j-1]){
		    flag=0;
		    break;
		}
    if(flag) return 1;
    flag=1;
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	    if(a[i][j]<maxa-x)
		if(sum1[n][j]-sum1[i-1][j]){
		    flag=0;
		    break;
		}
    if(flag) return 1;
    flag=1;
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	    if(a[i][j]<maxa-x)
		if(sum1[n][m]-sum1[n][j-1]-sum1[i-1][m]+sum1[i-1][j-1]){
		    flag=0;
		    break;
		}
    if(flag) return 1;
    return 0;
}

int main(){
    mina=1e9;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
	    scanf("%d",&a[i][j]);
	    maxa=max(maxa,a[i][j]);
	    mina=min(mina,a[i][j]);
	}
//    return printf("%d",check(11)),0;
    int l=0,r=1e9,mid,ans;
    while(l<=r){
	mid=(l+r)>>1;
//	printf("%d %d %d %d\n",l,r,mid,check(mid));
	if(check(mid)) ans=mid,r=mid-1;
	else l=mid+1;
    }
    printf("%d",ans);
}
