#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,a[2000000],flag,ans,maxa,maxb,x;
char s[2000000];
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    scanf("%s",s);
    flag=0;
    for(int i=1;i<=n;i++){
	if(s[i-1]=='G'){
	    ans+=a[i]*5ll;
	    maxa+=a[i];
	    continue;
	}
	if(s[i-1]=='W'){
	    ans+=a[i]*3ll;
	    maxb+=a[i];
	    flag=1;
	    continue;
	}
	if(s[i-1]=='L'){
	    if(maxa+maxb<a[i]){
		if(flag) {
		    ans+=(a[i]-maxb-maxa)*3ll;
		    maxb=a[i]-maxa;
		}
		else{
		    ans+=(a[i]-maxa)*5ll;
		    maxa=a[i];
		}
	    }
	    ans+=a[i];
	    x=min(maxb,a[i]);
	    maxb-=x;
	    a[i]-=x;
	    maxa-=a[i];
	}
    }
    ans-=maxa*2+maxb;
    printf("%lld",ans);
}



