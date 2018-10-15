#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int l,xx,yy,n,top,f[10000],x[10000],y[10000];
pair<double,pair<int,int> >a[5000000]; 

int add(int x,int y,double z){
	a[++top]=make_pair(z,make_pair(x,y));
}

int find(int x){
	return (f[x]==x)?x:f[x]=find(f[x]);
}

int main(){
	freopen("AC.in","r",stdin);
	freopen("AC.out","w",stdout);
	scanf("%d%d%d",&xx,&yy,&n);
	f[0]=0;f[n+1]=n+1;
	for(int i=1;i<=n;i++){
		f[i]=i;
		scanf("%d%d",&x[i],&y[i]);
		add(0,i,(double)min(x[i],yy-y[i]));
		add(n+1,i,(double)min(y[i],xx-x[i]));
		for(int j=1;j<=i-1;j++)
			add(i,j,sqrt(1ll*(x[j]-x[i])*(x[j]-x[i])+1ll*(y[j]-y[i])*(y[j]-y[i])));
	}
	sort(a+1,a+top+1);l=0;
	while(find(0)!=find(n+1)){
		if(find(a[++l].second.second)!=find(a[l].second.first))
			f[find(a[l].second.second)]=find(a[l].second.first);
	}
	printf("%lf",a[l].first);
}
