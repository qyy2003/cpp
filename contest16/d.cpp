#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,nn,mm;
const int MAXA=1e7;
int f[MAXA<<1],posa,fll=0,wj,ans,an;
char s1[MAXA],s2[MAXA];
int work(int x,int y,int &z){
printf("%lld %lld %lld\n",x,y,z);
fflush(stdout);
    if(y%m==0&&x%n==posa&&z%m==0) fll++;
    if(fll==2) return x;
    if(s1[x%n]==s2[y%m]) z++,y++;
    return work(x+1,y,z);
}
main(){
    scanf("%lld%lld",&nn,&mm);
    scanf("%s",s1);
    scanf("%s",s2);
    n=strlen(s1); m=strlen(s2);
    for(posa=0;posa<n&&s1[posa]!=s2[0];posa++);
    nn*=n;
    wj=work(0,0,an)-posa;
    ans=((nn-posa-1)/wj);//+f[(nn-posa-1)%wj+posa];
    //for(int i=0;i<14;i++) printf("%lld ",f[i]);
    //printf("%lld %lld\n",f[wj-1],(nn-posa-1)%wj+posa);
    printf("%lld",ans/mm);
    return 0;
}
