#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,a[2000000],f[2000000],flag,ans,maxa,maxb,x,suma;
char s[2000000];
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    scanf("%s",s+1);
    for(int i=n;i>=1;i--){
	if(s[i]=='L') f[i]=f[i+1]+a[i];
	else f[i]=f[i+1]-a[i];
	f[i]=max(0ll,f[i]);
    }
    flag=0;
    maxa=0;
    for(int i=1;i<=n;i++){
	if(s[i]=='G'){
	    ans+=a[i]*5ll;
	    maxa+=a[i];
	    if(f[i+1]<maxa){
		x=min(maxa-f[i+1],a[i]*2ll);
		ans-=x*2ll;
		maxa-=x;
	    }
	    continue;
	}
	if(s[i]=='W'){
	    ans+=a[i]*3ll;
	    maxa+=a[i];
	    flag=1;
	    continue;
	}
	if(s[i]=='L'){
	    if(maxa<a[i]){
		if(flag) {
		    ans+=(a[i]-maxa)*3ll;
		}
		else{
		    ans+=(a[i]-maxa)*5ll;
		}
		maxa=a[i];
	    }
	    ans+=a[i];
	    maxa-=a[i];
	}
    }
    ans-=maxa;
    printf("%lld",ans);
}
