int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	for(int j=1;j<=n+1;j++)
	    scanf("%lld",&a[i][j]);
    for(int i=1;i<=n;i++){
	for(nxt=i;!a[nxt][i];nxt++);
	for(int j=1;j<=n+1;j++) swap(a[i][j],a[nxt][j]);
	for(int j=1;j<=n;j++){
	    mul=a[i][j]*gcd(
