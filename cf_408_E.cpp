#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,x,y,z,top;
long long c[101000][200],b[101000],P=1e9+7,a[101000];
vector<pair<int,pair<int,int> > > q;
int main(){
    scanf("%d%d",&n,&m);
    c[0][0]=1;
    for(int i=1;i<=n+200;i++){
	c[i][0]=1;
	for(int j=1;j<=200;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%P;
    }
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++){
	scanf("%d%d%d",&x,&y,&z);
	q.push_back(make_pair(z,make_pair(y-x,y)));
    }
    sort(q.begin(),q.end());
    top=m-1;
    for(int i=100;i>=0;i--){
	while(top>=0&&q[top].first>=i) b[q[top].second.second-q[top].second.first]++,top--;
	for(int j=top+1;j<m;j++) 
	    b[q[j].second.second+1]-=c[q[j].second.first+q[j].first-i][q[j].first-i],
	    b[q[j].second.second+1]=(b[q[j].second.second+1]+P)%P;
	for(int i=2;i<=n;i++) b[i]+=b[i-1],b[i]%=P;
    }
    for(int i=1;i<=n;i++) printf("%lld ",(a[i]+b[i])%P);
}



/*
1 0 0 0 0 0 0 0 -1
1 1 1 1 1 1 1 1 0
1 2 3 4 5 6 7 8 -c[8][1]
1 3 6 1015212836-c[9][2]
*/
