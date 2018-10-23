#include<cstdio>
#include<iostream>
using namespace std;
int n,x;
char ch;
long long a[3],b[3],P=1e9+7;
int main(){
    ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)){
	x=ch-'0';
	b[x%3]=a[0];b[(x+10)%3]=a[1];b[(x+20)%3]=a[2];
	a[0]+=b[0];a[1]+=b[1];a[2]+=b[2];
	a[x%3]++;
	a[0]%=P; a[1]%=P; a[2]%=P;
	ch=getchar();
    }
    printf("%lld",a[0]);
}
