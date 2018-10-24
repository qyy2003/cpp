#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int n,bo[100000],top,a,b,x,nn,fa[100000],y,nnn;
string s;
int read(int &x){
    x=0;
    while(top<nnn&&!isdigit(s[top])) top++;
    while(top<nnn&&isdigit(s[top])) x=(x<<1)+(x<<3)+s[top]-'0',top++;
    return 1;
}
int main(){
    scanf("%d%d%d",&n,&a,&b);
    //nn=n-1;
    getchar();
    while(getline(cin,s)){
	top=0;
	nnn=s.size();
	//cout<<s;
	read(x);
//	printf(" $%d$ ",x);
	while(read(y)&&y){
	    fa[y]=x;
//	    printf(" !%d! ",y);
	   // nn--;
	}
//	printf("%d",nn);
    }
    //return 0;
    while(fa[a]){
	bo[a]=1;
	a=fa[a];
    }
    while(fa[b]&&(!bo[b])){
	b=fa[b];
    }
    printf("%d",b);
}
