#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXA=2*1e5+1000;
int n,m,d,ans,b[MAXA];
priority_queue<pair<int,int> > q;
pair<int,int> x,a[MAXA];
int main(){
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=n;i++) scanf("%d",&a[i].first),a[i].second=i;
    sort(a+1,a+n+1);
    ans=0;
    q.push(make_pair(-2000000000,0));
    for(int i=1;i<=n;i++){
        x=q.top();
        if(x.first+a[i].first>d){
            q.pop();
            q.push(make_pair(-a[i].first,x.second));
            b[i]=x.second;
            continue;
        }
        b[i]=++ans;
        q.push(make_pair(-a[i].first,ans));
    }
    for(int i=1;i<=n;i++)
        a[i].first=a[i].second,a[i].second=b[i];
    sort(a+1,a+n+1);
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i].second);
}
