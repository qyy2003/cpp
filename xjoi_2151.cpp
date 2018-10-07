#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int p=1e4;
struct node{
    int l,r,val,sum,tab;//val=min,sum=minsum;
}tree[100000];
int n,x,y,xx,yy,ans=0,last;
vector<pair<int,pair<int,int> > > f1[20005];
vector<pair<int,pair<int,int> > > f2[20005];
int build(int l,int r,int num){
tree[num].l=l; tree[num].r=r; tree[num].sum=r-l+1; tree[num].val=0,tree[num].tab=0;
if(l==r) return 0;
int mid=(l+r)>>1;
return build(l,mid,num<<1)+build(mid+1,r,num<<1|1);
}
int ask(int num)
{
    if(tree[num].val) return tree[num].sum;
        return tree[num].r-tree[num].l+1-tree[num].sum;
}
pair<int,int> add(int l,int r,int z,int num)
{
    if(l>tree[num].r||r<tree[num].l) 
        return make_pair(tree[num].val,tree[num].sum);
    //printf("$%d %d %d num=%d l=%d r=%d val=%d sum=%d\n",l,r,z,num,tree[num].l,tree[num].r,tree[num].val,tree[num].sum);
    if(l<=tree[num].l&&r>=tree[num].r)
    {
        //printf("YES%d %d %d %d %d",l,
        tree[num].val+=z;
        tree[num].tab+=z;
  //  if(tree[num].val==0) tree[num].sum=tree[num].r-tree[num].l+1;
   // printf("@%d %d %d num=%d l=%d r=%d val=%d sum=%d\n",l,r,z,num,tree[num].l,tree[num].r,tree[num].val,tree[num].sum);
        return make_pair(tree[num].val,tree[num].sum);
        //if(tree[num].sum<0) tree[num].sum++,tree[num].val-=tree[num].r-tree[num].l+1;
        //return ask(num);
    }
   // printf("$$%d %d %d num=%d l=%d r=%d val=%d sum=%d\n",l,r,z,num,tree[num].l,tree[num].r,tree[num].val,tree[num].sum);
   // if(z<0&&tree[num].sum>0&&((tree[num<<1].sum==0&&tree[num<<1].val<tree[num<<1].r-tree[num<<1].l+1)||(tree[num<<1|1].sum==0&&tree[num<<1|1].val<tree[num<<1|1].r-tree[num<<1|1].l+1)))
   // {
    tree[num<<1].val+=tree[num].tab;
    tree[num<<1|1].val+=tree[num].tab;
    tree[num<<1].tab+=tree[num].tab;
    tree[num<<1|1].tab+=tree[num].tab;
    tree[num].tab=0;
   // }
    int mid=(l+r)>>1;
    pair<int,int> x=add(l,r,z,num<<1),y=add(l,r,z,num<<1|1);
    if(x.first>y.first)
        tree[num].val=tree[num<<1|1].val,tree[num].sum=tree[num<<1|1].sum;
    else
        if(x.first<y.first)
        tree[num].val=tree[num<<1].val,tree[num].sum=tree[num<<1].sum;
        else
        tree[num].val=tree[num<<1|1].val,tree[num].sum=tree[num<<1|1].sum+tree[num<<1].sum;
   // if(tree[num].val==0) tree[num].sum=tree[num].r-tree[num].r-1;
        return make_pair(tree[num].val,tree[num].sum);
}    
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&x,&y,&xx,&yy);
        f1[x+p].push_back(make_pair(1,make_pair(y+p,yy+p-1)));
        f1[xx+p].push_back(make_pair(-1,make_pair(y+p,yy+p-1)));
        f2[y+p].push_back(make_pair(1,make_pair(x+p,xx+p-1)));
        f2[yy+p].push_back(make_pair(-1,make_pair(x+p,xx+p-1)));
    }
    build(0,2*p,1);last=0;
    for(int i=0;i<=2*p;i++)
    {
        n=f1[i].size();
        if(n)
        {
            sort(f1[i].begin(),f1[i].end());
            int j;
            for(j=n-1;j>=0;j--)
                if(f1[i][j].first>0)
                    add(f1[i][j].second.first,f1[i][j].second.second,f1[i][j].first,1);
                else
                    break;
            ans+=abs(last-ask(1));last=ask(1);
            for(;j>=0;j--)
                    add(f1[i][j].second.first,f1[i][j].second.second,f1[i][j].first,1);
            ans+=abs(last-ask(1));last=ask(1);
            //printf("!%d %d %d\n",i,ans,last);
        }
    }
    build(0,2*p,1); last=0;
    for(int i=0;i<=2*p;i++)
    {
        n=f2[i].size();
        if(n)
        {
            sort(f2[i].begin(),f2[i].end());
            int j;
            for(j=n-1;j>=0;j--)
                if(f2[i][j].first>0)
                    add(f2[i][j].second.first,f2[i][j].second.second,f2[i][j].first,1);
                else
                    break;
            ans+=abs(last-ask(1));last=ask(1);
            for(;j>=0;j--)
                    add(f2[i][j].second.first,f2[i][j].second.second,f2[i][j].first,1);
            ans+=abs(last-ask(1));last=ask(1);
            //printf("#%d %d %d\n",i,ans,last);
        }
    }
    printf("%d",ans);
}
