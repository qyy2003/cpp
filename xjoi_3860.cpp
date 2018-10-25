int main(){
    scanf("%d%lld%d",&n,&seed,&m);
    for(int i=1;i<=n;i++){
	a[i]=(seed/(1<<16))%m;
	seed=(seed*1103515245+12345)%(1<<31);
    }
    for(int i=1;i<=m;i++){
	memset(f,0,sizeof(f));
	for(int j=1;j<=n;j++){
	    sum=0;
	    for(int k=j;j>=0;j-=j&(-j)) sum+=f[j];
	    ans+=sum;
	    if(a[j]==m){
		for(int k=j;j<=n;j+=(j&-j))

