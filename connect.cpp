#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<cstdio>
#include<map>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXA=1e5+50000;
int n,m,qq,x,y,ans,nn,l,r;
int nxt[MAXA],last[MAXA],s[MAXA],q[MAXA];
map<pair<int,int>,bool> ma;
void read(int &x){
    char ch=getchar(); x=0; 
    while(!isdigit(ch)&&ch^'0') ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
}
int bfs(){
    int x;
    while(l<=r){
        x=q[l++];
       // printf("!%d \n",x);
        for(int i=nxt[0];i<=n;i=nxt[i]){
            if(!ma[make_pair(s[x],s[i])]){
                q[++r]=i; last[nxt[i]]=last[i]; nxt[last[i]]=nxt[i]; 
                //break;
            }
        }
        //for(int j=0;j<=n+1;j++) printf("%d %d %d\n",j,nxt[j],last[j]);
        if(nxt[0]==n+1) return 0;
    }
}
int main(){
    scanf("%d%d%d",&nn,&m,&qq);
    for(int i=1;i<=m;i++){
        read(x); read(y);
        ma[make_pair(x,y)]=1;
        ma[make_pair(y,x)]=1;
    }
  //  return 0;
    for(int i=1;i<=qq;i++){
        scanf("%d",&n);
        nxt[0]=1; ans=0; last[n+1]=n; nxt[n+1]=n+1;
       // printf("No");
        for(int j=1;j<=n;j++) read(s[j]);
       // printf("YES");
        for(int j=1;j<=n;j++) nxt[j]=j+1,last[j]=j-1;
        while(nxt[0]!=n+1){
            l=0; r=0; ans++; 
            q[0]=nxt[0]; nxt[0]=nxt[nxt[0]]; last[nxt[0]]=0; 
            //for(int j=0;j<=n+1;j++) printf("%d %d %d\n",j,nxt[j],last[j]);
            bfs();
        }
        printf("%d\n",ans);
    }
}
