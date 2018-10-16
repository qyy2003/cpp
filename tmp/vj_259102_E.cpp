#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int cnt,top[1000],n,m,kk,x,y
int main(){
scanf("%d",&cnt);
while(cnt--){
memset(top,0,sizeof(top));
scanf("%d%d%d",&n,&m,&kk);
for(int i=1;i<=m;i++){
scanf("%d%d",&x,&y);
go[++top[x-1]]=y-1;
go[++top[y-1]]=x-1;
}
memset(f,0,sizeof(f));
for(int i=0;i<n;i++) f[1<<i][1]=1;
for(int i=1;i<(1<<n);i++)
  for(int j=0;j<n;j++)
	if((1<<j)&i){
		for(int k=2;k<=kk;k++)
			f[i][k]=(f[i][k]+f[i^(1<<j)][k-1])%P;
		for(int g=1;g<=top[j];g++)
		if((1<<go[g])&i)
		for(int k=1;k<=kk;k++)
			f[i][k]=(f[i][k]+f[i^(1<<j)][k])%P;
		}
printf("%lld",f[(1<<n)-1][kk]);
}
		
