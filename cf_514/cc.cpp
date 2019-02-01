#include<cstdio>
#include<iostream>
using namespace std;
int n,m,x,y,len;
char ss[1000000];
int dfs(int x,int y){
    int yy=ss[x]-'a';
    if(!v[x][yy]){
	if(flag) return 0;
	flag=1;
	return dfs(x+1,0)||dfs(x+1,1)||dfs(x+1,2);
    }
    return dfs(v[x][yy]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
	scanf("%s",ss);
	len=strlen(ss);
	if(!b[len]){
	    b[len]=1;
	    s[len]=++tot;
	    e[len]=++tot;
	}
	x=s[len];
	for(int j=1;j<=len;j++){
	    y=ss[i]-'a';
	    if(!v[x][y]) v[x][y]=++tot;
	    vv[v[x][y]][y]=pre;
	    x=v[x][y];
	    pre=x;
	}
	vv[e[len]][y]=x;
    }
    for(int i=1;i<=m;i++){
	scanf("%s",ss);
	len=strlen(ss);
	if(!b[len]){
	    printf("NO\n");
	    continue;
	}
	x=e[len];
	for(int j=len;j>=1;j--){
	    x=vv[x][y];
	    if(
	for(int j=1;j<=len;j++){
	    y=ss[x]-'a';
	    if(!v[x][y]){
		flag=1;
		
	    }
	    x=v[x][y];
	}
