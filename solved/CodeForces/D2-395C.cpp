#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

#define MODULE 1000000007
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define CONTAINS(x, y) (x.find(y)!=x.end()) //x<T1,T2>, T1 y
#define getPair(x) MP(x->first,x->second)

template<class T, class U>
inline void chmin(T &t, U f) { if (t > f)t = f; }

template<class T, class U>
inline void chmax(T &t, U f) { if (t < f)t = f; }

template<typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val) { //usage: int dp[10][10]; Fill(dp,INF);
    std::fill((T *) array, (T *) (array + N), val);
}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;
//int_max->2*e+9 LLの時はLLONG_MAX
/*const int MAXN = 100001;

struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/

//-----Template---------
int n;
int u, v;
vector<vector<int>> graph;
bool used[100001];
int color[100001];
vector<P> edgememo;
map<int, vector<int>> newgraph;//ufの根，とufの根のvector
map<int, vector<P>> ngraphmemo;
//------UnionFind---------
//辺が貼られててiroが同じのをめも
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

//--------------
UnionFind uf(100001);

void dfs(int x) {
    used[x] = true;
    for (int i = 0; i < graph[x].size(); ++i) {
        vector<int> &target = graph[x];
        if (!used[target[i]]) {
            if (color[x] == color[target[i]]) {
                uf.unite(x, target[i]);
            } else {
                edgememo.push_back(MP(x, target[i]));//片方だけ
            }
            dfs(target[i]);
        }
    }
}

pair<bool,int> rescheck(int ufind){
    int res=ngraphmemo[ufind][0].first;
    for(int i=1;i<ngraphmemo[ufind].size();i++){
        if(ngraphmemo[ufind][i].first != res){
            return MP(false,0);
        }
    }
    return MP(true,res);
}

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    //cout<<setw(4)<<setfill('0')<<"hoge"<<endl;
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        cin >> color[i];
    }
    dfs(0);

    if(edgememo.size()==0){
        cout<<"Yes"<<endl;
        cout<<0<<endl;
        return 0;
    }


    for (int i = 0; i < edgememo.size(); ++i) {
        assert(uf.root(edgememo[i].first) != uf.root(edgememo[i].second));
        newgraph[uf.root(edgememo[i].first)].push_back(uf.root(edgememo[i].second));
        newgraph[uf.root(edgememo[i].second)].push_back(uf.root(edgememo[i].first));
        ngraphmemo[uf.root(edgememo[i].first)].push_back(MP(edgememo[i].first,edgememo[i].second));
        ngraphmemo[uf.root(edgememo[i].second)].push_back(MP(edgememo[i].second,edgememo[i].first));
    }

    bool f = false;
    int res=0;
    int elements=newgraph.size();
    for (auto it = newgraph.begin(); it != newgraph.end(); it++) {
        if(it->second.size()==elements-1){
            pair<bool,int> p=rescheck(it->first);
            if(p.first){
                f=true;
                res=p.second;
            }
        }
    }
    if(f){
        cout<<"YES"<<endl;
        cout<<res+1<<endl;
    }else {
        cout << "NO"<<endl;
    }

}