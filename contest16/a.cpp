#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],b[10000],bo[10000];
const int MAXA=1e6;
int first[MAXA<<1],nxt[MAXA<<1],go[MAXA<<1],val[MAXA<<1],tot=1;
void add(int x,int y,int z){
    nxt[++tot]=first[x]; first[x]=++tot; go[tot]=y; val[tot]=z;
}
void add(int x,int y){
    nxt[++tot]=first[x]; first[x]=++tot; go[tot]=y;
}
int work(){
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]),bo[b[i]]++;
    for(int i=1;i<=n;i++){
	bo[b[i]]--;
	if(bo[a[i]]!=1) m++;
	bo[b[i]]++;
    }
    printf("%d",m);
    return 0;
}
