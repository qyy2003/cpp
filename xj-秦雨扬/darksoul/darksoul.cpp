#include<iostream>
#include<map>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<pair<int,int> > q;
int f[10000],nxt[10000],first[10000],go[10000],val[10000],tot;
bool b[2000000];
int n,x,y,z;
map<pair<int,int>,int > ma;

int add(int x,int y,int z){
	nxt[++tot]=first[x];first[x]=tot;go[tot]=y; val[tot]=z;
}


int read(int &x){
	x=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
}

int dij(int st){
	memset(f,0x7f,sizeof(f));
	f[st]=0;q.push(make_pair(0,st));
	pair<int,int> x;
	while(!q.empty()){
		x=q.top();q.pop();
		for(int i=first[x.second];i;i=nxt[i]){
			if(f[x.second]+val[i]<f[go[i]]){
				f[go[i]]=f[x.second]+val[i];
				q.push(make_pair(-f[go[i]],go[i]));
			}
		}
	}
}

int dfs(int x){
	for(int i=first[x];i;i=nxt[i])
		if(!b[go[i]]){
			f[go[i]]=f[x]+val[i];
			b[go[i]]=1;
			dfs(go[i]);
		}
}


int main(){
	freopen("darksoul.in","r",stdin);
	freopen("darksoul.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(x); read(y); read(z);
		if(ma[make_pair(x,y)]&&val[ma[make_pair(x,y)]]>z){
			val[ma[make_pair(x,y)]]=z;
			val[ma[make_pair(y,x)]]=z;
		}
		add(x,y,z);
		add(y,x,z);
		ma[make_pair(x,y)]=tot-1;
		ma[make_pair(y,x)]=tot;
	}
	int ans=0;
	if(n>10000)
	{
		dfs(1);
		b[1]=1;
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
			if(f[i]>f[ans]) ans=i;
		f[ans]=0;b[ans]=1;
		dfs(ans);ans=0;
		for(int i=1;i<=n;i++)
			if(f[i]>ans) ans=f[i];
		return printf("%d",ans+1),0;
	}
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=1;j<=n;j++) ans=max(ans,f[j]);
	}
	printf("%d",ans+1);
}
