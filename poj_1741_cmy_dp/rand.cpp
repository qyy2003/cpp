#include<cstdio>
#include<iostream>
using namespace std;
int print(){
    printf("%d %d\n",10,20);
    for(int i=1;i<=9;i++)
	printf("%d %d %d\n",i+1,rand()%i+1,rand()%20+1);
}
int main(){
    int n;
    //scanf("%d",&n);
    n=1;
    srand(time(NULL));
    for(int i=1;i<=n;i++) print();
    printf("0 0\n");
}
