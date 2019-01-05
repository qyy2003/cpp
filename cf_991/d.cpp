#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char s1[100000],s2[100000],ans;
long long f[100000][5];
int main(){
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    int n=strlen(s1+1);
    //f[0][0]=f[0][1]=f[0][2]=-1;
    memset(f,-1,sizeof(f));
    f[0][3]=f[0][4]=0;
    for(int i=1;i<=n;i++){
	if(s1[i]=='X'&&s2[i]=='X'){
	    f[i][3]=f[i-1][4];
	}
	if(s1[i]=='X'&&s2[i]=='0'){
	    f[i][2]=f[i-1][4];
	    f[i][3]=f[i-1][0]+1;
	}
	if(s1[i]=='0'&&s2[i]=='X'){
	    f[i][1]=f[i-1][4];
	    f[i][3]=f[i-1][0]+1;
	}
	if(s1[i]=='0'&&s2[i]=='0'){
	    f[i][0]=f[i-1][4];
	    f[i][1]=f[i-1][0]+1;
	    f[i][2]=f[i-1][0]+1;
	    f[i][3]=max(max(f[i-1][0],f[i-1][1]),f[i-1][2])+1;
	}
	f[i][4]=max(max(f[i][1],f[i][0]),max(f[i][2],f[i][3]));
    }
    printf("%lld",f[n][4]);
}
/*
0:
  0
  0
1:
  0
  1
2:
  1
  0
3:
  1
  1
*/
