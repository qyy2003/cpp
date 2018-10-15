#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int a[10];
int main(){
scanf("%d%d%d",&a[1],&a[2],&a[3]);
sort(a+1,a+4);
printf("%d",max(a[3]-(a[2]+a[1])+1,0));
}
