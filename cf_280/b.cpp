#include<bits/stdc++.h>
using namespace std;
const int MAXA=1e5+7;
class Main{
    public:
    int s[MAXA<<1],a[MAXA<<1],n,ans,top;
    int work(){
	ans=0;top=0;
	for(int i=1;i<=n;i++){
	    while(top&&s[top]<a[i]){
		ans=max(ans,s[top]^a[i]);
		top--;
	    }
	    s[++top]=a[i];
	}
	return ans;
    }
}T[2];
int main(){
    scanf("%d",&T[0].n);T[1].n=T[0].n;
    for(int i=1;i<=T[0].n;i++) scanf("%d",&T[0].a[i]);
    for(int i=1;i<=T[0].n;i++) T[1].a[i]=T[0].a[T[0].n-i+1];
    printf("%d",max(T[0].work(),T[1].work()));
}
