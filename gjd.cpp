#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Num{
    public:
    Num(int _=0,int __=0):fu(_),top(__){};
    int nu[600000],top,fu;
    int read();
    int print();
    Num add(Num x);
    //int times();
    Num fuu(Num y);
};
int Num::read(){
    char ch=getchar();
    while(ch^'-'&&!isdigit(ch)) ch=getchar();
    if(ch=='-') fu=1,ch=getchar();
    while(isdigit(ch)) nu[++top]=ch-'0',ch=getchar();
    for(int i=1;i<=top/2;i++) swap(nu[i],nu[top-i+1]);
}
int Num::print(){
    if(fu) printf("-");
    for(int i=top;i>=1;i--){
	if(nu[i]) printf("%d",nu[i]);
	else printf("0");
    }
}
Num Num::fuu(Num x){
    x.fu^=1;
    return x;
}
Num Num::add(Num x){
    Num ans;
    ans.top=max(x.top,top);
    for(int i=1;i<=ans.top;i++){
       ans.nu[i]+=nu[i]+x.nu[i];
       ans.nu[i+1]+=ans.nu[i]/10;
       ans.nu[i]=ans.nu[i]%10;
    }
    if(ans.nu[ans.top+1]) ans.top++;
    return ans;
}
int main(){
    Num a,b,c;
    a.read(); b.read();
    //c.add(a); c.add(b);
    c=a.add(b);
    c.print();
}
