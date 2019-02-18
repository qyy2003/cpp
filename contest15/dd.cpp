#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int a[10000];
long long k,x,n,m,y;
long long f1[100],f2[100],f0[100];
int build(int len,int x,int fl){
    if(x<0) return 0;
    int l=1,r=len;
    for(int i=l;i<=r;i++) a[i]=1;
    if(fl==1||fl==3) a[1]=2,l++,fl--;
    if(fl==2) a[len]=0,r--,fl-=2;
    if(r-l+1<x*2) return 0;
    for(int i=0;i<x;i++) a[l+i*2]=0,a[l+i*2+1]=2;
    return 1;
}
int print(int len,int x,int fl){
    printf("$%d %d %d\n",len,x,fl);
    build(len,x,fl);
    for(int i=1;i<=len;i++) printf("%c",'A'+a[i]);
    printf("\n");
}
int main(){
    scanf("%lld%lld%lld%lld",&k,&x,&n,&m);
    f0[0]=1;f0[1]=1;f0[2]=2;
    for(int i=3;i<=k;i++){
	f0[i]=f0[i-1]+f0[i-2];
	//printf("%lld ",f0[i]);
    }
    //printf("\n");
    f1[1]=0;f1[2]=0;
    for(int i=3;i<=k;i++){
	f1[i]=f1[i-1]+f1[i-2];
	if(i&1) f1[i]++;
	//printf("%lld ",f1[i]);
    }
    f2[1]=0;f2[2]=0;
    //printf("\n");
    for(int i=3;i<=k;i++){
	f2[i]=f2[i-1]+f2[i-2]+1;
	//printf("%lld ",f2[i]);
    }
    //printf("%lld %lld\n",f0[k-3],f0[k-2]);
    for(long long i=0;i<=n/2;i++){
	y=x-f0[k-3]*i;
	if(((y)%f0[k-2]==0)&&build(n,i,0)&&build(m,(y)/f0[k-2],0))
	    return print(n,i,0)+print(m,(y)/f0[k-2],0),0;
	y=x-f0[k-3]*(i+1);
	if(((y)%f0[k-2]==0)&&build(n,i,2)&&build(m,(y)/f0[k-2],1))
	    return print(n,i,2)+print(m,(y)/f0[k-2],1),0;
	y=x-f0[k-3]*i-f1[k-1];
	if(((y)%f0[k-2]==0)&&build(n,i,1)&&build(m,(y)/f0[k-2],2))
	    return print(n,i,1)+print(m,(y)/f0[k-2],2),0;
	y=x-f0[k-3]*i-f2[k];
	if(((y)%f0[k-2]==0)&&build(n,i,3)&&build(m,(y)/f0[k-2],3))
	    return print(n,i,3)+print(m,(y)/f0[k-2],3),0;
    }
    printf("Happy new year!");
}

BBBBBA CBBBBBB
BBBBBACBBBBBB
CBBBBBBBBBBBACBBBBBB
BBBBBACBBBBBBCBBBBBBBBBBBACBBBBBB
