#include<bits/stdc++.h>
using namespace std;
const long long P=1e9+7;
template<class T,int N,int M>
class Matrix{
    private:
    char ch[10];
    public:
    T n,m,A[N][M];
    Matrix(int _n=0,int _m=0):n(_n),m(_m){memset(A,0,sizeof(A));}
    friend Matrix<T,N,M> operator * (Matrix<T,N,M> a ,Matrix<T,N,M> b){
	Matrix<T,N,M> ans(a.n,b.m);
	for(int i=0;i<a.n;i++)
	    for(int j=0;j<b.m;j++)
		for(int k=0;k<a.m;k++)
		    ans.A[i][j]=(ans.A[i][j]+a.A[i][k]*b.A[k][j]%P)%P;
	return ans;
    }
    void pre(){
        if(typeid(T).name()==typeid(int).name()) sprintf(ch,"%%d "); 
        if(typeid(T).name()==typeid(long long).name())sprintf(ch,"%%lld ");
    }
    void scan(){
    pre();
    for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	    scanf(ch,&A[i][j]);
    }
    void print(){
    pre();
    for(int i=0;i<n;i++,printf("\n"))
	for(int j=0;j<m;j++)
	    printf(ch,A[i][j]);
    }
};
int n,m,t,last;
int b[1000];
Matrix<long long,50,50>Std;
Matrix<long long,50,50>a;
Matrix<long long,50,50>an;
void wr(int x,int y,int z){
    if(b[y]) return ;
    Std.A[x][y]=z;
    Std.A[y][x]=z;
}

void write(int i,int j,int z){
    int x=(i-1)*m+j-1;
    Std.A[x][x]=z;
    if(i>1) wr(x,x-m,z);
    if(i<n) wr(x,x+m,z);
    if(j>1) wr(x,x-1,z);
    if(j<m) wr(x,x+1,z);
}

void work(int x){
    while(x){
	//printf("x: %d a: \n",x);
	//[a.print();
	if(x&1) an=a*an;
	x>>=1; a=a*a;
    }
}

void solve(){
    int fl,x,y,z;
    scanf("%d%d%d%d",&fl,&x,&y,&z);
    a=Std;
    work(z-last);
	//printf("an:\n");
	//an.print();
    last=z;
    if(fl==2){
	write(x,y,0);
	an.A[(x-1)*m+y-1][0]=0;
	b[(x-1)*m+y-1]=1;
//	an.print();
//	Std.print();
    }
    if(fl==3){
	write(x,y,1);
	b[(x-1)*m+y-1]=0;
    }
    if(fl==1) printf("%lld\n",an.A[(x-1)*m+y-1][0]);
}

int main(){
    scanf("%d%d%d",&n,&m,&t);
    an.n=Std.n=Std.m=n*m;
    an.m=1;
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
	    write(i,j,1);
	}
    an.A[0][0]=1;
    last=1;
    for(;t;t--) solve();
}
