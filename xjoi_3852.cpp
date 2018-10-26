#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
double d1,d2,w1,w2;
int mina,maxa,maxb,minb,x;
int main(){
    scanf("%lf%lf%lf%lf",&d1,&d2,&w1,&w2);
    maxa=floor(w1/d1+d1/2.0)+1;mina=ceil(w1/d1-d1/2.0)-1;
    if(1ll*d1*(d1+1.0)/2.0>=w1){
	x=(w1*8.0+1.0);
	maxa=floor((sqrt(x)-1.0)/2.0);
	maxa++;
	mina=-1;
    }
    maxb=floor(w2/d2+d2/2.0);minb=ceil(w2/d2-d2/2.0);
    if(1ll*d2*(d2+1.0)/2.0>=w2){
	x=(w2*8.0+1.0);
	maxb=floor((sqrt(x)-1.0)/2.0);
	//maxb=sqrt(w2*2.0);
	minb=0;
    }
    printf("%d %d %d %d",maxa,mina,maxb,minb);
    if(mina>maxb||maxa<minb)
    return printf("Impossible"),0;
    return printf("Possible"),0;
}
