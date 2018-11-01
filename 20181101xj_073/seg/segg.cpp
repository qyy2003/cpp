#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const long long MAXA=2e5,P=998244353;
long long a[MAXA],tr[MAXA<<2],tror[MAXA<<2],pf[MAXA<<2],kk,an[MAXA<<2],xx,yy;
int m,n,opt,l,r,k;
int build(int x,int l,int r){
    if(l==r){
	tr[x]=a[l];
	pf[x]=a[l]*a[l]%P;
	an[x]=a[l]*a[l]*4%P;
	tror[x]=a[l];
	return 0;
    }
    build(x<<1,l,(l+r)>>1);
    build(x<<1|1,((l+r)>>1)+1,r);
    tr[x]=tr[x<<1]+tr[x<<1|1];
    pf[x]=(pf[x<<1]+pf[x<<1|1])%P;
    tror[x]=tror[x<<1]|tror[x<<1|1];
    an[x]=(((pf[x<<1]*(r-((r+l)>>1))%P+pf[x<<1|1]*(((l+r)>>1)-l+1)%P)*2%P+tr[x<<1]%P*tr[x<<1|1]%P*4%P)%P+(an[x<<1]+an[x<<1|1])%P)%P;
}

long long asksum(int x,int ql,int qr,int l,int r){
    if(l>qr||r<ql) return 0;
    if(ql<=l&&r<=qr) return tr[x];
    return asksum(x<<1,ql,qr,l,(l+r)>>1)+asksum(x<<1|1,ql,qr,((l+r)>>1)+1,r);
}

long long askpf(int x,int ql,int qr,int l,int r,long long &sumpf,long long &sumtr){
    //printf("%d %d %d %d %d!\n",x,ql,qr,l,r);
    if(ql<=l&&r<=qr) {
	sumpf=pf[x];
	sumtr=tr[x];
	return an[x];
    }
    int mid=(l+r)>>1;
    if(ql>mid)return askpf(x<<1|1,ql,qr,mid+1,r,sumpf,sumtr);
    if(qr<=mid) return askpf(x<<1,ql,qr,l,mid,sumpf,sumtr);
    long long ans,sumpf1,sumpf2,sumtr1,sumtr2;
    ans=askpf(x<<1,ql,qr,l,(l+r)>>1,sumpf1,sumtr1)+askpf(x<<1|1,ql,qr,((l+r)>>1)+1,r,sumpf2,sumtr2);
    sumpf=(sumpf1+sumpf2)%P; sumtr=(sumtr1+sumtr2)%P;
    return ((ans%P+(sumpf1*(min(qr,r)-((r+l)>>1))%P+sumpf2*(((l+r)>>1)-max(ql,l)+1)%P)%P*2%P)%P+sumtr1%P*sumtr2%P*4%P)%P;
}

long long change(int x,int ql,int qr,int l,int r,long long cha){
    if(!(tror[x]&(~cha))) return 0;
    if(l>qr||r<ql) return 0;
    if(l==r){
	tr[x]=tr[x]&cha;
	a[l]=a[l]&cha;
	pf[x]=a[l]*a[l]%P;
	an[x]=a[l]*a[l]*4%P;
	tror[x]=a[l];
	return 0;
    }
    change(x<<1,ql,qr,l,(l+r)>>1,cha);
    change(x<<1|1,ql,qr,((l+r)>>1)+1,r,cha);
    tr[x]=tr[x<<1]+tr[x<<1|1];
    pf[x]=(pf[x<<1]+pf[x<<1|1])%P;
    tror[x]=tror[x<<1]|tror[x<<1];
    an[x]=((pf[x<<1]*(r-((r+l)>>1))%P+pf[x<<1|1]*(((l+r)>>1)-l+1)%P)*2%P+tr[x<<1]*tr[x<<1|1]%P*4%P+an[x<<1]+an[x<<1|1])%P;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    //printf("%lld %lld %lld\n",tr[1],pf[1],an[1]);
    scanf("%d",&m);
    while(m--){
	scanf("%d%d%d",&opt,&l,&r);
	if(opt==1){
	    scanf("%lld",&kk);
	    change(1,l,r,1,n,kk);
	}
	if(opt==2) printf("%lld\n",asksum(1,l,r,1,n));
	if(opt==3) printf("%lld\n",askpf(1,l,r,1,n,xx,yy));
    }
}

