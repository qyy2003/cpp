#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,q,x,y,ans,xx;
vector <int> v[505];
int main(){
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=m;i++){
                scanf("%d%d",&x,&y);
                v[y].push_back(x);
        }
        for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
        for(int i=1;i<=q;i++){
                scanf("%d%d",&x,&y);
                for(int i=x;i<=y;i++){
                        xx=lower_bound(v[i].begin(),v[i].end(),x)-v[i].begin();
                                ans+=v[i].size()-xx;
                    }
                printf("%d\n",ans);
                ans=0;
        }
}
