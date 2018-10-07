#include<cstdio>
#include<iostream>
using namespace std;
int n;
long long ans,inv[100005];
const long long P=1e9+7;
int main()
{
    scanf("%d",&n);
    ans=1;
    inv[1]=1;
    for(int i=2;i<=n;i++)
        ans*=2*n-i,ans%=P,inv[i]=(P-P/i)*inv[P%i]%P,ans*=inv[i],ans%=P; 
    ans*=2*n-1;
    ans%=P;
    printf("%lld",(2*ans-n)%P);
}
//把每个阶梯前后作为盒子，球1-n标号，依次放入盒中，盒子里最小的就是该盒至下一个有球的盒子中间阶梯的数量，盒1放在第0个盒子里，就有在n+1个盒子里放n-1个球，即c[n+1+n-1-1][n+1-1];
