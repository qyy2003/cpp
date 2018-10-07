#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXA=30005;
int n,f[MAXA],size[MAXA],s[MAXA],x,y,yy,xx,xx1,yy1;
char ss[100];
int find(int x,int &y)
{
    if(x==f[x])
    {
        y=0;
        return x;
    }
    f[x]=find(f[x],y);
    y+=s[x]; 
    s[x]=y;
    return f[x];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=30000;i++)
        f[i]=i,s[i]=0,size[i]=1;;
    for(int i=1;i<=n;i++)
    {
        scanf("%s%d%d",ss,&xx,&yy);
        xx1=0;yy1=0;
        x=find(xx,xx1);
        y=find(yy,yy1);
      //  printf("%d %d\n",x,y);
        if(ss[0]=='C')
        {
            if(x==y)
            printf("%d\n",max(0,abs(xx1-yy1)-1));
            else
                printf("-1\n");
        }
        else
        {
            f[x]=y;
            s[x]=size[y];
            size[y]+=size[x];
        }
    }
}



