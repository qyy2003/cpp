#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,ans[1000000];
pair<int,int> a[1000000];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&x),a[i]=make_pair(x,i);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
	a[i].first=max(a[i-1].first+1,a[i].first);
	ans[a[i].second]=a[i].first;
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}
	

