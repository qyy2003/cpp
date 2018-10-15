#include<cstdio>
#include<algorithm>
using namespace std;
int n,cntb,cntw;
char s[1000];
int main(){
scanf("%d",&n);
for(int i=1;i<=n;i++){
scanf("%d",s);
if(s[0]=='0')
printf("%d %d\n",0,++cntb);
else
printf("%d %d\n",2,++cntw);
fflush(stdout);
}
printf("%d %d %d %d",1,0,1,2);
fflush(stdout);
}

