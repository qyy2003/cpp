#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
string s;
int n,x,top=0;
vector<int> v[100];
int read(int &x){
    x=0;
    while(top<s.length()&&(!isdigit(s[top]))) top++;
    while(top<s.length()&&(isdigit(s[top]))) x=(x<<1)+(x<<3)+s[top]-'0',top++;
    return x;
}

int dfs(int x){
    b[x]=1;
    for(int i=1;i<=x;i++)

int main(){
    getline(cin,s);
    top=0;
    read(n);
    for(int i=1;i<=n;i++){
	top=0;
	getline(cin,s);
	while(read(x)) v[i].push_back(x);
    }
    printf("%lld",dfs(1));
}
