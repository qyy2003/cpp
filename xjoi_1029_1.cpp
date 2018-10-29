#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
double a,b,c,d,f1[2505],f2[2505],ans,anss;
int main(){
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    f1[0]=1;
    for(int i=1;i<=a;i++) 
	for(int j=b*i;j>=0;j--){
	    f1[j]=0;
	    for(int k=1;k<=b;k++)
		if(j>=k)
		    f1[j]+=f1[j-k]/b;
	}
    f2[0]=1;
    for(int i=1;i<=c;i++) 
	for(int j=d*i;j>=0;j--){
	    f2[j]=0;
	    for(int k=1;k<=d;k++)
		if(j>=k)
		    f2[j]+=f2[j-k]/d;
	}
    for(int i=1;i<=a*b;i++)
	for(int j=1;j<i;j++){
	    ans+=f1[i]*f2[j]*i;
	    anss+=f1[i]*f2[j];
	}
    if(anss==0.0) printf("-1.0");
    else printf("%lf",ans/anss);
}
