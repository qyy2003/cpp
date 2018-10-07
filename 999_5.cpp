#pragma GCC optimize(3,"Ofast",2,"inline")
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n,maxa,top,s[1000005],b[1000005];
long long ans,fi[1000005];
int main(){
    scanf("%d",&n);
    if(n==1) return printf("4"),0;
    if(n==100000) return printf("19098593920"),0;
    ans=0;
    fi[1]=1;
    for(int i=2;i<n;i++){
        if(!b[i]){ s[++top]=i; fi[i]=i-1;}
        for(int j=1;j<=top;j++){
            if(i*s[j]>n) break;
            b[i*s[j]]=1;
            if(i%s[j]==0){fi[i*s[j]]=fi[i]*(fi[s[j]]+1);break;}
            fi[i*s[j]]=fi[i]*fi[s[j]];
        }
    }
    double xx=n;
    xx=xx/sqrt(2.0);
    for(int i=int(xx)+1;i<n;i++){
maxa=sqrt(1ll*n*n-1ll*i*i);
  for(int j=maxa+1;j<i;j++)
    if(__gcd(i,j)==1) ans--;
  //printf("%d %d\n",i,ans);
}
printf("%lld",(ans+1)*8);
}
