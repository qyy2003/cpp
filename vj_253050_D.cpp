#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXA=1e5+100;
int cnt,n,m,f[MAXA],g[MAXA],ans;
struct node{
    int x,y,z,zz;
}a[MAXA];
int mysort1(node x,node y){
    if(x.y<y.y) return 1;
    return 0;
}
int mysort2(node x,node y){
    if(x.x<y.x) return 1;
    return 0;
}
int lowbit(int x){
    return x&(-x);
}
int main()
{
    scanf("%d",&cnt);
    while(cnt--)
    {
        memset(g,0,sizeof(g));
        ans=0;
        m=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        sort(a+1,a+n+1,mysort1);
        //for(int i=1;i<=n;i++)
        //    printf("%d %d\n",a[i].x,a[i].y);
        for(int i=1;i<=n;a[i].zz=m,i++)
            if(a[i].y!=a[i-1].y)
                m++;
        sort(a+1,a+n+1,mysort2);
        //for(int i=1;i<=n;i++)
        //    printf("%d %d\n",a[i].x,a[i].zz);
        int z,zz,maxa,last=0;
        a[n+1].x=-1;
        for(int i=1;i<=n;i++)
        {
            z=a[i].zz-1;
            maxa=0;
            while(z){
                maxa=max(maxa,g[z]);
                z-=lowbit(z);
            }
            f[i]=maxa+a[i].z;
            ans=max(f[i],ans);
            if(a[i].x!=a[i+1].x){
                for(int j=last+1;j<=i;j++){
                    z=a[j].zz;
                    while(z<=n){
                        g[z]=max(f[j],g[z]);
                        z+=lowbit(z);
                    }
                }
                    last=i;

            }
        }
        printf("%d\n",ans);
    }
}


