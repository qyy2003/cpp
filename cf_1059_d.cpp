#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int x,y,n,flagf,flagz;
const double EPSs=1e-8;;
double a[100005],b[100005];
int check(double x){
    double maxa=-1e7,mina=1e15;
    for(int i=1;i<=n;i++){
	if(x*2.0*b[i]<b[i]*b[i]) return 0;
	maxa=max(maxa,a[i]-sqrt(x*2.0*b[i]-b[i]*b[i]));
	mina=min(mina,a[i]+sqrt(x*2.0*b[i]-b[i]*b[i]));
    }
    //printf("%lf %lf\n",maxa,mina);
    return maxa-mina<EPSs;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d%d",&x,&y);
	a[i]=x; b[i]=fabs(y);
	if(y<0) flagf=1;
	else flagz=1;
    }
    if(flagf==flagz) return printf("-1"),0;
    double l=0,r=1e15+1,half=0.5000,mid,ans,EPS=1e-8;
    //printf("!%lf !\n",mid);
    int t=500;
    while(t--){
	mid=(l+r)*half;
    //printf("!%lf %lf %lf !\n",l,r,mid);
	if(check(mid)){
	    ans=mid; r=mid;
	}
	else
	    l=mid;
    }
    printf("%lf",ans);
}
