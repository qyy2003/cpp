#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,map[3000][3000],b[3000];
int dfs(int x){
    if(b[x]) return 0;
    b[x]=1;
    for(int i=1;i<=n;i++)
	if(map[x][i])
	    dfs(i);
}
int dfs2(int x){
    if(b[x]) return 0;
    b[x]=1;
    for(int i=1;i<=n;i++)
	if(map[i][x])
	    dfs2(i);
}
int ask(){
    for(int i=1;i<=n;i++){
	int ans=0;
	for(int j=1;j<=n;j++)
	    if(map[i][j])
		ans++;
	if(ans>=2) return 1;
    }
    return 0;
}
    
int  main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	    scanf("%d",&map[i][j]);
    dfs(1);
    for(int i=1;i<=n;i++)
	if(!b[i])
	    return printf("NO\n"),0;
    memset(b,0,sizeof(b));
    dfs2(1);
    for(int i=1;i<=n;i++)
	if(!b[i])
	    return printf("NO\n"),0;
    if(ask()) printf("YES\n");
    else printf("NO\n");
}

