#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
class jz{
    public:
    int n,map[20][20];
    jz(int _n=0):n(_n){memset(map,0,sizeof(map));}
    friend jz operator * (jz a,jz b){
	//return 0;
	jz ans(a.n);
	for(int i=1;i<=a.n;i++)
	    for(int j=1;j<=b.n;j++)
		for(int k=1;k<=a.n;k++)
		    if(a.map[i][k]*b.map[k][j])
			ans.map[i][j]=1;
	return ans;
    }
    void scan(){
	int x;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++){
		scanf("%d",&x);
		if(x) map[i][j]=1;
	    }
    }
    void print(){
	for(int i=1;i<=n;i++,printf("\n"))
	    for(int j=1;j<=n;j++)
		printf("%d ",map[i][j]);
    }
    void ans(){
	int ans=0;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
		if(!map[i][j])
		    ans=1;
	if(ans) printf("NO\n");
	else printf("YES\n");
    }
};

jz a;

int main()
{
    scanf("%d",&n);
    a.n=n;
    a.scan();
    long long m=1ll*n*n*n*n;
    while(m){
	m>>=1;
	a=a*a;
    }
//	a=a*a;
    for(int i=1;i<=n;i++){
    a.print();
    printf("\n");
    }
    a.ans();
}
