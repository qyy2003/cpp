#pragma GCC optimize(3,"Ofast",2,"inline")
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n,maxa,anss,yy,li,tops,top,ss[1000005],s[1000005],b[1000005];
long long ans,fi[1000005];
int dfs(int x,int y,int z,int kk){
    if(kk)anss+=((kk&1)?-1:1)*(y/z);
    for(int i=x+1;i<=tops;i++) dfs(i,y,z*ss[i],kk+1);
    //dfs(x+1,y,z,kk);
}
int ask(int x,int y){
    tops=0;li=sqrt(y);yy=y;
    for(int i=1;i<=top;i++){
        if(s[i]>li) break;
        if(yy%s[i]==0)
        {
            ss[++tops]=s[i];
            while(!(yy%s[i])) yy/=s[i];
        }
    }
    if(yy>1) ss[++tops]=yy;
    anss=x;
    dfs(0,x,1,0);
    return anss;
}

int main(){
    scanf("%d",&n);
    if(n==1) return printf("4"),0;
    ans=0;
    fi[1]=1;
    for(int i=2;i<n;i++){
        if(!b[i]){ s[++top]=i; fi[i]=i-1;}
        for(int j=1;j<=top;j++){
            if(i*s[j]>n) break;
            b[i*s[j]]=1;
            if(i%s[j]==0){fi[i*s[j]]=fi[i]*(fi[s[j]]+1);break;}
            fi[i*s[j]]=fi[i]*fi[s[j]];
        }
    }
    fi[1]=0;
    double xx=n;
    xx=xx/sqrt(2.0);
    for(int i=1;i<=int(xx);i++)
        ans+=fi[i];
    for(int i=int(xx)+1;i<n;i++){
        maxa=sqrt(1ll*n*n-1ll*i*i);
        ans+=ask(maxa,i);
        //printf("%d %lld\n",i,ans);
    }
    printf("%lld",(ans+1)*8);
}
