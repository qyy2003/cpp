#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n,m;
map<pair<int,int>,bool> ma;
int main(){
    //scanf("%d",&n);
    m=1e6;
    for(int i=2;i<=1000;i++)
	for(int j=1;j<=m/i;j++)
	    ma[make_pair(i+j,i*j)]=1;
}
