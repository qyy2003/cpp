#include<cstdio>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
int n,last,x,y,num[1010],xx[1010],b[1010];
queue<int>q;
int ma[1010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
       // printf("$%d %d %d\n",x,y,min(x,y));
        if(max(x,y)!=n) return printf("NO"),0;
        num[min(x,y)]++;
        xx[i]=min(x,y);
    }
    b[n]=n;
    last=n;
    for(int i=n-1;i>=1;i--){
     //   printf("!%d %d!",last,num[i]);
        if(!num[i]){ 
            if(q.empty()) return printf("NO"),0;
            b[q.front()]=i;
            q.pop();
            continue;
        }
        while(num[i]>1)
                q.push(--last),num[i]--;
        last--;
        b[last]=i;
        ma[i]=last;
    }
            if(!q.empty()) return printf("NO"),0;
    //for(int i=1;i<=n;i++) printf("%d ",b[i]);
    printf("YES\n");
    for(int i=1;i<n;i++)
        printf("%d %d\n",b[ma[xx[i]]],b[ma[xx[i]]+1]),ma[xx[i]]++;
}
        


        
