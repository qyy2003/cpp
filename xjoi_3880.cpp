#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,r1[1000],r2[1000],ans,x,y,fa[10000],ans1,ans2;
char s[1000];
int find(int x){
    return fa[x]=(x==fa[x])?x:find(fa[x]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n+m;i++) fa[i]=i;
    for(int i=0;i<n;i++){
	scanf("%s",s);
	for(int j=0;j<m;j++)
	    if(s[j]=='#'){
		r1[i]++;
		r2[j]++;
		x=find(i);
		y=find(n+j);
		if(x!=y) fa[x]=y;
	    }
    }
    for(int i=0;i<n;i++) 
	if(find(i)==i&&r1[i])
	    ans++;
    for(int i=0;i<m;i++) 
	if(find(i+n)==i+n&&r2[i])
	    ans++;
    if(ans>=2) return printf("NO"),0;
    ans1=0;ans2=0;
    for(int i=0;i<n;i++)
	ans1+=(r1[i]&1);
    for(int i=0;i<m;i++)
	ans2+=(r2[i]&1);
    if(ans1+ans2>2||ans1==2) return printf("NO"),0;
    printf("YES");
}
