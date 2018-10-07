int main(){
scanf("%d%d%d",&n,&m,&k);
for(int i=1;i<=m;i++){
scanf("%d%d",&x,&y);
add(x,y);      
add2(x,y);
v.push_back(make_pair(x,y));
sum[x]++;
sum2[y]++;
}
for(int i=1;i<=n;i++)
  if(!sum[i])
	dfs(i);
for(int i=1;i<=n;i++)
  if(!sum2[i])
	dfs2(i);
for(int i=1;i<=m;i++){
scanf("%d%d",&x,&y);
if(x==1)
