#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,tt;
long long ans,p[100100],de[100100],t[100100],pos[100100],f[100100];
int cmp(int x,int y){
    return de[y]*t[x]<de[x]*t[y];
}
int main(){
    scanf("%d%d",&n,&tt);
    for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&de[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&t[i]);
    for(int i=1;i<=n;i++) pos[i]=i;
    sort(pos+1,pos+n+1,cmp);
    //return 0;
    for(int i=1;i<=n;i++)
	for(int j=tt;j>=t[pos[i]];j--)
		f[j]=max(f[j-t[pos[i]]]+p[pos[i]]-de[pos[i]]*j,f[j]);
    for(int i=1;i<=tt;i++) ans=max(ans,f[i]);
    printf("%lld",ans);
}

