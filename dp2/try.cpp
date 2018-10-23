#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,x,y,l,r,ans,top,a[100000],b[100000],pre[100000]mid;
int main()
{
scanf("%d",&n);
top=0;
for(int i=1;i<=n;i++) scanf("%d",&b[i]);
scanf("%d%d",&x,&y); b[x]=y;
for(int i=1;i<=n;i++)
{
x=b[i];
l=1;r=top;
ans=0;
while(l<=r){
mid=(l+r)>>1;
if(x>=b[a[mid]])
{ans=mid;l=mid+1;}
else
r=mid-1;
}
if(ans==top)
 top++;
a[ans+1]=i;

}
printf("%d",top);
}
