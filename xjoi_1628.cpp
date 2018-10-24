#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
int n,ans,size,p,summ,last;
string  s[100005];
stack<string>q;
int insert(string s1,string s2){
    if(s1>=s2) return 0;;
    for(int i=0;i<s1.length();i++){
	if(s1[i]!=s2[i]) return 0;
    }
    return 1;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	cin>>s[i];
    }
    sort(s+1,s+n+1);
    for(int i=1;i<=n;i++) {
	while((!q.empty())&&(!insert(q.top(),s[i]))) q.pop();
	q.push(s[i]);
	ans=(ans>q.size())?ans:q.size();
    }
    printf("%d",ans);
}
