#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,nn,sw,sw1,top,x,a[4],s[1000005];
vector< pair<int,pair<int,int> > >q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d",&x);
	if(x==1) s[++top]=i;
	else if(sw) sw1=i;
		    else sw=i;
    }
    //if(top==1||top==2||(top==4&&n==4)) return printf("NO"),0;
    while(top>4){
	q.push_back(make_pair(s[top-2],make_pair(s[top-1],s[top])));
	top-=3;
	sw1=s[top+1];
	sw=s[top+2];
    }
    if(top==3)
	while(top>0){ 
	    q.push_back(make_pair(s[top-2],make_pair(s[top-1],s[top])));
	    top-=3;
	}
    if(top==2) {
	if((!sw)||(!sw1)) return printf("NO"),0;
	q.push_back(make_pair(s[top],make_pair(sw1,sw)));
	q.push_back(make_pair(s[top-1],make_pair(sw1,sw)));
	top-=2;
	sw=s[top+1];
    }
    if(top==4) {
	if(!sw) return printf("NO"),0;
	q.push_back(make_pair(sw,make_pair(s[top-1],s[top])));
	q.push_back(make_pair(sw,make_pair(s[top-2],s[top-3])));
	top-=4;
    }
    if(top) return printf("NO\n"),0;
    int nn=q.size();
    printf("YES\n");
    printf("%d\n",nn);
    for(int i=0;i<nn;i++){
	a[0]=q[i].first; a[1]=q[i].second.first; a[2]=q[i].second.second;
	sort(a,a+3);
	printf("%d %d %d\n",a[0],a[1],a[2]);
    }
}

