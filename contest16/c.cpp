#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXA=1e6;
int n,m,ans,topp,a[MAXA],an;
main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
	scanf("%lld",&a[i]);
	if(an-(n-i)*a[i]*topp<m) printf("%lld\n",i);
	else{
	    an+=a[i]*topp;
	    topp++;
	}
    }
    return 0;
}
