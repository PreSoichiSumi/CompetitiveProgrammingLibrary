#include <iostream>
#include <climits>
#include <array>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 100001;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
struct edge {   //structとclassの違いは，メンバが初期状態でpublicとなっているかprivateとなっているか
    edge(LL to, LL cost) : to(to), cost(cost) {}

    LL to, cost;
};

class Dijkstra {
public:
    vector<edge> *graph;
    LL N;

    Dijkstra(LL N, vector<edge> *graph) : graph(graph), N(N) {}

    vector<LL> adjListDijkstra(int s) { //初期化なしで何回も実行できる．O( |N|log|E| )

        LL dist[N];
        fill(dist,dist+N,INF);  //begin(dist)と書けるはずだったんだけどなあ

        priority_queue<P, vector<P>, greater<P>> que;   //<型，PQueueに使うコンテナ，比較>．　<型>もある

        dist[s] = 0;
        que.push(P(0, s));
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first)continue;
            for (int i = 0; i < graph[v].size(); ++i) {
                edge e = graph[v][i];
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }
        return vector<LL>(dist,dist+N);
    }
};

LL n, m, t;
int A[MAXN];//globalは要素数const

int main() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    vector<edge> graphNormal[n];    //ローカルは要素数constでなくてもいい
    vector<edge> graphInverted[n];

    for (int i = 0; i < n; ++i) {
        graphNormal[i].push_back(edge(i, 0));
        graphInverted[i].push_back(edge(i, 0));
    }

    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        a--;
        b--;
        graphNormal[a].push_back(edge(b, c));
        graphInverted[b].push_back(edge(a, c));
    }
    Dijkstra dijkstraN(n, graphNormal);
    Dijkstra dijkstraI(n, graphInverted);

    auto distN = dijkstraN.adjListDijkstra(0);
    auto distI = dijkstraI.adjListDijkstra(0);
    for (int i = 0; i < n; ++i) {
        distN.at(i) += distI.at(i);
    }
    LL money[n];
    LL max = 0;
    for (int i = 0; i < n; ++i) {
        if (distN.at(i) >= INF || distN.at(i) >= t) { //unreachable or too many time
            money[i] = 0;
        } else {
            money[i] = (t - distN.at(i)) * A[i];
        }
        max = max < money[i] ? money[i] : max;
    }
    cout << max << endl;
    return 0;
}