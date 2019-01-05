#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,an[1000],ans,w1=1,w2=1,a0=0,top=0;
void work(){
    ans+=(top-a0)*w1/(w2*top);
}
void dfs(int x){
    //printf("%d %lld %lld %lld\n",x,w1,w2,ans);
    //fflush(stdout);
    if(x==10) return work();
    if(an[x]==0) return dfs(x+1);
    for(long long i=1;i<=an[x];i++){
	w1*=++top;
	w2*=i;
	dfs(x+1);
    }
    for(long long i=1;i<=an[x];i++){
	w1/=top;
	top--;
	w2/=i;
    }
}
int main(){
    scanf("%lld",&n);
    while(n){
	an[n%10]++;
	n/=10;
    }
    if(an[0]==0) dfs(1);
    for(a0=1;a0<=an[0];a0++){
    w1*=++top;
    w2*=a0;
    dfs(1);
    }
    printf("%lld",ans);
}
/*
10
100
110
101
1100
1010
1001
*/
