#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXA=5*1e6;
int ans,l,r,x,s[MAXA],f[MAXA],b[MAXA],tot,n,m,rr,c,xx,yy,first[MAXA],nxt[MAXA<<2],go[MAXA<<2],val[MAXA<<2];

int add(int x,int y,int z){
	if(s[x]=='*'||s[y]=='*') return 0;
	nxt[++tot]=first[x];first[x]=tot; go[tot]=y; val[tot]=z;
}

int spfa(){
//	printf("%d %d!",l,r);
	while(l<r){
		x=s[++l];
		//printf("!%d %d\n",x/m,(x-1)%m+1);
		for(int i=first[x];i;i=nxt[i]){
		//printf("%d %d %d %d\n",go[i]/m,(go[i]-1)%m+1,f[go[i]],f[x]);
			if(f[go[i]]>f[x]+val[i]&&(!b[go[i]])) b[go[i]]=1,s[++r]=go[i];
			f[go[i]]=min(f[go[i]],f[x]+val[i]);
		}
		b[s[l]]=0;
	}
}

int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&rr,&c,&xx,&yy);
	for(int i=1;i<=n;i++){
		getchar();
		for(int j=1;j<=m;j++) s[i*m+j]=getchar();
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++) 
			add(i*m+j,i*m+j+1,1),add(i*m+j+1,i*m+j,0);
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++) 
			add(i*m+j,(i+1)*m+j,0),add((i+1)*m+j,i*m+j,0);
	l=r=0;s[++r]=rr*m+c;
	memset(f,0x7f,sizeof(f));
	f[rr*m+c]=0;
	spfa();
	//for(int i=1;i<=n;i++,printf("\n"))
	//	for(int j=1;j<=m;j++)
	//		printf("%d ",f[i*m+j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(f[i*m+j]<=yy&&(f[i*m+j]-(j-c))<=xx)
				ans++;
	printf("%d",ans);
}
