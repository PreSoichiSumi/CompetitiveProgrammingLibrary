#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

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

const int MAXN = 5001;

struct edge {   //structとclassの違いは，メンバが初期状態でpublicとなっているかprivateとなっているか
    edge(int to, int cost) : to(to), cost(cost) {}

    int to, cost;
};

vector<edge> graph[MAXN];

class Dijkstra {
public:
    vector<edge> *graph;
    LL N;

    Dijkstra(LL N, vector<edge> *graph) : graph(graph), N(N) {}

    vector<LL> adjListDijkstra(int start) { //初期化なしで何回も実行できる．O( |N|log|E| )

        LL dist[N];
        LL dist2[N];
        fill(dist, dist + N, INF);  //begin(dist)と書けるはずだったんだけどなあ
        fill(dist2, dist2 + N, INF);
        priority_queue<P, vector<P>, greater<P> > que;   //<型，PQueueに使うコンテナ，比較>．　<型>もある

        dist[start] = 0;
        que.push(P(0, start));
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;
            if (dist2[v] < p.first)continue;
            for (int i = 0; i < graph[v].size(); ++i) {
                edge e = graph[v][i];
                LL d = p.first + e.cost;
                if (dist[e.to] > d) {
                    swap(d, dist[e.to]);
                    que.push(P(dist[e.to], e.to));
                }
                if (dist2[e.to] > d) {
                    dist2[e.to] = d;
                    que.push(P(dist2[e.to], e.to));
                }
            }
        }
        return vector<LL>(dist2, dist2 + N);
    }
};

//-----Template---------
int n, r, tmpU, tmpV, cost;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> r;
    for (int i = 0; i < r; i++) {
        cin >> tmpU >> tmpV >> cost;
        tmpU--;
        tmpV--;
        graph[tmpU].push_back(edge(tmpV, cost));
        graph[tmpV].push_back(edge(tmpU, cost));
    }
    Dijkstra dijkstra(n, graph);
    vector<LL> tmp = dijkstra.adjListDijkstra(0);
    cout << tmp.at(n-1)<<endl;
}