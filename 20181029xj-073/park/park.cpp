#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int l,r,n,q,a[100000],li[100000],maxb,maxa,lii;
int read(int &x){
    char ch=getchar();x=0;
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
}
int main(){
    freopen("park.in","r",stdin);
    freopen("park.out","w",stdout);
    //scanf("%d%d",&n,&q);
    //for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    //for(int i=1;i<=n;i++) scanf("%d",&li[i]);
    read(n); read(q);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) read(li[i]);
    for(register int i=1;i<=q;i++){
//	scanf("%d%d%d",&l,&r,&lii);
	read(l); read(r); read(lii);
	maxb=maxa=lii;
	for(register int j=l;j<=r;j++){
	    maxb=(maxb>lii)?maxb:lii,
	    maxb+=a[j],
	    maxb=(maxb<li[j])?maxb:li[j],
	    maxa=(maxa>maxb)?maxa:maxb;
	}
	printf("%d\n",maxa);
    }
}
