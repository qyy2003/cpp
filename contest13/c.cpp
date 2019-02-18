#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char c[1000000],s[1000000];
int top;
int main(){
    scanf("%s",c+1);
    int len=strlen(c+1);
    for(int i=1;i<=len;i++){
	while(top&&(c[i]>s[top])) top--;
	s[++top]=c[i];
    }
    for(int i=1;i<=top;i++) printf("%c",s[i]);
}
