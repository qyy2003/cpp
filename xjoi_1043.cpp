#include<cstdio>
#include<iostream>
using namespace std;
int n,m,son[1000],last,x;
int main(){
    scanf("%d",&n);
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
	scanf("%d",&m);
	if(m==0){
	    printf("0 %d\n",son[i]);
	    continue;
	}
	scanf("%d",&last);
	printf("%d ",last);
	for(int j=2;j<=m;j++){
	    scanf("%d",&x);
	    son[last]=x;
//	    printf("!%d %d!\n",last,x);
	    last=x;
	}
	printf("%d\n",son[i]);
    }
}

