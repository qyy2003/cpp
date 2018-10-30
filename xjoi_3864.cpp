#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,cx[100],cy[100],vx[100],vy[100];
double ans,rest,x;
vector<pair<double,int> > q;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&cx[i]);
    for(int i=1;i<=n;i++) scanf("%d",&cy[i]);
    for(int i=1;i<=m;i++) scanf("%d",&vx[i]);
    for(int i=1;i<=m;i++) scanf("%d",&vy[i]);
    for(int i=1;i<=m;i++){
	q.clear();
	for(int j=1;j<=n;j++) q.push_back(make_pair(1ll*(vx[i]-cx[j])*(vx[i]-cx[j])+1ll*(vy[i]-cy[j])*(vy[i]-cy[j]),1));
	for(int j=1;j<=m;j++) q.push_back(make_pair(1ll*(vx[i]-vx[j])*(vx[i]-vx[j])+1ll*(vy[i]-vy[j])*(vy[i]-vy[j]),0));
	sort(q.begin(),q.end());
	for(int i=1;i<q.size();i++){
	    x=1.0/(double)(i)/(double)(i+1);
	    ans+=sqrt(q[i].first)*((q[i].second)?(double)1.0/(double)(i):x);
	    if(q[i].second) break;
	}
    }
    printf("%.9lf",ans);
}
