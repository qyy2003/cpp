#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,last,now,bb,aa,a[1000000],b[10000],num;
int main(){
    scanf("%d%d",&n,&m);
    last=1;num=m; bb=n; aa=0;
    for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	if(!b[a[i]]) num--;
	b[a[i]]++;
	while(b[a[last]]>1) b[a[last]]--,last++;
	if((!num)&&i-last<bb-aa){
	    bb=i; aa=last;
	}
    }
    printf("%d %d",aa,bb);
}


