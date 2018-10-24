#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int a,b,flag,top,nn,flag1,sb[100000],sa[100000],topa,topb;
vector<int> q;
int main(){
    scanf("%d%d",&a,&b);
    if(a<b) swap(a,b),flag=1;
    top=1;
    while(a>=top){
	a-=top;
	sa[++topa]=top;
	top++;
    }
    while(b>=top){
	b-=top;
	sb[++topb]=top;
	top++;
    }
    flag1=a+b;
    for(int i=topa;i>=1;i--)
	if(i<=b)
	    sb[++topb]=i,b-=i;
	else
	    q.push_back(i);
    if(flag1>=top) q.push_back(top);
    sort(q.begin(),q.end());
    sort(sb+1,sb+topb+1);
    nn=q.size();
    if(flag){
	printf("%d\n",topb);
	for(int i=1;i<=topb;i++) 
	    printf("%d ",sb[i]);
	printf("\n%d\n",nn);
	for(int i=0;i<nn;i++)
	    printf("%d ",q[i]);
    }
    else{
	printf("%d\n",nn);
	for(int i=0;i<nn;i++)
	    printf("%d ",q[i]);
	printf("\n%d\n",topb);
	for(int i=1;i<=topb;i++) 
	    printf("%d ",sb[i]);
    }
}
