#include<cstdio>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
int n,x00,y00,x,y,z,ans;
map<pair<int,int>,int>ma;
int main(){
    scanf("%d",&n);
    scanf("%d%d",&x00,&y00);
    for(int i=1;i<=n;i++){
	scanf("%d%d",&x,&y);
	x=x-x00;
	y=y-y00;
	//printf("%d %d\n",x,y);
	z=__gcd(x,y);
	x/=z;y/=z;
	if(y<0){
	    x=-x;y=-y;
	}
	if(ma[make_pair(x,y)]) continue;
	ma[make_pair(x,y)]=1;
	ans++;
    }
    printf("%d",ans);
}
