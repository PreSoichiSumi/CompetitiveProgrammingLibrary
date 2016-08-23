struct edge {   //structとclassの違いは，メンバが初期状態でpublicとなっているかprivateとなっているか
    edge(LL to, LL cost) : to(to), cost(cost) {}

    LL to, cost;
};

class Dijkstra {
public:
    vector<edge> *graph;
    LL N;

    Dijkstra(LL N, vector<edge> *graph) : graph(graph), N(N) {}

    vector<LL> adjListDijkstra(int start) { //初期化なしで何回も実行できる．O( |N|log|E| )

        LL dist[N];
        fill(dist,dist+N,INF);  //begin(dist)と書けるはずだったんだけどなあ

        priority_queue<P, vector<P>, greater<P>> que;   //<型，PQueueに使うコンテナ，比較>．　<型>もある

        dist[start] = 0;
        que.push(P(0, start));
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
