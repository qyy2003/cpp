#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,x,maxa,mina;
int main(){
    scanf("%d",&n);
    maxa=2*1e9;
    mina=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        maxa=min(maxa,x);
        mina=max(mina,x);
    }
    printf("%d",mina-maxa+1-n);
}
