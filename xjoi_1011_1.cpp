#pragma GCC optimize(2,3,"Ofast","inline")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXA=7100;
int n,top,x,y;
long long a[MAXA],f[MAXA],s[MAXA];
int first[MAXA],nxt[MAXA<<1],go[MAXA<<1],tot;
pair<int,int> ss[MAXA];
int add(int x,int y){
	nxt[++tot]=first[x]; first[x]=tot; go[tot]=y;
}
long long dfs(int x,int father){
	int l=top+1,now=l;
	for(int i=first[x];i;i=nxt[i])
		if(go[i]!=father)
			f[x]+=dfs(go[i],x);
	s[++top]=a[x];
	sort(s+l,s+top+1);
	//for(int i=l;i<=top;i++) printf("!%lld ",s[i]);
	//printf("\n");
	for(int i=l;;){
		if(s[i]==a[x]) break;
		now=i;
		while(s[now]==s[now+1]) now++;
		//	printf("%d %d %d %d %d\n",x,now,i,l,top);
		f[x]+=(now-i+1)*(i-l);
		i=now+1;
	}
	return f[x];
}

long long dfss(int x,int father,int deep){
	int l=top+1,now=l;
	for(int i=first[x];i;i=nxt[i])
		if(go[i]!=father)
			dfss(go[i],x,deep+1);
	ss[++top]=make_pair(deep,a[x]);
	sort(ss+l,ss+top+1);
	//for(int i=l;i<=top;i++) printf("!%lld ",s[i]);
	//printf("\n");
	for(int ll=l;ll<top;ll++){
		l=ll;
		while(ss[l].second==ss[l+1].second) l++;
		l++;
		if(l>top) break;
		for(int i=l;i<=top;i++)
			s[i]=ss[i].second;
		sort(s+l,s+top+1);
		for(int i=l;;){
			if(s[i]>=ss[ll].second||i>top) break;
			now=i;
			while(s[now]==s[now+1]&&now<top) now++;
				printf("%d %d %d %d %d\n",x,now,i,l,top);
			f[x]+=(now-i+1)*(i-l);
			i=now+1;
		}
	}
	return 0;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	top=0;
	if(n<=1000) dfss(1,0,0);
	else dfs(1,0);
	for(int i=1;i<=n;i++) printf("%lld ",f[i]);
}
