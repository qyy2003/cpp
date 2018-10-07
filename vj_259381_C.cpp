#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[1000000],ans,x,y;
int main(){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
                scanf("%d",&a[i]);
        }
        ans=1000000000;
        for(int i=1;i<=n-m+1;i++){
                x=a[i];
                y=a[i+m-1];
                if(x>0){
                        ans=min(ans,y);
                        continue;
                }
                if(y<0){
                        ans=min(ans,-x);
                        continue;
                }
                ans=min(ans,y-2*x);
                ans=min(ans,-x+2*y);
        }
        printf("%d",ans);
}
