#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,a[110006],b[110006];
long long ans;
int main(){
scanf("%d",&n);
ans=n;
for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
sort(a+1,a+n+1);
sort(b+1,b+n+1);
for(int i=1;i<=n;i++){
ans+=max(a[i],b[i]);
}
cout<<ans;
}
