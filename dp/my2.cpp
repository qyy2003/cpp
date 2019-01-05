#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,a[500000],f1[500000],f2[500000],lis[500000],sum[500000],fff[500000],c[500000],anss,x,y,top,ans,l,r,mid,nn,last,topp,ff[500000];
bool b[500000];
vector<pair<int,int> > s[500000];
vector<int> q;
int findup(int x){
    l=1;r=top;int anss=0;
    while(l<=r){
	mid=(l+r)>>1;
	if(x<=a[lis[mid]]) r=mid-1;
	else anss=mid,l=mid+1;
    }
    return anss;
}
int finddown(int x){
    l=1;r=top;int anss=0;
    while(l<=r){
	mid=(l+r)>>1;
	if(x>=a[lis[mid]]) r=mid-1;
	else anss=mid,l=mid+1;
    }
    return anss;
}
int cmp(int x,int y){return a[x]<a[y];}
int main(){
//    freopen("kite.in","r",stdin);
  //  freopen("kite.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){
	scanf("%d%d",&x,&y);c[i]=x;
	s[x].push_back(make_pair(i,y));
    }
//    a[0]=1e9;
    for(int i=1;i<=n;i++){
	nn=s[i].size();
	for(int j=0;j<nn;j++) f1[s[i][j].first]=findup(s[i][j].second);
	ans=findup(a[i]);
	if(ans==top) lis[++top]=i;
	lis[ans+1]=(a[lis[ans+1]]>a[i])?i:lis[ans+1];
	ff[i]=ans;
    }
    anss=top;
    top=0;a[0]=0;
    memset(lis,0,sizeof(lis));
    for(int i=n;i>=1;i--){
	nn=s[i].size();
	for(int j=0;j<nn;j++) f2[s[i][j].first]=finddown(s[i][j].second);
	ans=finddown(a[i]);
	if(ans==top) lis[++top]=i;
	lis[ans+1]=(a[lis[ans+1]]<a[i])?i:lis[ans+1];
	fff[i]=ans;
	if(fff[i]+ff[i]+1==anss) sum[ff[i]]++;
    }
    //for(int i=1;i<=m;i++) printf("%d %d\n",f1[i],f2[i]);
    for(int i=1;i<=m;i++) printf("%d\n",max(f1[i]+f2[i]+1,(fff[c[i]]+ff[c[i]]+1!=anss||sum[ff[c[i]]]>1)?top:top-1));
}
