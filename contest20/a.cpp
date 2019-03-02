#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int k,a,b,v,ans;
int main(){
    scanf("%d%d%d%d",&k,&a,&b,&v);
    if(a%v==0) a=a/v;
    else a=a/v+1;
    while(b&&(a>0)){
	ans++;
	if(b>=k-1){
	    b-=k-1;
	    a-=k;
	}
	else{
	    a-=b+1;
	    b=0;
	}
    }
    //printf("%d\n",a);
    if(a>0) ans+=a;
    printf("%d",ans);
}
