2．（连续邮资问题）某国发行了n 种不同面值的邮票，并规定每封信最多允许贴m 张邮票，在这些约束下，为了能贴出{1，2，3,…，maxvalue}连续整数集合的所有邮资，并使maxvalue 的值最大，应该如何设计各邮票的面值？例如，当n=5、m=4 时，面值设计为{1，3，11，15，32}，可使maxvalue 达到最大值70（或者说，用这些面值的1 至4 张邮票可以表示不超过70 的所有邮资，但无法表示邮资71。而用其他面值的1 至4 张邮票如果可以表示不超过k 的所有邮资，必有k≤70）。
下面是用递归回溯求解连续邮资问题的程序。数组x[1:n]表示n 种不同的邮票面值，并约定各元素按下标是严格递增的。数组 bestx [1:n]存放使maxvalue 达到最大值的邮票面值（最优解），数组y[maxl]用于记录当前已选定的邮票面值x[1:i]能贴出的各种邮资所需的最少邮票张数。请将程序补充完整。
#include <iostream.h>
#define NN 20
#define maxint 30000
#define maxl 500
int n,m,bestx[NN],x[NN],y[maxl],maxvalue=0;
void result()
{int j;
	cout<<"r="<<maxvalue<<endl;
	for(j=1;j<=n;j++)
		cout<<bestx[j]<<" ";
	cout <<endl;
}
void backtrace(int i,int r)
{ int j,k,z[maxl];
	for(j=0;j<= ① ;j++)
		if(y[j]<m)
			for(k=1;k<=m-y[j];k++)
				if(y[j]+k<=y[ ② ])
					y[ ③ ]=y[j]+k;
	while(y[r]<maxint) r++;
	if(i>n)
	{if(r-1>maxvalue)
		{maxvalue= ④ ;
			for(j=1;j<=n;j++) bestx[j]=x[j];
		}
		return;
	}
	for(k=0;k<maxl;k++)
		z[k]=y[k];
	for(j= ⑤ ;j<=r;j++)
	{x[i]=j;
		⑥ ;
		for(k=0;k<maxl;k++)
			y[k]=z[k];
	}
}
void main()
{int j;
	cout<<"input n,m:"<<endl; cin >>n>>m;
	for(j=1;j<maxl;j++)
		y[j]=maxint;
	y[0]=0; x[0]=0; x[1]=1;
	backtrace(2,1);
	result();
}
