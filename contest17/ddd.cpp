#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

typedef long long LL;
const int MAXN = 2e5 + 10;

inline LL in()
{
    LL x = 0, flag = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') flag = -1; ch = getchar(); }
    while (ch >='0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * flag;
}

int n, m;

int head[MAXN], nume;
struct Adj
{
    int nex, to, id;
    LL w;
} adj[MAXN << 1];
void addedge(int from, int to, int id, LL w)
{
    adj[++nume] = (Adj) { head[from], to, id, w };
    head[from] = nume;
}
int lton[MAXN];
LL val[MAXN];

int siz[MAXN], son[MAXN], top[MAXN], fa[MAXN], dep[MAXN];
int ind, id[MAXN], rnk[MAXN];
void DFS1(int u, int pre)
{
    fa[u] = pre;
    siz[u] = 1;
    dep[u] = dep[pre] + 1;
    for (int i = head[u]; i != -1; i = adj[i].nex)
    {
        int v = adj[i].to, id = adj[i].id;
        if (v == pre) continue;
        lton[id] = v;
        val[v] = adj[i].w;
        DFS1(v, u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
//    printf("U: %d   siz: %d son: %d val: %lld\n", u, siz[u], son[u], val[u]);
}
void DFS2(int u, int t)
{
    top[u] = t;
    id[u] = ++ind; rnk[ind] = u;
//    printf("U: %d,   top: %d id: %d\n", u, t, id[u]);
    if (son[u]) DFS2(son[u], t); 
    for (int i = head[u]; i != -1; i = adj[i].nex)
    {
        int v = adj[i].to;
        if (v == son[u] || v == fa[u]) continue;
        DFS2(v, v);
    }
}

#define ls now << 1
#define rs now << 1 | 1
struct Segt
{
    int l, r;
    LL v;
} T[MAXN << 2];
LL merge(LL x, LL y)
{
    //if (x * y > 1e18) return 2e18
    if (x > (LL)1e18 || y > (LL)1e18 || ((double)x > 1.0e18 / (double)y)) return (LL)2e18;
    else return x * y;
}
void build(int now, int l, int r)
{
    T[now].l = l, T[now].r = r;
    if (l == r)
    {
        T[now].v = val[rnk[l]];
//        printf("T[%d] = %lld\n", l, T[now].v);
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid); build(rs, mid + 1, r);
    T[now].v = merge(T[ls].v, T[rs].v);
}
LL query(int now, int l, int r)
{
    if (T[now].l > r || T[now].r < l) return 1;
//    printf("Q : %d %d %d\n", now, l, r);
    if (l <= T[now].l && T[now].r <= r) return T[now].v;
    return merge(query(ls, l, r), query(rs, l, r));
}
void update(int now, int x, LL c)
{
    if (T[now].l > x || T[now].r < x) return;
//    printf("U : %d[%d,%d] %d %lld\n", now, T[now].l, T[now].r, x, c);
    if (T[now].l == T[now].r) return (void)(T[now].v = c);
    update(ls, x, c); update(rs, x, c);
    T[now].v = merge(T[ls].v, T[rs].v);
}
LL query_path(int x, int y)
{
//    printf("XXXXXXXXXX QUERY %d %d XXXXXXXXXX\n", x, y);
    LL ret = 1;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
//        printf("x, y : %d %d\n", x, y);
        ret = merge(ret, query(1, id[top[x]], id[x]));
        x = fa[top[x]];
    }
    if (id[x] > id[y]) swap(x, y);
//    printf("x, y : %d %d\n", x, y);
    ret = merge(ret, query(1, id[x] + 1, id[y]));
    return ret;
}
#undef ls
#undef rs

int main()
{
    n = in(), m = in();
    nume = -1;
    memset(head, -1, sizeof head);
    for (int i = 1; i < n; i ++)
    {
        int u = in(), v = in();
        LL w = in();
        addedge(u, v, i, w);
        addedge(v, u, i, w);
    }
//    puts("############ DFS FIRST ############\n");
    DFS1(1, 0);
//    puts("############ DFS SECOND ############\n");
    DFS2(1, 1);
//    puts("############ BUILD ############\n");
    build(1, 1, n);
//    for (int i = 1; i <= n; i ++) printf("%d ", rnk[i]); printf("\n");
    for (int i = 1; i <= m; i ++)
    {
        int opt = in();
        if (opt == 1)
        {
            int x = in(), y = in(); LL X = in();
            printf("%lld\n", X / query_path(x, y));
        }
        else
        {
            int u = in(); LL c = in();
//            printf("update lton : %d\n", lton[u]);
            update(1, id[lton[u]], c);
            val[lton[u]] = c;
        }
//        printf("Now queue: "); for (int j = 1; j <= n; j ++) printf("%lld ", query(1, j, j)); printf("\n");
    }
    return 0;
}


