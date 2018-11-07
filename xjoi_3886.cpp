int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
	for(int j=1;j<=i*i;j++)
	    for(int k=1;k<=n;k++)
		f[i][j]=f[i][k
