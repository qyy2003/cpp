#include<bits/stdc++.h>
using namespace std;
int n,m;
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
    scanf("%d%d",&n,&m);
    printf("%d%d",n,m);
    return 0;
}
