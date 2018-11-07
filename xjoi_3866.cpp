#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
long long P=1e9+9,a[20],f[100][2000];
long long dfs(int w,int li){
    if(w<0) return 1;
    if(f[w][li]) return f[w][li];
    int lii=li;
    for(int i=0;i<n;i++)
	if((a[i]&(1ll<<w))&&(li&(1<<i)))
	    lii^=1<<i;
    f[w][li]=dfs(w-1,lii);
    for(int i=0;i<n;i++)
	if(li&(1<<i)){
	if(a[i]&(1ll<<w))
		f[w][li]=(f[w][li]+dfs(w-1,lii^(1<<i)))%P;
	}
	else
		f[w][li]=(f[w][li]+dfs(w-1,lii))%P;
    return f[w][li];
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    printf("%lld",dfs(60,(1<<n)-1));
}
