#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
long long u,v,n,m,q,T,a[200005],x,y,t,flag;
queue<long long> q3;
queue<pair<long long,long long > >q2;
queue<pair<long long,long long > >q1;
int get(long long &x){
    x=(q1.empty())?0:q1.front().first+q*(t-q1.front().second); flag=1;
    if((!q2.empty())&&x<q2.front().first+q*(t-q2.front().second)) x=q2.front().first+q*(t-q2.front().second),flag=2;
    if((!q3.empty())&&x<q3.front()+q*t) x=q3.front()+q*t,flag=3;
    //printf("!%lld %lld|",flag,q3.front());
    if(flag==1) q1.pop();
    if(flag==2) q2.pop();
    if(flag==3) q3.pop();
}

int main(){
    scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&q,&u,&v,&T);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--) q3.push(a[i]);
    for(t=1;t<=m;t++){
	get(x);
	x-=q;
	if(t%T==0) printf("%lld ",x);
	y=u*x/v;
	x=x-y;
	q1.push(make_pair(x,t));
	q2.push(make_pair(y,t));
    }
    printf("\n");
    for(int i=1;i<=n+m;i++){
	get(x);
	if(i%T==0) printf("%lld ",x-q);
    }
    printf("\n");
}


