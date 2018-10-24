#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100006],b[100005],c[100005],flag,flag1,flag2;
int solve(int pos,int mul){
    if(pos>n) return 1;
    flag1=(a[pos]&(1<<mul))?1:0;
    flag2=(b[pos]&(1<<mul))?1:0;
    if(flag2&&(!flag1)) return 0;
    if(flag1&&flag2){
	if(c[pos-1]&(1<<mul))
	    c[pos]|=1<<mul;
	else
	    return 0;
    }
    if(flag1&&(!flag2))
	if(!(c[pos-1]&(1<<mul)))
	    c[pos]|=1<<mul;
    if((!flag1)&&(!flag2)&&(c[pos-1]&(1<<mul))) return 0;
   // printf("!%d %d\n",pos,c[pos]);
    return solve(pos+1,mul);
}
int main(){
    scanf("%d",&n);flag=1;
    for(int i=2;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<=n;i++) scanf("%d",&b[i]);
    if(!solve(2,1)){
	for(int i=1;i<=n;i++) c[i]=0;
	c[1]=2;
	if(!solve(2,1)) return printf("NO"),0;
    }
    if(!solve(2,0)){
	for(int i=1;i<=n;i++) c[i]&=2;
	c[1]|=1;
	if(!solve(2,0)) return printf("NO"),0;
    }
    printf("YES\n");
    for(int i=1;i<=n;i++) printf("%d ",c[i]);
}
