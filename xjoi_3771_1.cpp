#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int K,n,m,a[1000][1000];
int main(){
    scanf("%d",&K);
    if(K<=98){
	if(K<50) K++;
	n=(K>49)?K-48:1;
	m=(K>49)?50:K;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++,printf("\n"))
	    for(int j=1;j<=m;j++)
		printf(".");
	return 0;
    }
    K++;
    m=50;n=(K&1)?44:45;
    for(int i=1;i<=m;i++) a[1][i]=1;
    K-=m+n-1;int last=m,dir=-1;
    for(int i=2;i<=n;i++){
	a[i][last]=1;
	if(i&1){
	    for(int j=1;j<=min(K/2,49);j++){
		last+=dir;
		a[i][last]=1;
	    }
	    if(dir==1) K-=(K>=98)?98:K;
	    //printf("%d\n",K);
	    dir*=-1;
	}
    }
    printf("%d %d\n",n,m);
    for(int i=1;i<=n;i++,printf("\n"))
	for(int j=1;j<=m;j++)
	    if(a[i][j]) printf(".");
	    else printf("#");
}

