#pragma GCC optimize(2,3,"inline","Ofast")
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int b[10000];
long long n,s,br=0ll;
int check(){
        long long sum=0;
        for(int i=1;i<=n;i++)
                sum+=i%b[i];
        if(sum==s){
                for(int i=1;i<=n;i++) printf("%d ",b[i]);
                return 0;
        }
        return 1;
}
int dfs(int x){
        br++;
        int flag=1;
        if(x==n+1) return check();
        if(n>10&&br>=10000000) return printf("nO 5oLuTi0N\n"),0;
        for(int i=1;i<=n&&flag;i++)
                if(!b[i]){
                        b[i]=x;
                        flag&=dfs(x+1);
                        b[i]=0;
                }
        return flag;
}
int main(){
        scanf("%lld%lld",&n,&s);
        if((n-1)*(n-2)/2<s) return printf("nO 5oLuTi0N\n"),0;
        if((n-1)*(n-2)/2==s){
                printf("0 ");
                for(int i=1;i<n;i++)
                        printf("%d ",i);
                return 0;
        }
        if(s==0ll){
                for(int i=1;i<n;i++) printf("%d",i);
                return 0;
        }
        if(n>s){
                printf("%lld ",s-1);
                for(int i=2;i<s-1;i++) printf("%d ",i);
                printf("%lld ",n);
                for(int i=s;i<n;i++) printf("%d ",i);
                printf("1 ");
                return 0;
        }
        if(dfs(1)) printf("nO 5oLuTi0N\n");
}

