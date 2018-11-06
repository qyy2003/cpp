#include<cstdio>
#include<iostream>
using namespace std;
int n,a[1000],ans,sum,flag;
int read(int &x){
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    x=ch-'0';
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) read(a[i]),sum+=a[i];
    if(!sum){
	if(n>1) return printf("YES\n"),0;
	return printf("NO\n"),0;
    }
    for(int num=0;num<sum;num++){
	ans=0;flag=1;
	for(int i=1;i<=n;i++){
	    ans+=a[i];
	    if(ans>num) {
		flag=0;
		break;
	    }
	    if(ans==num) ans-=num;
	}
	if(flag&&(!ans)) return printf("YES\n"),0;
    }
    printf("NO\n");
}


