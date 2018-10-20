#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int n,top;
double x,y,ans;
pair<double,double> s[10000];
vector<pair<double,double>  >q;
double cross(double x1,double y1,double x2,double y2,double x3,double y3){
    return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%lf%lf",&x,&y);
	q.push_back(make_pair(x,y));
    }
    sort(q.begin(),q.end());
    for(int i=0;i<n;i++){
	while(top>=2&&cross(s[top-1].first,s[top-1].second,s[top].first,s[top].second,q[i].first,q[i].second)<0.0) top--;
	s[++top]=q[i];
    }
    for(int i=3;i<=top;i++)
	ans+=cross(s[1].first,s[1].second,s[i-1].first,s[i-1].second,s[i].first,s[i].second);
   // printf("%lf",ans*0.5);
    top=0;
    for(int i=n-1;i>=0;i--){
	while(top>=2&&cross(s[top-1].first,s[top-1].second,s[top].first,s[top].second,q[i].first,q[i].second)<0.0) top--;
	s[++top]=q[i];
    }
   // for(int i=1;i<=top;i++) printf("%lf %lf\n",s[i].first,s[i].second);
    for(int i=3;i<=top;i++)
	ans+=cross(s[1].first,s[1].second,s[i-1].first,s[i-1].second,s[i].first,s[i].second);
    printf("%0.2lf",ans*0.5);
}

