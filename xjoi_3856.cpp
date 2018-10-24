#include<cstdio>
#include<cstring>
using namespace std;
char s[10000],i,ii;
int main(){
    scanf("%s",s);
    for(i=0;i<strlen(s);i++)
    if(s[i]=='S') break;
    if(i==strlen(s)) return printf("%sSANTA",s),0;
    for(;i<strlen(s);i++)
    if(s[i]=='A') break;
    if(i==strlen(s)) return printf("%sSANTA",s),0;
    for(;i<strlen(s);i++)
    if(s[i]=='T') break;
    if(i==strlen(s)) return printf("%sSANTA",s),0;
    for(int j=0;j<i;j++) printf("%c",s[j]);
    printf("NT");
    for(int j=i+1;j<strlen(s);j++) printf("%c",s[j]);
    printf("A");
}
