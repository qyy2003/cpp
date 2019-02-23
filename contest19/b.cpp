#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,s,f,t,l,r,pos,now;
int ask(){
    if(s<f) return 1;
    return -1;
}
char print(int x){
    if(x==1) return 'R';
    return 'L';
}
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&f);
    scanf("%d%d%d",&t,&l,&r);
    pos=s;
    while(pos!=f){
	now++;
	if(now==t){
	    if((l<=pos+ask()&&r>=pos+ask())||(l<=pos&&r>=pos)){
		putchar('X');
		scanf("%d%d%d",&t,&l,&r);
		continue;
	    }
	    scanf("%d%d%d",&t,&l,&r);
	}
	pos=pos+ask();
	putchar(print(ask()));
    }
}
