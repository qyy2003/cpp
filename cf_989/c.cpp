#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a,b,c,d,xx,yy;
int an[1000][1000];
void col(int x){
    an[xx][yy]=x;
    yy+=2;
    if(yy>50){
	xx+=2;
	yy=1;
    }
}
void make(){
    for(int i=40;i<=50;i++) 
	for(int j=1;j<=50;j++)
	    an[i][j]=1;
    xx=41;yy=1;
    for(int i=1;i<a;i++){
	col(0);
    }
}
int main(){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    b--;
    make();
    xx=1;yy=1;
    for(int i=1;i<=b;i++) col(1);
    for(int i=1;i<=c;i++) col(2);
    for(int i=1;i<=d;i++) col(3);
    printf("%d %d\n",50,50);
    for(int i=1;i<=50;i++,printf("\n"))
	for(int j=1;j<=50;j++)
	    printf("%c",'A'+an[i][j]);
}

