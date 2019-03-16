#include<bits/stdc++.h>
using namespace std;
class node{
    public:
	node* l=NULL,*r=NULL,*fa=NULL;
	int siz=1,val,rnd,sum=1;
	node(int _val=0,int _rnd=0):val(_val),rnd(_rnd){}
	void print(){
	    if(fa!=NULL) printf("fa=%d ",fa->val);
	    else printf("fa! ");
	    if(l!=NULL) printf("l=%d ",l->val);
	    else printf("l! ");
	    if(r!=NULL) printf("r=%d ",r->val);
	    else printf("r! ");
	    printf("val=%d siz=%d rnd=%d sum=%d\n",val,siz,rnd,sum);
	    printf("\n");
	}
};
class Treap{
    public:
	node *root=new node(-1,0);
	node *pos=NULL,*pre=NULL,*swapp;
	void swp(node *son){
	    node *fa=son->fa;
	    printf("%d %d\n",fa->val,son->val);
	    if(son->val < fa->val) fa->l=son->r,son->r->fa=fa,son->r=fa;
	    else fa->r=son->l,son->l->fa=fa,son->l=fa;
	    son->fa=fa->fa;fa->fa=son;
	    fa=son->fa;
	    if(son->val < fa->val) fa->l=son;
	    else fa->r=son;
	}
	void add(int x){
	    pos=root;
	    while(pos!=NULL){
		if(pos->val==x){ pos->sum++; return; }
		pre=pos;
		if(pos->val > x) pos=pos->l; else pos=pos->r;
	    }
	    if(pre->val>x){pre->l=new node(x,rand());pre->l->fa=pre; pos=pre->l;}
	    else{pre->r=new node(x,rand()); pre->r->fa=pre;pos=pre->r;}
	    while(pos->rnd<pre->rnd){
		swp(pos);
		//swapp=pos;
		//pos=pre;
		//pre=swapp;
		swap(pre,pos);
		if(pre->val==-1) break;
	    }
	}
	void del(int x){
	    pos=root;
	    while(pos->val!=x){
		if(pos->val > x) pos=pos->l;
		else pos=pos->r;
	    }
	    if(pos->sum>1){
		pos->sum--;
		return;
	    }
	    while((pos->l!=NULL)&&(pos->r!=NULL)){
		pos->print();
		if(pos->l->rnd < pos->r->rnd) swp(pos->l);
		else swp(pos->r);
		pos->print();
	    }
	    pre=NULL;
	    if(pos->l!=NULL) pre=pos->l;
	    if(pos->r!=NULL) pre=pos->r;
	    if(pre!=NULL){
		pre->fa=pos->fa;
		if(pre->fa->val < pre->val) pre->fa->r=pre;
		else pre->fa->l=pre;
	    }else{
		if(pos->fa->r==pos) pos->fa->r=NULL;
		else pos->fa->l=NULL;
	    }
	    delete pos;
	}
	void print(node *x){
	    printf("x=%d ",x->val);
	    if(x->l!=NULL) printf("l=%d ",x->l->val);
	    if(x->r!=NULL) printf("r=%d ",x->r->val);
	    printf("\n");
	    if(x->l!=NULL) print(x->l);
	    if(x->r!=NULL) print(x->r);
	}

}T;

int test(){
    T.add(10);
    T.add(5);
    T.add(2);
}

int main(){
    //return test();
    srand(time(NULL));
    int t,xx,yy;
    scanf("%d",&t);
    while(t--){
	scanf("%d%d",&xx,&yy);
	switch(xx){
	    case 1:T.add(yy);break;
	    case 2:T.del(yy);break;
		   //case 3:T.rating(yy);break;
		   //case 4:T.ask(yy);break;
		   //case 5:T.askl(yy);break;
		   //case 6:T.askr(yy);break;
	}
	printf("\nt=%d\n",t);
	T.print(T.root);
    }
}
