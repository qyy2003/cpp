#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXA=10000;
long long n,m,li,a[MAXA],b[MAXA],suma[MAXA],sumb[MAXA],lena[MAXA],lenb[MAXA],ans;
int main(){
scanf("%lld%lld",&n,&m);
for(int i=1;i<=n;i++) scanf("%lld",&a[i]),suma[i]=suma[i-1]+a[i];
for(int i=1;i<=m;i++) scanf("%lld",&b[i]),sumb[i]=sumb[i-1]+b[i];
scanf("%lld",&li);
memset(lena,0x7f,sizeof(lena));
memset(lenb,0x7f,sizeof(lenb));
for(int i=1;i<=n;i++)
  for(int j=i;j<=n;j++)
    lena[j-i+1]=min(lena[j-i+1],suma[j]-suma[i-1]);
for(int i=1;i<=m;i++)
  for(int j=i;j<=m;j++)
    lenb[j-i+1]=min(lenb[j-i+1],sumb[j]-sumb[i-1]);
for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
	if(1ll*lena[i]*lenb[j]<=li)
		ans=max(ans,1ll*i*j);
printf("%lld",ans);
}
