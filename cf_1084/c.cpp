#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
long long top,suma,sumb,sum,ans;
char ch,s[1000000];
int main(){
    long long P=1e9+7;
    ch=getchar();
    while(!('a'<=ch&&ch<='z')) ch=getchar();
    top=0;
    while(('a'<=ch&&ch<='z')) s[++top]=ch,ch=getchar();
    while(top){
	if(s[top]=='a'){
	sum=suma+1;
	sumb+=sum;
	ans+=sum;
	}
	if(s[top]=='b')
	    suma=sumb;
	suma%=P;
	sumb%=P;
	sum%=P;
	ans%=P;
	top--;
    }
    printf("%lld",ans);
    return 0;
}
