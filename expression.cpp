int main(){
    scanf("%d%d",&n,&p);scanf("%s",s);
    ma['+']=4;ma['-']=4;ma['*']=3;ma['/']=3;ma['(']=5;ma[')']=1;
    len=strlen(s);
    for(int i=0;i<len;i++){
        if(isdigit(s[i])){
            x=0;
            while(isdigit(s[i]))x=(x<<1)+(x<<3)+s[i]-'0',i++;
            node[++top]=make_pair(num,++size);
            num[++topn]=size;
        }
        if(map[s[i]]){
            if(s[i]==')'){
                while(
        while(ma[s[i]]<=ma[ss[tops]]){
            ss[tops--];

        
