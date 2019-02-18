#include<cstdio>
#include<iostream>
using namespace std;
int n,m,flag,fl,bx[2000][2000],by[2000][2000];
char map[2000][2000];
int dfs(int x,int y){
    if(flag) return 0;
    if(bx[x%n][y%m]==x&&by[x%n][y%m]==y) return 0;
    if(map[x%n][y%m]=='#') return 0;
    //printf("%d %d %d %d\n",x,y,bx[x%n][y%m],bx[x%n][y%m]);
    if((bx[x%n][y%m]||by[x%n][y%m])&&(!((bx[x%n][y%m]==x)&&(by[x%n][y%m]==y)))) flag=1;
    bx[x%n][y%m]=x;
    by[x%n][y%m]=y;
    //printf("#%d %d %d %d\n",x,y,bx[x%n][y%m],bx[x%n][y%m]);
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",map[i]);
    for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	    if(map[i][j]=='S'){
		dfs(i+n*500,j+m*500);
		}
			    /*
	    for(int ii=0;ii<3;ii++)
		for(int jj=0;jj<3;jj++,printf("\n"))
    for(int i=1;i<=n;i++,printf("\n"))
	for(int j=1;j<=m;j++)
	    printf("%d",b[ii][jj][i][j]);
    for(int i=1;i<=n;i++)
	if(b[i][1]&&b[i][m])
	    return printf("Yes"),0;
    for(int i=1;i<=m;i++)
	if(b[1][i]&&b[n][i])
	    return printf("Yes"),0;
    */
    if(flag) printf("Yes");
    else printf("No");
}
/*
6 14
....#..##.#...
##..#...#.#...
##..####.#.###
###.#.#..S#..#
########....##
.#.#..#.....#.
*/
