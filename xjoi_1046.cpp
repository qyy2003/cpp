#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n,x,ans;
priority_queue<int> q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d",&x);
	q.push(-x);
    }
    for(int i=1;i<n;i++){
	x=-q.top();
	q.pop();
	x-=q.top();
	q.pop();
	ans+=x;
	q.push(-x);
    }
    printf("%d",ans);
}


