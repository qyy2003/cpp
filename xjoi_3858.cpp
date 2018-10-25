#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char s1[1000],s2[1000];
int top,sum;
int main(){
    scanf("%s",s1); scanf("%s",s2);
    top=0;
    for(int i=0;i<strlen(s1);i++){
	if(top==strlen(s2)) break;
	if(s2[top]==')'&&s1[i]=='(') {
	    sum=1;
	    while(sum) sum+=(s1[i]=='(')?1:-1,i++;
	    i--;
	    top++;
	    continue;
	}
	else
	    if(s2[top]=='('&&s1[i]==')'){
		sum=1;
		while(sum) sum+=(s2[--top]==')')?1:-1;
	    }
	    else top++;
    }
    if(top==strlen(s2)) printf("Possible");
    else printf("Impossible");
}
