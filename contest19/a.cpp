#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,x,b[100],fl;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d",&x);
	if(x==5||x==7) return printf("-1"),0;
	b[x]++;
    }
    if(b[4]>b[2]||b[4]>b[1]) return printf("-1"),0;
    fl=b[4]; b[2]-=b[4]; b[1]-=b[4];
    if(b[6]-b[2]-b[3]||b[6]-b[1]) return printf("-1"),0;
    for(int i=1;i<=fl;i++) printf("1 2 4\n");
    for(int i=1;i<=b[2];i++) printf("1 2 6\n");
    for(int i=1;i<=b[3];i++) printf("1 3 6\n");
}
