#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[10000],b[10000],maxa;
int main(){
    b[0]=100000;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
    for(int k=1;k<=1000;k++){
	for(int j=1;j<=n;j++)
	    if(a[j]!=k+j*m-m)
		b[k]++;
	if(b[k]<b[maxa]) maxa=k;
    }
    printf("%d\n",b[maxa]);
    for(int i=1;i<=n;i++)
	if(a[i]<maxa+i*m-m)
	    printf("+ %d %d\n",i,maxa+i*m-a[i]-m);
	else if(a[i]>maxa+i*m-m)
	    printf("- %d %d\n",i,a[i]-maxa-i*m+m);
}
