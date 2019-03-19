int main(){
    scanf("%lf%lf%lf",&w,&h,&a);
    if(a<90){
    a=a*cos(-1)/ALL;
    h-=w/tan(a)+w/sin(a);
    k=tan(a)-ONE/(tan(a)*cos(a))-ONE/tan(a)-ONE/(cos(a)*sin(a))-ONE/(sin(a));
    
