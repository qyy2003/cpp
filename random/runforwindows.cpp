#include<iostream>
#include<time.h>
#include<cstdio>
using namespace std;
int map[10000],n,N=48,x,na;
string nam[10000];
int pre(){
    freopen("data.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d",&x);
	map[x]=1;
    }
    fclose(stdin);
    freopen("CON","r",stdin); 
    freopen("/dev/tty","r",stdin);
    return 0;
}
int end(){
    freopen("data.in","w",stdout);
    printf("%d\n",n);
    for(int i=1;i<=N;i++){
	if(map[i])
	    printf("%d ",i);
    }
    return 0;
}
int name();
int main(){
    srand(time(NULL));
    name();
    pre();
    printf("Wecome to random\n");
    printf("1 for random a person\n");
    printf("0 for exit\n");
    printf("Please enter a number...\n");
    scanf("%d",&x);
    while(x){
	na=rand()%48+1;
	while(map[na]) na=rand()%48+1;
	map[na]=1;
	n++;
	cout<<"Let's congratulate "<<nam[na]<<"!"<<endl;
	if(n==48){
	    for(int i=1;i<=48;i++)
		map[i]=0;
	    n=0;
	}
	scanf("%d",&x);
    }
    end();
}
int name(){
    nam[1]="";
    nam[2]="";
    nam[3]="";
    nam[4]="";
    nam[5]="";
    nam[6]="";
    nam[7]="";
    nam[8]="";
    nam[9]="";
    nam[10]="";
    nam[11]="";
    nam[12]="";
    nam[13]="";
    nam[14]="";
    nam[15]="";
    nam[16]="";
    nam[17]="";
    nam[18]="";
    nam[19]="";
    nam[20]="";
    nam[21]="";
    nam[22]="";
    nam[23]="";
    nam[24]="";
    nam[25]="";
    nam[26]="";
    nam[27]="";
    nam[28]="";
    nam[29]="";
    nam[30]="";
    nam[31]="";
    nam[32]="";
    nam[33]="";
    nam[34]="";
    nam[35]="";
    nam[36]="";
    nam[37]="";
    nam[38]="";
    nam[39]="";
    nam[40]="";
    nam[41]="";
    nam[42]="";
    nam[43]="";
    nam[44]="";
    nam[45]="";
    nam[46]="";
    nam[47]="";
    nam[48]="";
    return 0;
}
