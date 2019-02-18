#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m;
const int MAXA=1e6;
int ba[MAXA],bb[MAXA],bc[MAXA],bd[MAXA];
int mysort(int x,int y){

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
	scanf("%d%d%d",&ba[i],&bb[i],&bc[i]);
	lsh[++top]=ba[i];
	lsh[++top]=bb[i];
	bd[i]=i;
    }
    sort(bd+1,bd+n+1,mysort);
    for(int i=1;i<=n;i++) printf("%d ",bd[i]);
    for(int i=1;i<=m;i++){
	scanf("%d%d%d",&pa[i],&pb[i],&pc[i]);
	lsh[++top]=pa[i];
	lsh[++top]=pb[i];
	pd[i]=i;
    }
    sort(pd+1,pd+m+1;mysort2);
}
