#include<cstdio>
#include<algorithm>
using namespace std;
int x,y,z,maxa;
int main(){
    scanf("%d%d%d",&x,&y,&z);
	maxa=min(x+2,min(y+1,z));
    printf("%d",maxa*3-3);
}

