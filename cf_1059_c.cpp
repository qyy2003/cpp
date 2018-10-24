#include<cstdio>
#include<iostream>
using namespace std;
int n,s[1000006],top,a[1000006];
int solve(int n,int mul){
    if(n==1) return s[++top]=mul;
    if(n==2) return s[++top]=mul,s[++top]=mul*2;
    if(n==3) return s[++top]=mul,s[++top]=mul,s[++top]=mul*3;
    for(int i=1;i<=(n-n/2);i++) s[++top]=mul;
    for(int i=1;i<=n/2;i++) a[i]=a[i*2]/2;
    solve(n/2,mul<<1);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) a[i]=i;
    solve(n,1);
    for(int i=1;i<=n;i++) printf("%d ",s[i]);
}
