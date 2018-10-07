#pragma GCC optimize("inline","O3","Ofast")
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int q,x,y,maxand,maxor,a[100],son[1<<24][3],now1,now2,bo[1<<24],size;
void read(int &x){
    char ch=getchar(); x=0; 
    while(!isdigit(ch)&&ch^'0') ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
}
int change(int x){
    for(int i=20;i>=1;i--)
        a[i]=x&1,x>>=1;
}

int insert(int x,int deep){
    if(deep>=20) return 0;
    if(!son[x][a[deep+1]]){
        son[x][a[deep+1]]=++size;
    }
        return insert(son[x][a[deep+1]],deep+1);
}

int askxor(int x,int deep){
    if(deep>=20) return 0;
       // printf("$%d %d\n",deep,a[deep+1]);
    if(son[x][a[deep+1]^1]) return askxor(son[x][a[deep+1]^1],deep+1)+(1<<(20-deep-1));
       // printf("$$%d %d\n",deep,a[deep+1]);
    return askxor(son[x][a[deep+1]],deep+1);
}

int add(int x){
    bo[x]=1;
    for(int i=0;(1<<i)<=x;i++)
    if((x&(1<<i))&&(!bo[x^(1<<i)])) add(x^(1<<i));
}

int main(){
    scanf("%d",&q);
    for(int cn=1;cn<=q;cn++){
        read(x); read(y);
        maxand=0;
        maxor=0;
        change(y);
        if(x==1) add(y),insert(0,0);
        if(x==3) printf("%d\n",askxor(0,0));
        if(x!=2) continue;
        now1=now2=0;
        for(int i=1;i<=20;i++)
            if(a[i]&&(1<<(20-i))){
                if(bo[now1+(1<<(20-i))])
                    now1+=(1<<(20-i));
            }
            else
                if(bo[now2+(1<<(20-i))])
                    now2+=(1<<(20-i));
        printf("%d %d %d\n",askxor(0,0),now1,now2|y);
    }
}
