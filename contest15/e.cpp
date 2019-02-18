#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,top,topp;
long double a[500][500],ans[500],DIV=2,EPS=1e-6,sx[10000],sy[10000],tx[10000],ty[10000],st,k,an,xx,zero=0;
void clear(){
    top=0;
    sx[++top]=0;
    sy[top]=0;
    sx[++top]=1;
    sy[top]=0;
}
long double abss(long double x){
    return (x<zero)?-x:x;
}
long double work(long double y1,long double y2,long double s1,long double s2,long double x1,long double x2){
    //printf("%lf %lf %lf %lf %lf %lf\n",y1,y2,s1,s2,x1,x2);
    if(y1>s1-1e-18&&y2>s2-1e-18){
	tx[++topp]=x1;
	ty[topp]=y1;
	return 0;
    }
    if(y1<s1-1e-18&&y2<s2-1e-18){
	tx[++topp]=x1;
	ty[topp]=s1;
	return ((s1-y1)+(s2-y2))*(x2-x1)/DIV;
    }
    if(s1>y1){
	st=(s1-y1)*(x2-x1)/(s1-y1+y2-s2);
	//printf("^%lf^",st);
	tx[++topp]=x1;
	ty[topp]=s1;
	tx[++topp]=x1+st;
	ty[topp]=s1+st*k;
	return st*(s1-y1)/DIV;
    }
    st=(y1-s1)*(x2-x1)/(y1-s1+s2-y2);
    tx[++topp]=x1;
    ty[topp]=y1;
    tx[++topp]=x1+st;
    ty[topp]=s1+st*k;
    return (x2-x1-st)*(s2-y2)/DIV;
}

long double ask(long double x,long double y){
    k=y-x;an=0;topp=0;
    for(int i=1;i<top;i++){
	//for(int ii=1;ii<=top;ii++) printf("#%lf %lf\n",sx[ii],sy[ii]);
	an+=work(sy[i],sy[i+1],k*sx[i]+x,k*sx[i+1]+x,sx[i],sx[i+1]);
	//printf("$%lf \n",an);
	//for(int ii=1;ii<=topp;ii++) printf("##%lf %lf\n",tx[ii],ty[ii]);
    }
    tx[++topp]=1;
    ty[topp]=max(y,sy[top]);
    top=0;
    for(int i=1;i<=topp;i++){
	  //if(top>2&&abss((ty[i]-sy[top])*(sx[top]-sx[top-1])-(sy[top]-sy[top-1])*(tx[i]-sx[top]))<EPS) top--; 
	  sx[++top]=tx[i];
	  sy[top]=ty[i];
	}
    return an;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
	for(int j=0;j<=m;j++)
	    scanf("%Lf",&a[i][j]);
    for(int i=1;i<=m;i++){
	clear();
	for(int j=1;j<=n;j++)
	    ans[j]+=ask(a[j][i-1],a[j][i]);
    }
    for(int i=1;i<=n;i++) printf("%Lf\n",ans[i]);
}
