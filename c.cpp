#include<cstdio>
#include<iostream>
using namespace std;
int n,s[1000007],top,now;
int solve(int maxa,int mul){

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) sq[i]=i;
    int nn=n;
    solve(n,1);
    for(int i=nn;i>=1;i++){
	printf("%d ",s[i]);
    }
}
