#include<bits/stdc++.h>
using namespace std;
int k,n,m;
int a[1000][1000];
int main(){
    scanf("%d",&k);
    if (k<=49){
        printf("%d %d\n",1,k+1);
        for (int i=1;i<=k+1;++i) printf(".");
        return 0;
    } else 
    if (k<=98){
        m=50;
        n=k-50+2;
        printf("%d %d\n",n,m);
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                printf(".");
            }
            printf("\n");
        }
        return 0;
    }
    ++k;
    m=50;n=(k&1)?44:45;
    for (int i=1;i<=m;++i)a[1][i]=1;
    k-=m+n-1;int last=m,cur=-1;
    for (int i=2;i<=n;++i){
        a[i][last]=1;
        if (i&1){
            for (int j=1;j<=min(k/2,49);++j){last+=cur; a[i][last]=1;}
            if (cur==1) k-=(k>=98)?98:k;
            cur*=-1;
        }
    }
    printf("%d %d",n,m);
    for (int i=1;i<=n;++i){
        printf("\n");
        for (int j=1;j<=m;++j) if (a[i][j]) printf("."); else printf("#");
    }
}
