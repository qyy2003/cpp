#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+7;
int n;
class Node{
    public:
	Node *l,*r,*fa;int val,flag,siz;
	Node(int _val):val(_val){flag=0;siz=1;l=r=fa=NULL;}
	void swp(){
	    if(!flag) return;
	    swap(l,r);flag=0;
	    if(l!=NULL) l->flag^=1;
	    if(r!=NULL) r->flag^=1;
	}
	void asksiz(){
	    siz=1;
	    if(l!=NULL) siz+=l->siz;
	    if(r!=NULL) siz+=r->siz;
	}
};
class Splay{
    public:
	Node *root,*pos,*pre;
	Splay(){root=new Node(MAXN);}
	void build(Node *pos,int x){
	    pos->l=new Node(x); pos->l->fa=pos; pos->l->siz=x+1;
	    if(x) build(pos->l,x-1);
	}
	void swp(Node *son){
	    Node *faa=son->fa;
	    if(faa->l==son){
		faa->l=son->r;
		if(son->r!=NULL) son->r->fa=faa;
		son->r=faa;
	    }else{
		faa->r=son->l;
		if(son->l!=NULL) son->l->fa=faa;
		son->l=faa;
	    }
	    if(faa->fa->l==faa) faa->fa->l=son;else faa->fa->r=son;
	    son->fa=faa->fa; faa->fa=son; faa->asksiz(); son->asksiz();
	}
	Node *find(int x){
	    pos=root->l;
	    while(x){
		pos->swp();
		if((pos->l!=NULL)&&(pos->l->siz >= x)){pos=pos->l;continue;}
		if(pos->l!=NULL) x-=pos->l->siz;
		if(x<=1) break;
		x--; pos=pos->r;
	    }
	    return pos;
	}
	void up(Node *son){
	    if(son->fa==root) return;
	    if(son->fa->fa==root) return swp(son);
	    if((son->fa->l==son&&son->fa->fa->l==son->fa)&&(son->fa->r==son&&son->fa->fa->r==son->r)){
		swp(son->fa);
		swp(son);
	    }else swp(son);
	    return up(son);
	}
	void turn(int x,int y){
	    up(find(x+1));
	    int sizl=root->l->l->siz;
	    up(find(y+1));
	    int sizr=root->l->l->siz+2;
//	    printf("%d %d\n",sizl,sizr);
//	    fflush(stdout);
	    up(find(sizl));
	    up(find(sizr));
	    if(root->l->l!=NULL&&root->l->l->r!=NULL) root->l->l->r->flag^=1;
	}
	void printans(Node *pos){
	    pos->swp();
	    if(pos->l!=NULL) printans(pos->l);
	    if(pos->val<=n&&pos->val>0)printf("%d ",pos->val);
	    if(pos->r!=NULL) printans(pos->r);
	}
	void print(Node *pos){
	    printf("val=%d siz=%d flag=%d ",pos->val,pos->siz,pos->flag);
	    if(pos->l!=NULL) printf("l=%d ",pos->l->val);
	    if(pos->r!=NULL) printf("r=%d ",pos->r->val);
	    printf("\n");
	    if(pos->l!=NULL) print(pos->l);
	    if(pos->r!=NULL) print(pos->r);
	}
}T;
int main(){
    int t,x,y;
    scanf("%d%d",&n,&t);
    T.build(T.root,n+1);
    //T.print(T.root);
    //for(int i=1;i<=n;i++) T.add(i);
    while(t--){
	scanf("%d%d",&x,&y);
	T.turn(x,y);
	//T.print(T.root);
	//T.printans(T.root->l);
	//printf("\n\n");
    }
    T.printans(T.root->l);
}
