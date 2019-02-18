#include<bits/stdc++.h>
using namespace std;
const int MAXA=1e4;
queue<int>q;
int n,m,a[2000000],ans,x,y,f[2000000],b[2000000];
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    n=unique(a+1,a+n+1)-(a+1);
    for(int i=1;i<=n;i++){
	a[i]-=m;
	f[a[i]+MAXA]=1;
	q.push(a[i]);
	b[a[i]+MAXA]=1;
    }
    while(!q.empty()){
	//printf("%d ",x);
	x=q.front(); q.pop();
	if(x==0) return printf("%d",f[x+MAXA]),0;
	for(int i=1;i<=n;i++){
	    if(abs(x+a[i])>1000) continue;
	    if(b[x+a[i]+MAXA]) continue;
	    f[x+a[i]+MAXA]=f[x+MAXA]+1;
	    b[x+a[i]+MAXA]=1;
	    q.push(x+a[i]);
	}
    }
    printf("-1");
    return 0;
}
