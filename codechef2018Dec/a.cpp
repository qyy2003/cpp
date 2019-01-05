#include<cstdio>
#include<iostream>
using namespace std;
int n,m,x;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
	scanf("%d",&x);
	if(x<m) printf("Bad boi\n");
	else printf("Good boi\n");
    }
}
