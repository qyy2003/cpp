#pragma GCC optimize(2,3,"inline","Ofast")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,kk,xx,a[10000];
long long ans,sum,f[10000];
pair<int,int> x;
priority_queue<pair<int,int> > qq;
priority_queue<int> q[1005];
int  pian(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&xx);
			q[i].push(xx);
		}
		qq.push(make_pair(-q[i].top(),i));
        q[i].pop();
	}
	for(int i=1;i<=kk;i++){
			ans=ans-qq.top().first;
			x=qq.top();qq.pop();
            if(!q[x.second].empty()){
                    qq.push(make_pair(-q[x.second].top(),i));
                    q[x.second].pop();
            }
    }
    printf("%lld",ans);
}

int main(){
	scanf("%d%d%d",&n,&m,&kk);
    if(kk>1000) return pian(),0;
    for(int i=1;i<=kk;i++) f[i]=1000000000000000;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) scanf("%d",&a[j]);
            sort(a+1,a+m+1);
            sum=0;
            for(int k=kk;k>=1;sum=0,k--)
            for(int j=1;j<=m;j++){
                    sum+=a[m-j+1];
                            f[k]=min(f[k],f[k-j]+sum);
            }
            //        for(int k=1;k<=kk;k++)
            //                printf("%lld ",f[k]);
            //        printf("\n");
    }
    printf("%lld",f[kk]);
}
