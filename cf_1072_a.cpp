#include<cstdio>
#include<iostream>
using namespace std;
int n,m,k;
int solve(int n,int m,int k){
    if(k==0) return 0;
    return solve(n-4,m-4,k-1)+2*n+2*m-4;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    printf("%d",solve(n,m,k));
}
