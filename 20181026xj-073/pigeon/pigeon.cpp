#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[200005],b[200005],l,r,k,top,opt;
int main(){
    freopen("pigeon.in","r",stdin);
    freopen("pigeon.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
	scanf("%d",&a[n-i+1]);
    }
    while(m--){
	scanf("%d",&opt);
	if(opt==1){
	    n--;
	}
	if(opt==2){
	    scanf("%d",&a[++n]);
	}
	if(opt==3){
	    scanf("%d%d%d",&l,&r,&k);
	    top=0;
	    for(int i=n-r+1;i<=n-l+1;i++)
		b[++top]=a[i];
	    //for(int i=1;i<=top;i++) printf("%d ",b[i]);
	    //printf("\n");
	    nth_element(b+1,b+k,b+top+1);
	    //for(int i=1;i<=top;i++) printf("%d ",b[i]);
	    //printf("\n");
	    printf("%d\n",b[k]);
	}
    }
}

