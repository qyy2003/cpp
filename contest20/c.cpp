#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int b[100],x,y,n,m,bo[100][100];
int ask(int y){
    int x=0;
    for(int i=1;i<=n;i++)
	if((b[x]>b[i])&&(i!=y)&&(!bo[y][i]))
	    x=i;
    return x;
}
int solve(){
    scanf("%d%d",&n,&m);
    memset(b,0,sizeof(b));
    b[0]=1000;
    memset(bo,0,sizeof(bo));
    for(int i=1;i<=m+2*n;i++){
	x=ask(0);
	y=ask(x);
	bo[x][y]=bo[y][x]=1;
	b[x]++; b[y]++;
	printf("%d %d\n",x,y);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
}
