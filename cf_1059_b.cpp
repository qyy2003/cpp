#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,sum[1005][1005],b[1005][1005];
char s[1005][1005];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
	    while(s[i][j]^'#'&&s[i][j]^'.') scanf("%c",&s[i][j]);
	    //printf("%c",s[i][j]);
	    if(s[i][j]=='#') sum[i][j]=sum[i][j-1]+1;
	    else sum[i][j]=sum[i][j-1];
	}
    for(int i=2;i<n;i++)
	for(int j=2;j<m;j++){
	    if(sum[i-1][j+1]-sum[i-1][j-2]!=3)continue;
	    if(s[i][j-1]=='.'||s[i][j+1]=='.') continue;
	    if(sum[i+1][j+1]-sum[i+1][j-2]!=3) continue;
	    b[i][j-1]++; b[i][j+1]++;b[i-1][j-1]++; b[i-1][j]++; b[i-1][j+1]++;
	    b[i+1][j-1]++; b[i+1][j]++; b[i+1][j+1]++;
	}
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	    if(s[i][j]=='#'&&!b[i][j])
		return printf("NO"),0;
    return printf("YES"),0;
}
