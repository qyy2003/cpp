#include<cstdio>
#include<iostream>
#include<queue>
#define int long long
using namespace std;
int n,x,sum;
long long ans;
priority_queue<int>q1;
priority_queue<int>q2;
main()
{
    int cnt;
    scanf("%lld",&cnt);
    while(cnt--)
    {
    scanf("%lld",&n);
    ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        if(!q2.empty()&&-q2.top()<x) {
	if(!q1.empty()&&-q1.top()<-q2.top()) { ans+=q1.top(); q1.pop(); q2.push(-x);continue;}
	q1.push(q2.top()); 
	q2.pop(); q2.push(-x); continue;
	}
        if(!q1.empty()&&-q1.top()<x) {q2.push(-x); ans+=q1.top(); q1.pop();continue;}
        q1.push(-x);
       // printf("!1");
       // printf("%d %d %d\n",i,q1.top(),x);
    }
    sum=0;
    while(!q2.empty()){
        ans-=q2.top(); q2.pop(); sum++;
    }
    printf("%lld %lld\n",ans,sum*2);
    while(!q1.empty()) q1.pop();
    }
}
            
