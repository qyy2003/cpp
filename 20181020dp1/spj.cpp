#include<cstdio>
#include<cstring>
using namespace std;
struct rec{
    int x;int y;int step;
}q[1000000];
int n,k;char ch; int ans=999999,h,t;
int map[100][100]; 
char s[10000];
bool b[1000][1000];
inline void push(int x,int y,int st){
    if (x==n&&y==k){
	if (st<ans){
	    ans=st;
	}
	return;
    }
    if (st>ans) return;
    if (x<=0||y<=0||x>n||y>k) return;
    if (map[x][y]>0) return;
    if (b[x][y]) return;
    b[x][y]=true;
    q[++t].x=x; q[t].y=y;q[t].step=st;
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;++i){
	getchar();
	for (int j=1;j<=k;++j){
	    ch=getchar();
	    if (ch=='.') map[i][j]=0; else map[i][j]=1;
	}
    }
    q[++t].x=1; q[t].y=1;b[1][1]=true;
    while (h<t){
	int nowx=q[++h].x,nowy=q[h].y,nows=q[h].step;
	push(nowx+1,nowy,nows+1); push(nowx-1,nowy,nows+1); push(nowx,nowy-1,nows+1); push(nowx,nowy+1,nows+1);
    }printf("%d",ans);
}
