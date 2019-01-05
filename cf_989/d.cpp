int main(){
    scanf("%d%d%d",&n,&l,&w);
    for(int i=1;i<=n;i++){
	scanf("%d%d",&x,&y);
	if(y==1) q1.push_back(x);
	if(y==2) q2.push_back(x);
    }
    sort(q2.begin(),q2.end());
    n=q1.size();
    long long ans=0;
    for(int i=0;i<n;i++){
	x=q1[i];
	ans+=max(0,
		    upper_bound(q2.begin(),q2.end(),2*w-x
		    lower_bound(q2.begin(),q2.end(),x)
		);
