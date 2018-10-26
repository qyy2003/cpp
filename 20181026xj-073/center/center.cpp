#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n,m,qo,ans,x,y,cnt,l,r,b[2005],go[2005][10005],topgo[2005];
pair<int,int> qq[2000005],xx,q[10000005];
//queue<pair<int,int> >q;
void read(int &x){
    char ch=getchar();x=0;
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
}
int main(){
    freopen("center16.in","r",stdin);
    freopen("center.out","w",stdout);
    //scanf("%d%d%d",&n,&m,&qo);
    read(n); read(m); read(qo);
    for(register int i=1;i<=m;i++){
	//scanf("%d%d",&x,&y);
	read(x); read(y);
	go[x][++topgo[x]]=y;
	go[y][++topgo[y]]=x;
    }
    while(qo--){
	memset(b,0,sizeof(b)); ans=0;l=1;r=0;
	//scanf("%d",&cnt);
	read(cnt);
	for(register int i=1;i<=cnt;i++){
	    //scanf("%d%d",&x,&y);
	    read(x);read(y);
	    qq[i]=(make_pair(-y,x));
	}
	sort(qq+1,qq+cnt+1);
	int top=1;
	while(l<=r||top<=cnt){
	    if(l>r||(top<=cnt&&q[l].first<-qq[top].first)){
		xx=make_pair(-qq[top].first,qq[top].second);
		top++;
	    }
	    else{
		xx=q[l];
		l++;
	    }
	    if(b[xx.second]) continue;
	    ans++;
	    b[xx.second]=1;
	    if(!xx.first) continue;
	    for(register int i=1;i<=topgo[xx.second];i++)
		if(!b[go[xx.second][i]])
		    q[++r]=make_pair(xx.first-1,go[xx.second][i]);
	}
	printf("%d\n",ans);
    }
}

