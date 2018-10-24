#include<cstdio>
#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
const int MAXA=3*1e5+7;
int n,c[MAXA<<1],a[MAXA],b[MAXA],fa[MAXA],ans,suma;
vector<int> v[MAXA];
map<int,int> ma;
map<int,int>maa;
int find(int x) { return fa[x]=(fa[x]==x)?x:find(fa[x]);}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	c[i]=a[i];a[n+1]^=a[i];maa[a[i]]++;
    }
    maa[a[n+1]]++;
    for(int i=1;i<=n;i++){
	scanf("%d",&b[i]);
	maa[b[i]]--;if(maa[b[i]]<0) return printf("-1"),0;
	if(a[i]!=b[i]) ans++;
	c[n+i]=b[i];
	b[n+1]^=b[i];
    }
    maa[b[n+1]]--;
    if(maa[b[n+1]]<0) return printf("-1"),0;
    c[2*n+1]=a[n+1];n++; c[2*n]=b[n];
    sort(c+1,c+n+n+1);
    //printf("%d ",ans);
    for(int i=1;i<=2*n;i++)
	if(c[i]!=c[i-1])
	    ma[c[i]]=ma[c[i-1]]+1;
	else
	    ma[c[i]]=ma[c[i-1]];
   // for(int i=1;i<=n;i++) printf("%d %d| %d %d\n",a[i],ma[a[i]],b[i],ma[b[i]]);
    //fflush(stdout);
    for(int i=1;i<=n;i++) fa[ma[b[i]]]=ma[b[i]];
    //for(int i=0;i<=3;i++) printf("%d ",fa[i]);
    for(int i=1;i<n;i++){
	if(a[i]==b[i]) continue;
	fa[find(ma[a[i]])]=find(ma[b[i]]);
    }
    //for(int i=1;i<=n;i++) printf("%d ",fa[ma[b[i]]]);
    for(int i=1;i<=n;i++) if(fa[ma[b[i]]]==ma[b[i]]&&a[i]!=b[i]) ans++,fa[ma[b[i]]]++;
    //printf("%d",ans+1);
    //if(ans==0) return printf("0"),0;
    printf("%d",ans-1);
}   
