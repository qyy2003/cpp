#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int cnt,cn,n,m,a[10005],f[10005],pre[10005],l,r;
pair<int,int> s[10005];
int cal(int k,int x,int y){
    return y-k*x;
}
int worse(int k,int xx1,int yy1,int xx2,int yy2){
    if(cal(k,xx1,yy1)>=cal(k,xx2,yy2)) return 1;
    return 0;
}
int cross(int xx1,int yy1,int xx2,int yy2,int xx3,int yy3){
    return (xx2-xx1)*(yy3-yy1)-(xx3-xx1)*(yy2-yy1);
}
int main()
{
    scanf("%d",&cnt);
    for(int cn=1;cn<=cnt;cn++)
    {
        printf("Case %d: ",cn);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        f[i]=(a[i]-a[1])*(a[i]-a[1]);
        if(n<=m) return printf("0\n"),0;
           // for(int i=1;i<=n;printf("%d ",f[i]),i++);
        for(int j=2;j<=m;j++)
        {
            l=0;r=0;
            s[l]=make_pair(2*a[j],a[j]*a[j]);
            s[++r]=make_pair(2*a[j+1],f[j]+a[j+1]*a[j+1]);
            for(int i=j+1;i<=n;i++)
            {
            //printf("$%d %d %d %d\n",a[i],s[l].first,s[l].second,f[i]);
            while(l<r&&worse(a[i],s[l].first,s[l].second,s[l+1].first,s[l+1].second)) l++;
            while(l<r&&cross(s[r-1].first,s[r-1].second,2*a[i+1],f[i]+a[i+1]*a[i+1],s[r].first,s[r].second)>=0) r--;
            s[++r]=make_pair(2*a[i+1],f[i]+a[i+1]*a[i+1]);
            f[i]=cal(a[i],s[l].first,s[l].second)+a[i]*a[i];
            //printf("!%d %d %d %d\n",a[i],s[l].first,s[l].second,f[i]);
            }
            //for(int i=1;i<=n;printf("%d ",f[i]),i++);
        }
        printf("%d\n",f[n]);
    }
}
