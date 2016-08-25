#include <iostream>
#include <climits>
#include <array>
#include <cmath>
#include <vector>
#include <queue>
#include <set>

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
const int MAXN = 100001;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

struct edge {   //structとclassの違いは，メンバが初期状態でpublicとなっているかprivateとなっているか
    edge(int to, int cost) : to(to), cost(cost) {}

    int to, cost;
};

vector<edge> graph[MAXN];

//-----Template---------

int n, m, k;
int u, v, l;
set<int> storages;
int tmpStorage;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> l;
        u--;
        v--;
        graph[u].push_back(edge(v, l));
        graph[v].push_back(edge(u, l));
    }
    if (k > 0) {
        for (int i = 0; i < k; ++i) {
            cin >> tmpStorage;
            tmpStorage--;
            storages.insert(tmpStorage);
        }
        int min = INF;
        for (int i = 0; i < n; ++i) {
            auto itr = storages.find(i);
            if (itr != storages.end()) //storageなら飛ばす
                continue;
            for (int j = 0; j < graph[i].size(); ++j) {
                if (storages.find(graph[i][j].to) != storages.end())//行き先がstorageならコストを比較
                    chmin(min, graph[i][j].cost);
            }
        }
        int res = min == INF ?
                  -1 : min;
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}