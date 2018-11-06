#include<cstdio>
#include<iostream>
using namespace std;
int n,x;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d",&x);
	if(x) return printf("HARD"),0;
    }
    printf("EASY");
}
