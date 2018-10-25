#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[300000],f1[300000],f2[300000],l,r,v,x,y,val;
char s[100];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
	for(x=i;x<=n;x+=x&(-x)) f1[x]=max(f1[x],a[i]);
	for(x=n-i+1;x>0;x-=x&(-x)) f2[x]=max(f2[x],a[i]);
    }
    for(int i=1;i<=m;i++){
	scanf("%s%d%d",s,&l,&r);
	if(s[0]=='Q'){
	    v=a[l];
	    for(x=l;x+(x&(-x))<=r;x+=x&(-x)) v=max(f2[n-x],v);
	    for(x=r;x-(x&(-x))>=l;x-=x&(-x)) v=max(f1[x],v);
	    v=max(v,a[x]);
	    printf("%d\n",v);
	}
	else{
	    for(int x=l;x<=n+1;x+=x&(-x)){
		if(r<f1[x]){
		    if(a[l]==f1[x]){
			val=r;
			for(int y=x-1;y>=x-(x&(-x))/2;y-=y&(-y))
			    val=max(val,f1[y]);
		    }
		    else
			break;
		}
		if(v==f1[x]) break;
		f1[x]=val;
	    }
	    for(int x=l;x>=0;x-=x&(-x)){
		if(r<f2[x]){
		    if(a[l]==f2[x]){
			val=r;
			for(int y=x+1;y<=x+(x&(-x))/2;y+=y&(-y))
			    val=max(val,f2[y]);
		    }
		    else break;
		}
		if(v==f2[x]) break;
		f2[x]=val;
	    }
	    a[l]=r;
	}
    }
}
