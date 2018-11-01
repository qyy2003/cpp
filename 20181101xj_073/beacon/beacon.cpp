#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
int f[1000][1000],ans,flag,flagg,sum,n,x,y,ii;
vector<int> go[1000];
int dfs(int x,int father,int fr){
    f[fr][x]=f[fr][father]+1;
    for(int i=0;i<go[x].size();i++)
	if(go[x][i]!=father)
	    dfs(go[x][i],x,fr);
}
int main(){
    freopen("beacon.in","r",stdin);
    freopen("beacon.out","w",stdout);
    scanf("%d",&n); ans=n;
    for(int i=1;i<n;i++){
	scanf("%d%d",&x,&y);
	go[x].push_back(y);
	go[y].push_back(x);
    }
    for(int i=1;i<=n;i++) dfs(i,i,i);
    //for(int i=1;i<=n;i++,printf("\n"))
	//for(int j=1;j<=n;j++)
	  //  printf("%d ",f[i][j]);
    for(int i=1;i<(1ll<<n);i++){
	flagg=1;
	for(int j=1;j<=n;j++)
	    if(flagg)
	    for(int k=1;k<=n;k++)
		if(j!=k){
		    flag=1;
		    for(int z=0;z<n;z++)
			if((1ll<<z)&i)
			    if(f[j][z+1]!=f[k][z+1]){
				flag=0;
				break;
			    }
		    if(flag) {
			flagg=0;
			break;
		    }
		}
	if(flagg) {
	    sum=0;
	    ii=i;
	    while(ii){
		ii-=ii&(-ii);
		sum++;
	    }
	    ans=min(ans,sum);
	}
    }
    printf("%d",ans);
}
		

