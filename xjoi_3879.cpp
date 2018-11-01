#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
queue<int>q;
string s;
int n,x,top=0,flag,tot,sz,tops;
long long P=1e9+7,f[100],ans=0;
int bo[100],ru[100],b[100],deep[100],low[100],map[100][100],ed[100],ss[100],ma[100][100];
int read(int &x){
    x=0;
    while(top<s.length()&&(!isdigit(s[top]))) top++;
    while(top<s.length()&&(isdigit(s[top]))) x=(x<<1)+(x<<3)+s[top]-'0',top++;
    return x;
}

int tuopu(){
    while(!q.empty()) q.pop();
    memset(f,0,sizeof(f));
    for(int i=1;i<=sz;i++){
	for(int j=1;j<=sz;j++)
	    if(ma[j][i]&&i!=j)
		ru[i]++;
	if(!ru[i]) q.push(i);
    }
    f[ed[1]]=1;
    while(!q.empty()){
	flag=1;
	x=q.front(); q.pop();
	for(int i=1;i<=sz;i++){
	    if(ma[x][i]&&i!=x){
		f[i]+=f[x]*ma[x][i]%P;
		f[i]%=P;
		flag=0;
		ru[i]--;
		if(ru[i]==0) q.push(i);
	    }
	}
	if(flag) ans=(ans+f[x])%P;
    }
}


int check(int x){
    int ans=0;
    for(int i=1;i<=n;i++) ans+=map[x][i];
    if(ans>1){
	printf("-1");
	exit(0);
    }
}

int  tarjan(int x,int father){
    ss[++tops]=x;
    b[x]=1;
    deep[x]=++tot;
    low[x]=tot;
    for(int i=1;i<=n;i++){
	if(!map[x][i]) continue;
	if(!deep[i]){
	    tarjan(i,x);
	    low[x]=min(low[x],low[i]);
	}
	else if(b[i]) low[x]=min(low[x],low[i]);
    }
    if(low[x]==deep[x]){
	ed[x]=++sz;
	if(ss[tops]!=x||map[x][x]){
	    while(ss[tops]!=x) ed[ss[tops]]=sz,b[ss[tops]]=0,check(ss[tops]),tops--;
	    check(ss[tops]);
	}
	b[x]=0;
	tops--;
    }
}

int main(){
    getline(cin,s);
    top=0;
    read(n);
    for(int i=1;i<=n;i++){
	top=0;
	getline(cin,s);
	while(read(x))
	    map[i][x]++;
    }
    tarjan(1,0);
    for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	    if(ed[i]!=ed[j]&&map[i][j])
		ma[ed[i]][ed[j]]=(ma[ed[i]][ed[j]]+map[i][j])%P;
    tuopu();
    printf("%lld",ans);
}
