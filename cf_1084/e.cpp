#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
long long n,k,num1,num2,num,ans,last;
char s1[1000000],s2[1000000];
int main(){
    scanf("%lld%lld",&n,&k);
    scanf("%s",s1);
    scanf("%s",s2);
    num1=0; num2=0;last=0;
    for(int i=0;i<n;i++){
	num1=(num1<<1)+s1[i]-'a';
	num2=(num2<<1)+s2[i]-'a';
	num=num2-num1+1;
	if(k<=num-last){
	    ans+=k*(n-i);
	    break;
	}
	else ans+=(num-last)*(n-i),k-=num-last;
	last=num;
    }
    printf("%lld",ans);
    return 0;
}
