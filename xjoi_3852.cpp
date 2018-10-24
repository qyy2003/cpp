#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int d1,d2,w1,w2,ma,maxa,mina,mb,maxb,minb,maxmin,minmax;
int main(){
    scanf("%d%d%d%d",&d1,&d2,&w1,&w2);
    if(w1<d1||w2<d2) return printf("Impossible"),0;
    ma=d1/w1;mb=w2/d2;
    mina=max(0,ma-w1/2);
    maxa=2*ma-mina;
    minb=max(0,mb-w2/2);
    maxb=2*mb-minb;
    maxmin=max(mina,minb);
    minmax=min(maxa,maxb);
    if(minmax>=maxmin) return printf("Possible"),0;
    return printf("Impossible"),0;
}
