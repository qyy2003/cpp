#include<cstdio>
#include<iostream>
using namespace std;
int n,p,flag=0,an[100000];
char s[100000];
int main(){
    scanf("%d%d",&n,&p);
    scanf("%s",s+1);
    if(n<=p) return printf("No\n"),0;
    for(int i=1;i<=n;i++){
	if(s[i]=='.') an[i]=0;
	else an[i]=s[i]-'0';
    }
    for(int i=1;i<=n-p;i++){
	if(an[i]^an[i+p])
	    flag=1;
    }
    for(int i=1;i<=n;i++)
	if(flag==0&&s[i]=='.'){
	    if(i>p) an[i]=an[i-p]^1,flag=1;
	    if(i<=n-p) an[i]=an[i+p]^1,flag=1;
	}
    if(!flag) return printf("No\n"),0;
    for(int i=1;i<=n;i++) printf("%d",an[i]);
}


