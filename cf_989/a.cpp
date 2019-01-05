#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[10000];
int a[10000];
int main(){
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<3;i++) a[s[i]]++;
    if(a['A']&&a['B']&&a['C']) return printf("Yes\n"),0;
    for(int i=3;i<n;i++){
	a[s[i]]++;
	a[s[i-3]]--;
	if(a['A']&&a['B']&&a['C']) return printf("Yes\n"),0;
    }
    return printf("No\n"),0;
}
