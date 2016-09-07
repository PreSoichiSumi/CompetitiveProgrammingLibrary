#include <climits>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

template<class T, class U>
inline void chmin(T &t, U f) { if (t > f)t = f; }

template<class T, class U>
inline void chmax(T &t, U f) { if (t < f)t = f; }

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 1001;

struct edge {   //structとclassの違いは，メンバが初期状態でpublicとなっているかprivateとなっているか
    edge() {}

    edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
    int from, to, cost;
};
struct UnionFind {
    vector<int> data;

    UnionFind(int size) : data(size, -1) {}

    bool unite(int x, int y) {   //併合
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }

    bool isSame(int x, int y) {    //同じ集合か判定
        return root(x) == root(y);
    }

    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    int size(int x) {
        return -data[root(x)];
    }
};


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
//-----Template---------

bool comp(const edge& e1,const edge& e2){
    return e1.cost<e2.cost;
}
#define MAXE 50000
edge es[MAXE+1];
int V,E;
int kruskal(){
    sort(es,es+E,comp);
    UnionFind uf(V);
    int res=0;
    for (int i = 0; i < E; ++i) {
        edge e= es[i];
        if(!uf.isSame(e.from, e.to)){
            uf.unite(e.from,e.to);
            res+=e.cost;
        }
    }
    return res;
}
//------
LL testcase;
LL n, m, r, tmpA, tmpB, tmpCost;
vector<LL> res;
int main() {
    scanf("%d",&testcase);
    for (int j = 0; j < testcase; ++j) {
        scanf("%d %d %d",&n,&m,&r);
        V = n + m;
        E = r;
        for (int i = 0; i < r; i++) {
            scanf("%d %d %d",&tmpA,&tmpB,&tmpCost);
            es[i] = edge(tmpA, tmpB + n, -tmpCost);
        }
        res.push_back(10000*(n+m)+kruskal());
    }
    for (int i = 0; i < testcase; ++i) {
        printf("%d\n",res[i]);
    }
}