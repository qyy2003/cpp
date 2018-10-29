#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int n,x,f[155][155][10];
int dp(int l,int r,int x){
    if(~f[l][r][x]) return f[l][r][x]; 
    if(l==r) return f[l][r][x]=0;
    for(int i=l;i<r;i++)
	for(int ll=x,rr=x;ll>=0&&rr<=7;ll--,rr++){
	    if((dp(l,i,ll)&&dp(i+1,r,rr))||(dp(l,i,rr)&&dp(i+1,r,ll))) return f[l][r][x]=1;
	    if((dp(l,i,ll+1)&&dp(i+1,r,rr))||(dp(l,i,rr)&&dp(i+1,r,ll+1))) return f[l][r][x]=1;
	    if(rr+1<=7&&((dp(l,i,ll)&&dp(i+1,r,rr+1))||(dp(l,i,rr+1)&&dp(i+1,r,ll)))) return f[l][r][x]=1;
	}
    return f[l][r][x]=0;
}
int main(){
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    scanf("%d",&n);
    memset(f,-1,sizeof(f));
    for(int i=1;i<=n;i++) scanf("%d",&x),f[i][i][x]=1;
    for(int i=0;i<=7;i++)
	if(dp(1,n,i))
	    printf("%d ",i);
}
