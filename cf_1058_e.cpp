int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%lld",&x);
	while(x){
	    x-=x&(-x);
	    y++;
	}
	ans+=f[i-1][y];
	for(int i=1;i<=n;i++)
