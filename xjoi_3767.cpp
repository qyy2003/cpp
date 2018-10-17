#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[10000],bo[4000],suma,sum[4000][3],cnt[3];
long long ans,fact3[4000],fact2[4000];
const long long P=1e9+7;
int cg(int x){ return (x>0)?0:1;}//change
int insert(int x,int y,int z){// 0 means to get||a 0,b 1,c 2
    x=a[x];
    if(!((sum[x][y]==0&&z==1)||(sum[x][y]==1&&z==-1))) return sum[x][y]+=z;
    cnt[cg(sum[x][1])+cg(sum[x][2])+cg(sum[x][0])]--;
    sum[x][y]+=z;
    cnt[cg(sum[x][1])+cg(sum[x][2])+cg(sum[x][0])]++;
}
int main(){
    scanf("%d",&n);
    fact2[0]=1;fact3[0]=1;
    for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	suma+=(bo[a[i]]==0)?1:0;bo[a[i]]=1;
	insert(i,2,1);
	fact2[i]=fact2[i-1]*2%P;fact3[i]=fact3[i-1]*3%P;
    }
    cnt[3]+=suma;
    printf("!%d\n",suma);
    for(int i=1;i<=n;i++){
	insert(i,1,1);
	for(int j=i+1;j<=n;j++){
	    insert(j,0,1);
	    if(!*cnt) ans=(ans+fact3[cnt[3]]*fact2[cnt[2]]%P)%P;
	    printf("%d %d %d %d %d %d %lld\n",i,j,cnt[0],cnt[1],cnt[2],cnt[3],fact3[cnt[3]]*fact2[cnt[2]]);
	    insert(j,0,-1);insert(j,2,-1);insert(j,1,1);
	}
	for(int j=i+1;j<=n;j++) insert(j,0,1);
	    printf("!%d %d %d %d %d %d %lld\n",i,1,cnt[0],cnt[1],cnt[2],cnt[3],fact3[cnt[3]]*fact2[cnt[2]]);
	if(!*cnt) ans=(ans+fact3[cnt[3]]*fact2[cnt[2]]%P)%P;
	for(int j=i+1;j<=n;j++) insert(j,0,-1),insert(j,1,-1),insert(j,2,1);
	insert(i,0,1); insert(i,1,-1); insert(i,2,-1);
    }
    printf("%lld\n",ans);
    printf("%lld",(fact3[suma]/*get all*/-fact2[suma]/*don't have a*/-ans+P)%P);
}

