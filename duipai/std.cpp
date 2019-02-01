#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <ctime>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <functional>
#include <algorithm>
typedef unsigned long long LL;
const int N = 100010;
const int M = 300010;
LL val[N];
int fa[N];
int stack[N];
int head[N];
int pnt[M * 2];
int nxt[M * 2];
int E;
int cover[N];
int start[M * 2];
int dep[N];
LL myrand()
{
        LL ret = 0;
        for(int i = 0; i < 4; i++) {
                ret = ret << 16;
                ret |= rand();
        }
        return ret;
}
void add_edge(int a, int b)
{
        start[E] = a;
        pnt[E] = b;
        nxt[E] = head[a];
        head[a] = E++;
}
int tot;
void dfs(int u, int f)
{
        stack[++tot] = u;
        fa[u] = f;
        dep[u] = dep[f] + 1;
        for(int i = head[u]; i != -1; i = nxt[i]) {
                if(!dep[pnt[i]]) {
                        dfs(pnt[i], u);
                }
        }
}
int main()
{
        srand(time(NULL));
        int n, m, a, b;
        scanf("%d%d", &n, &m);
        std::fill(head + 1, head + n + 1, -1);
        for(int i = 0; i < m; i++) {
                scanf("%d%d", &a, &b);
                add_edge(a, b);
                add_edge(b, a);
        }
        dfs(1, 0);
        for(int i = 0; i < 2*m; i += 2) {
                a = start[i], b = pnt[i];
                if(dep[a] < dep[b]) {
                        std::swap(a, b);
                }
                cover[a]++, cover[b]--;
                if(dep[b] + 1 == dep[a]) {
                        continue;
                }
                LL v = myrand();
                val[b] ^= v, val[a] ^= v;
        }
        for(int i = n; i >= 1; i--) {
                cover[fa[stack[i]]] += cover[stack[i]];
                val[fa[stack[i]]] ^= val[stack[i]];
        }
        long long ret = std::count(cover + 1, cover + 1 + n, 2);
        long long bridge = std::count(cover + 1, cover + n + 1, 1);
        ret += bridge * (bridge - 1) / 2 + bridge * (m - bridge);
        printf("%lld %lld\n", bridge, bridge * (bridge - 1) / 2 + bridge * (m - bridge));
        std::sort(val + 1, val + n + 1);
        for(int i = 1, len; i <= n; i++) {
                if(val[i] == 0) {
                        continue;
                }
                if(val[i] == val[i - 1]) {
                        ret += len++;
                } else {
                        len = 1;
                }
        }
        printf("%lld\n", ret);
        return 0;
}

