#include <bits/stdc++.h>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

template<class T, class U>
inline void chmin(T &t, U f) { if (t > f)t = f; }

template<class T, class U>
inline void chmax(T &t, U f) { if (t < f)t = f; }

typedef long long LL;
typedef pair<int, int> Pii;
typedef pair<LL, LL> PLL;

const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 100001;

LL makeVertex(LL a, LL b) {
    return a * ((LL)1e6+10) + b;
}

struct edge {
public:
    edge(LL vertex, LL cost) : vertex(vertex), cost(cost) {}
    bool operator<(const edge &rhs) const {
        return cost > rhs.cost;
    }

    LL vertex;  //<tyoten,company>
    LL cost;
};


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
//UnionFind解もある気がする

int n, m, tmpP, tmpQ, tmpC;

unordered_map<LL,vector<edge> > graph; // <O(M), O(M)>
unordered_map<LL,LL> distMap;  //(tyoten,com),dist

LL dijkstra(LL start,LL goal) {

    priority_queue<edge> que;   //そのままだと大きい順で出てくる

    distMap[start] = 0;
    que.push(edge(start,0));
    while (!que.empty()) {
        edge e = que.top();
        que.pop();
        LL v = e.vertex;

        if (distMap[v] < e.cost)continue;
        for (auto it=graph[v].begin();it!=graph[v].end();it++){
            edge e2=*it;
            if (distMap[e2.vertex] > distMap[v] + e2.cost) {
                distMap[e2.vertex] = distMap[v] + e2.cost;
                que.push(edge(e2.vertex,distMap[e2.vertex]));
            }
        }
    }
    return distMap[goal];
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &tmpP, &tmpQ, &tmpC);tmpP--;tmpQ--;
        graph[makeVertex(tmpP,tmpC)].push_back(edge(makeVertex(tmpQ,tmpC),0));
        graph[makeVertex(tmpQ,tmpC)].push_back(edge(makeVertex(tmpP,tmpC),0));    //各頂点をつなぐ辺は後で追加

        graph[makeVertex(tmpP,tmpC)].push_back(edge(makeVertex(tmpP,0),0));
        graph[makeVertex(tmpP,0)].push_back(edge(makeVertex(tmpP,tmpC),1));
        graph[makeVertex(tmpQ,tmpC)].push_back(edge(makeVertex(tmpQ,0),0));
        graph[makeVertex(tmpQ,0)].push_back(edge(makeVertex(tmpQ,tmpC),1));

        distMap[makeVertex(tmpP,tmpC)]=INF;
        distMap[makeVertex(tmpQ,tmpC)]=INF;
        distMap[makeVertex(tmpP,0)]=INF;
        distMap[makeVertex(tmpQ,0)]=INF;
    }

    LL res=dijkstra(makeVertex(0,0),makeVertex(n-1,0));
    cout<<((res==INF|| res==0 )?-1:res)<<endl;
    return 0;
}