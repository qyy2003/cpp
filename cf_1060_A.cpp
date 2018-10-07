#include<cstdio>
#include<iostream>
using namespace std;
int n,ans;
char s[1000];
int main(){
scanf("%d",&n);
scanf("%s",s);
for(int i=0;i<n;i++){
if(s[i]=='8') ans++;
}
printf("%d",min(ans,n/11));
}
