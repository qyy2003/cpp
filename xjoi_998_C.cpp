#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
void read(int &x){
    char ch=getchar(); x=0; 
    while(!isdigit(ch)&&ch^'0') ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
}
int main(){
    scanf("%d%d%d",&n,&m,&kk);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) read(b[i]);
    for(int i=1;i<=m;i++){
        read(x); read(y);
        add(x,y); add(y,z);
    }
    scanf("%d",&q);
    for(int cn=1;cn<=q;cn++){
        memset(bo,0,sizeof(bo));
        read(nn);
        for(int i=1;i<=nn;i++){
            read(x); bo[x]=1;
        }
        for(int i=1;i<=n;i++){
            if(bo[i]) continue;
            memset(col,0,sizeof(




