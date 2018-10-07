#pragma GCC optimize(2,3,"Ofast","inline")
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n;
int b[1000000],s[100000],top,m,flag,ans,sum;
int main(){
scanf("%lld%d",&n,&m);
for(int i=2;i<=m;i++){
if(!b[i]) s[++top]=i;
for(int j=1;j<top;j++){
if(1ll*s[j]*i>m) break;
b[s[j]*i]=1;
if(i%s[j]==0) break;
}
}
for(int i=1;i<=n;i++){
flag=1;
int x=i;
for(int j=1;j<=top;j++)
{
sum=0;
while(x%s[j]==0&&x) sum++,x/=s[j];
if(sum&&(!(sum&1))){
flag=0;
break;
}
}
if(flag) ans++;
}
printf("%d",ans);
}

