#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,sum1[1000][1000],sum2[1000][100],flag;
char s[1000][1000];
int main(){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
                scanf("%s",s[i]);
                for(int k=1;k<=m;k++)
                if(s[i][k-1]=='#'){
                for(int j=1;j<=m;j++)
                        sum1[i][j]++;
                for(int j=1;j<=n;j++)
                        sum2[j][k]++;
                }
        }
        for(int i=1;i<=n;i++){
                flag=0;
                for(int j=1;j<=m;j++)
                        if(sum1[i][j]&&sum2[i][j])
                                printf("%c",s[i][j-1]),flag=1;
                if(flag) printf("\n");
        }
}


