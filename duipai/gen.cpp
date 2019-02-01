#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int n = 100000;
const int m = 300000;
set<pair<int, int> > s;
int main()
{
	srand(time(0));
    printf("%d %d\n", n, m);
    for(int i = 2; i <= n; i++){
	int y = rand()%(i-1)+1;
	printf("%d %d\n", i, y);
	s.insert(pii(i, y));
	s.insert(pii(y, i));
    }
    for(int i = n; i <= m; i++){
	int x = rand()%(n-1)+1, y = rand()%(n-1)+1;
        while(s.count(pii(x, y))){
	 x = rand()%(n-1)+1, y = rand()%(n-1)+1;
	}
	s.insert(pii(x, y));
	s.insert(pii(y, x));
	printf("%d %d\n", x, y);
}
return 0;
}

