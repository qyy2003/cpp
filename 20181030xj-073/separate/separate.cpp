#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int nn,mm,px[3000][3000],py[3000][3000],map[3000][3000],f[3000],sum[3000];
int num,fmin[10000],fmax[10000],ffmin[10000],ffmax[10000];
pair<int,pair<int,int> > a[9000000];
int read(int &x){
    char ch=getchar(); x=0;
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
}

int check(int n,int m){
    int flag1=1,flag2=1;
    for(int i=2;i<=n;i++)
	if(f[i]>f[i-1]) flag1=0;
	else if(f[i]<f[i-1]) flag2=0;
    //printf("!%d %d\n",flag1,flag2);
    return flag1|flag2;
}

int sw(int n,int m){
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	    swap(px[i][j],py[i][j]);
}

int insert(int x,int y){
    int flag=(f[x]==sum[x])?1:0;
    //printf("%d %d %d %d %d\n",x,y,f[x],sum[x],flag);
    f[x]=max(f[x],y);
    sum[x]++;
    if(f[x]==sum[x]&&(!flag)) num--;
    if(f[x]!=sum[x]&&flag) num++;
    return num==0;
}

int work(int n,int m){
    for(int i=1;i<=nn;i++)
	for(int j=1;j<=mm;j++)
	    a[(i-1)*mm+j]=make_pair(map[i][j],make_pair(px[i][j],py[i][j]));
    sort(a+1,a+n*m+1);
    memset(f,0,sizeof(f));
    memset(sum,0,sizeof(sum));
    int ans=a[n*m].first-a[1].first;num=0;
    for(int i=1;i<n*m;i++)
	if(insert(a[i].second.first,a[i].second.second))
	    if(check(n,m))
		ans=min(ans,max(a[i].first-a[1].first,a[n*m].first-a[i+1].first));
    return ans;
}

int fenm(int n){
    fmin[0]=ffmin[n+1]=1e9+7;
    for(int i=1;i<=n;i++) fmin[i]=min(fmin[i-1],map[1][i]),
			  fmax[i]=max(fmax[i-1],map[1][i]);
    for(int i=n;i>=1;i--) ffmin[i]=min(ffmin[i+1],map[1][i]),
			  ffmax[i]=max(ffmax[i+1],map[1][i]);
    int ans=1e9+7;
    for(int i=1;i<n;i++) ans=min(ans,max(fmax[i]-fmin[i],ffmax[i+1]-ffmin[i+1]));
    return ans;
}

int fenn(int n){
    fmin[0]=ffmin[n+1]=1e9+7;
    for(int i=1;i<=n;i++) fmin[i]=min(fmin[i-1],map[i][1]),
			  fmax[i]=max(fmax[i-1],map[i][1]);
    for(int i=n;i>=1;i--) ffmin[i]=min(ffmin[i+1],map[i][1]),
			  ffmax[i]=max(ffmax[i+1],map[i][1]);
    int ans=1e9+7;
    for(int i=1;i<n;i++) ans=min(ans,max(fmax[i]-fmin[i],ffmax[i+1]-ffmin[i+1]));
    return ans;
}

int main(){
    freopen("separate.in","r",stdin);
    freopen("separate.out","w",stdout);
    read(nn); read(mm);
    for(int i=1;i<=nn;i++)
	for(int j=1;j<=mm;j++)
	read(map[i][j]),px[i][j]=i,py[i][j]=j;
    if(mm==1) return printf("%d",fenn(nn)),0;
    if(nn==1) return printf("%d",fenm(mm)),0;
    int ans=work(nn,mm);
    sw(nn,mm);
    ans=min(ans,work(mm,nn));
    printf("%d",ans);
}
