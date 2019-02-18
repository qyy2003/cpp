#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int a[10000];
long long k,x,n,m,yy,y;
long long l[100],r[100],ff[100],f[100];
int build(int len,int x,int fl,int fll){
    if(x<0) return 0;
    a[1]=l[fll]; a[len]=r[fll];
    for(int i=2;i<len;i++) a[i]=1;
    for(int i=2;i<len;i++){
	if(!x) break;
	if(a[i-1]==0){
	    a[i]=2;
	    x--;
	}
	else a[i]=0;
    }
    if(len>1&&a[len-1]==0&&a[len]==2) x--;
    if(x) return 0;
    return 1;
}
int print(int len,int x,int fl,int fll){
    //printf("$%lld %lld %lld\n",len,x,fl);
    build(len,x,fl,fll);
    for(int i=1;i<=len;i++) printf("%c",'A'+a[i]);
    printf("\n");
}
int work();
int main(){
    scanf("%lld%lld%lld%lld",&k,&x,&n,&m);
    f[0]=1;f[1]=1;f[2]=2;
    for(int i=3;i<=k;i++) f[i]=f[i-1]+f[i-2];
    for(l[1]=0;l[1]<=2;l[1]++) {//if(l[1]==1&&n>1) continue;
    for(l[2]=0;l[2]<=2;l[2]++) {//if(l[2]==1&&m>1) continue;
    for(r[1]=0;r[1]<=2;r[1]++) {//if(r[1]==1&&n>1) continue;
    for(r[2]=0;r[2]<=2;r[2]++) {//if(r[2]==1&&m>1) continue;
	if(n==1&&l[1]!=r[1]) continue;
	if(m==1&&l[2]!=r[2]) continue;
	yy=x-work();
	//printf("%lld %lld %lld %lld %lld\n",l[1],r[1],l[2],r[2],y);
	for(long long i=0;i<=n/2;i++){
	y=yy-f[k-3]*i;
	if((y%f[k-2]==0)&&build(n,i,0,1)&&build(m,y/f[k-2],0,2))
	    return print(n,i,0,1)+print(m,y/f[k-2],0,2),0;
	}
    }}}}
    printf("Happy new year!");
}
int work(){
    for(int i=3;i<=k;i++){
	l[i]=l[i-2];
	r[i]=r[i-1];
	ff[i]=ff[i-1]+ff[i-2];
	if(r[i-2]==0&&l[i-1]==2) ff[i]++;
    }
    return ff[k];
}
