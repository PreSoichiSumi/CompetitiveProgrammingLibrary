//-Dijkstra--

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

//---Bellman-Ford--O(VE)--------------
#define MAXE 10001
#define MAXV 10001
struct edge{int from,to,cost};
edge es[MAXE];
int d[MAXV];
int V,E;
void shortest_path(int s){
    for(int i=0;i<V;i++)d[i]=INF;
    d[s]=0;
    while (true){
        bool update=false;
        for (int i = 0; i < E; ++i) {
            edge e=es[i];
            if(d[e.from]!=INF && d[e.to]>d[e.from] +e.cost){
                d[e.to]=d[e.from] +e.cost;
                update = true;
            }
        }
        if(!update)break;
    }
}

bool findNegativeLoop(){
    memset(d,0, sizeof(d));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < E; ++j) {
            edge e=es[j];
            if(d[e.to]>d[e.from]+e.cost)
                d[e.to]=d[e.from]+e.cost;
            if(i==V-1)return true;
        }
    }
    return false;
}
//------------

///---warshal floid---------
#define MAXV 10001
int d[MAXV][MAXV];  //存在しないならINF,d[i][i]=0
int V;

void warshallFloid(){
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
//--------------------


//----prim-------------------
#define MAXV 1001
int cost[MAXV][MAXV];
int mincost[MAXV];
bool used[MAXV];
int V;
int prim(){
    for (int i = 0; i < V; ++i) {
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    int res=0;
    while(true){
        int v=-1;
        for (int u = 0; u < V; ++u) {
            if(!used[u] && (v==-1 || mincost[u]<mincost[v]))v=u;
        }
        if(v==-1)break;
        used[v]=true;
        res+=mincost[v];
        for (int u = 0; u < V; ++u) {
            mincost[u]=min(mincost[u],cost[v][u]);
        }
        return res;
    }
}
//------

//-----kruskal---
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
//---------------------