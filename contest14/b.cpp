#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100000],b[100000],flag1=1,flag2=1;
char ch;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	a[i]=ch-'0';
    }
    for(int i=1;i<=n;i++){
	ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	b[i]=ch-'0';
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
	if(a[i]>=b[i])
	    flag1=0;
	if(a[i]<=b[i])
	    flag2=0;
    }
    if(flag1||flag2) printf("YES");
    else printf("NO");
}
