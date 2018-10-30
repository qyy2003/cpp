#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,g[5000005],v[5];

int read(int &x){
    char ch=getchar(); x=0;
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
}

int check(int x){
    int ans=0;
    for(int i=1;i<=n;i++)
	if(x*3+3>=g[i])
	    ans+=(g[i]%3==0)?3:g[i]%3;
    return ans>=m;
}

int main(){
    freopen("zhanshajihua.in","r",stdin);
    freopen("zhanshajihua.out","w",stdout);
    //scanf("%d%d",&n,&m);
    read(n); read(m);
    for(int i=1;i<=n;i++) read(g[i]);
    int l=0,r=10000,mid,ans=-1;
    while(l<=r){
	mid=(l+r)>>1;
	if(check(mid)){
	    ans=mid;
	    r=mid-1;
	}
	else l=mid+1;
    }
    if(ans==-1) return printf("-1"),0;
    printf("%d ",ans);
    for(int i=1;i<=n;i++)
	if(ans*3+3>=g[i])
	    v[g[i]%3]++;
    int ans1=0,ans2=0;
    if(m<=v[2]*2) return printf("%d",ans+(m+1)/2),0; 
    m-=v[2]*2; ans2+=v[2];
    if(m<=v[1]) return printf("%d",ans+m+ans2),0;
    m-=v[1]; ans2+=v[1];
    if(m%3==0) return printf("%d",ans+m/3*4+ans2),0;
    if(!ans2) return printf("%d",ans+(m/3+1)*4),0;
    if(m%3==2) return printf("%d",ans+(m/3+1)*4+ans2-1),0;
    if(v[1]>1) return printf("%d",ans+(m/3+1)*4+ans2-2),0;
    return printf("%d",ans+(m/3+1)*4+ans2-1),0;
}

