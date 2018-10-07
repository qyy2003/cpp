#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXA=1e4+100;
long long cnt,n,m,kk,top,a[MAXA],b[MAXA],s[2*MAXA],ss[2*MAXA],len,l,r;
long long ans,st,x,num[2*MAXA],anss,sum,ansss;
int dfs(int x)
{
    if(b[x]) return 0;
    b[x]=1;
    s[++top]=a[x];
    sum+=a[x];
    dfs((x+kk)%(n));
}
int main()
{
    scanf("%lld",&cnt);
    for(int cn=1;cn<=cnt;cn++){
        printf("Case #%d: ",cn);
        ans=0;
        scanf("%lld%lld%lld%lld",&n,&st,&m,&kk);
    if(m==0) {
    printf("0\n");
        continue;
    }
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
        for(int i=0;i<n;i++)
            if(!b[i]){
               // printf("%d\n",i);
                anss=0;
                top=0;
                l=1;r=1;
                ss[1]=0;
                sum=0;
                dfs(i);
                if(sum>0)
                    anss+=sum*((m/top));
                ansss=0;
                len=m%top;
		if(len>0)
		{
		for(int j=1;j<top;j++)
                    s[top+j]=s[j];
                for(int j=1;j<top*2;j++)
                    num[j]=num[j-1]+s[j];
                for(int j=1;j<top*2;j++)
                {
                    while(l<=r&&ss[l]<j-len) l++;
            //printf("%lld %lld\n",num[j],num[ss[l]]);
                    x=num[j]-num[ss[l]];
                    ansss=max(ansss,x);
                    while(l<=r&&num[ss[r]]>=num[j])r--;
                    ss[++r]=j;
                }
                ans=max(ans,anss+ansss);
		}
		ansss=0;
        if(m>=top){
        if(sum>0)anss-=sum;
        len+=top;
        }
                for(int j=1;j<top*2;j++)
                {
                    while(l<=r&&ss[l]<j-len) l++;
            //printf("%lld %lld\n",num[j],num[ss[l]]);
                    x=num[j]-num[ss[l]];
                    ansss=max(ansss,x);
                    while(l<=r&&num[ss[r]]>=num[j])r--;
                    ss[++r]=j;
                }
                ans=max(ans,anss+ansss);
            }
        printf("%lld\n",max(0ll,st-ans));
    }
}
