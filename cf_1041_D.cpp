#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,h,ans,anss,l,dis[200005];
pair<int,int> a[200005];
int main(){
    scanf("%d%d",&n,&h); h--;
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].first,&a[i].second);
    sort(a+1,a+n+1);
    a[0].second=a[1].first;
    l=1;
    for(int i=1;i<=n;i++){
        dis[i]=a[i].first-a[i-1].second;
        ans+=dis[i];
        while(ans>h) ans-=dis[++l];
        anss=max(anss,a[i].second-a[l].first+h-ans+1);
    }
    printf("%d",anss);
}


