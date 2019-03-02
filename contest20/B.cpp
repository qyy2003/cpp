#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXA=1e5;
int n,m,a[MAXA<<1],mina,ans,b[MAXA<<1],s[MAXA],an,x,top,gcd[MAXA<<1],gcdd;
void pre(){
    for(int i=2;i<=MAXA;i++){
	if(!b[i]) s[++top]=i;
	for(int j=1;j<=top;j++){
	    if(i*s[j]>MAXA) break;
	    b[i*s[j]]=1;
	    if(i%s[j]==0) break;
	}
    }
}
int ask(long long x){
    int an=0,xx;
    for(int i=1;i<=m;i++){
	xx=b[i];
	    while(x%xx==0){
		x/=xx;
		an--;
	    }
	}
    for(int i=1;i<=top;i++){
	xx=s[i];
	    while(x%xx==0){
		x/=xx;
		an++;
	    }
    }
    if(x>1) an++;
    return an;
}

int main(){
    pre();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
	scanf("%d",&b[i]);
    gcd[1]=a[1];
    for(int i=2;i<=n;i++)
	gcd[i]=__gcd(gcd[i-1],a[i]);
    gcdd=1;
    for(int i=n;i;i--){
	if(ask(gcd[i]/gcdd)<0){
	    gcdd=gcd[i];
	}
	a[i]/=gcdd;
	ans+=ask(a[i]);
    }
    printf("%d",ans);
}



