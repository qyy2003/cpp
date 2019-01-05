#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<long long> v;
long long n,x;
int main(){
    scanf("%lld",&n);
    long long len=sqrt(n);
    for(long long i=len;i>=1;i--){
	if(n%i) continue;
	v.push_back(n*(n-i+2ll)/(i*2ll));
	x=n/i;
	if(x*x^n) v.push_back(n*(n-x+2ll)/(x*2ll));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) printf("%lld ",v[i]);
}

