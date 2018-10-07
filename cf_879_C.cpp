#include<cstdio>
#include<algorithm>
#include<iostream>
using  namespace std;
int n,ans1,ans2,x,ansxor,ansand,ansor,top;
char ch;
int main(){
	scanf("%d",&n);
	ans1=0; ans2=1023;
	for(int i=1;i<=n;i++){
		cin>>ch;scanf("%d",&x);
		if(ch=='|') ans1|=x,ans2|=x;
		if(ch=='&') ans1&=x,ans2&=x;
		if(ch=='^') ans1^=x,ans2^=x;
	}
	for(int j=0;j<=9;j++){
		if((!(ans1&(1<<j)))&&(!(ans2&(1<<j))))continue;
		ansand|=1<<j;
		if(((ans1&(1<<j)))&&((ans2&(1<<j)))){
			ansor|=1<<j;
			continue;
		}
		if(((ans1&(1<<j)))&&(!(ans2&(1<<j)))){
			ansxor|=1<<j;
			continue;
		}
	}
	top=0;
	if(ansand!=1023) top++;
	if(ansor) top++;
	if(ansxor) top++;
	printf("%d\n",top);
	if(ansand!=1023) printf("& %d\n",ansand);;
	if(ansor) printf("| %d\n",ansor);
	if(ansxor) printf("^ %d\n",ansxor);
}
