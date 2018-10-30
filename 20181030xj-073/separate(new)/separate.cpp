#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[2005][2005],f[2005][2005];
int check(int x){
    ll=maxa-x; rr=mina+x;
    int flag=1;
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	    if(a[i][j]>
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
	    scanf("%d",&a[i][j]);
	    maxa=max(maxa,a[i][j]);
	    mina=min(mina,a[i][j]);
	}
    int l=0,r=1e9,mid,ans;
    while(l<=r){
	mid=(l+r)>>1;
	if(check(mid)) ans=mid,r=mid-1;
	else l=mid+1;
    }
    printf("%d",ans);
}
