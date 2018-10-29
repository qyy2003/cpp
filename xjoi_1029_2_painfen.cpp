int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
	getchar();
	for(int j=0;j<m;j++){
	    ch=getchar();
	    if(ch=='#') f[i]|=1<<j;
	    }
    }
    flag1=1;flag2=1;flag3=1;flag4=1;
    for(int i=1;i<=n;i++)
	for(int j=0;j<m;j++)
	    if(f[i]&(1<<j)){
		if((i>1)&&(!(f[i-1]&(1<<j)))) flag1=0;
		if((i<n)&&(!(f[i+1]&(1<<j)))) flag3=0;
		if((j)&&(!(f[i]&(1<<(j-1))))) flag2=0;
		if((j<m-1)&&(!(f[i]&(1<<(j+1))))) flag4=0;
	    }
    for(int i=1;i<=n;i++){
	step=0;
	for(int j=0;j<m;j++)
	    f[i]=
