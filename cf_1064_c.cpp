#include<cstdio>
#include<algorithm>
using namespace std;
int nn;
char ss[700000];
int main(){
scanf("%d",&nn);
scanf("%s",ss);
sort(ss,ss+nn);
printf("%s",ss);
}
