#include<cstdio>
#include<iostream>
using namespace std;
int n,m,x,y,z,ans;
int main(){
    freopen("zujijihua.in","r",stdin);
    freopen("zujijihua.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
	scanf("%d%d%d",&x,&y,&z);
	ans+=z;
    }
    printf("%d",ans);
}
