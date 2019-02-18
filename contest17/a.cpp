#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ann,an,ans,len[10000];
char s[200][2000];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%s",s[i]);
	len[i]=strlen(s[i]);
    }
    for(int i=0;i<26;i++)
	for(int j=i+1;j<26;j++){
	    for(int k=1;k<=n;k++){
		ann=0;
		for(int x=0;x<len[k];x++)
		    if(s[k][x]=='a'+i||s[k][x]=='a'+j)
			ann++;
		if(ann==len[k]) an+=len[k];
	    }
	    ans=max(ans,an);
	    an=0;
	}
    printf("%d",ans);
}
