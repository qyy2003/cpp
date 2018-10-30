#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n,M;
vector<int> q[1000005];
int main(){
    M=1e6;
    for(int i=2;i<=1000;i++)
	for(int j=1;j<=M/i;j++)
	  q[i*j].push_back(i+j);
}
