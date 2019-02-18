#include<bits/stdc++.h>
using namespace std;
int n;
int ask(int x,int y){
    int an;
    printf("0 %d %d\n",x+y,x+y);
    fflush(stdout);
    scanf("%d",&an);
    return an;
}
void work(int x,int y){
    int an=ask(x+y,x+y);
    if(an>=y) return x;
    int pos=x+y;
    df[];
}

void print(){
    sort(sx+1,sx+n+1);
    topx=unique(sx+1,sx+topx+1)-(sx+1);
    sort(sy+1,sy+n+1);
    topy=unique(sy+1,sy+topy+1)-(sy+1);
    printf("%d %d %d",1,topx,topy);
    for(int i=1;i<=topx;i++) printf("%d ",sx[i]);
    printf("\n");
    for(int i=1;i<=topy;i++) printf("%d ",sy[i]);
}
int main(){
    work(-1e8,1e8);
    print();
    return 0;
}
