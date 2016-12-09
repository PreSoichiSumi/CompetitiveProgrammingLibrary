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
const int INF = INT_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
/*const int MAXN = 100001;

struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/
//-----Template---------
int edge[20][20];
int n, m;

//dp[i][j]:iの頂点をすでに通った状態でjにいるとき，0に戻るまでにかかる最小のコスト
int dp[1 << 15][20];

int rec(int s, int v) {
    if(dp[s][v]>=0)
        return dp[s][v];

    if (s == (1 << n)-1 && v == 0)
        return dp[s][v]=0;

    int res=INF;
    for(int i=0;i<n;i++){
        if(!(s>>i&1))
            chmin(res,rec(s|1<<i,i)+edge[v][i]);
    }
    return dp[s][v]=res;
}

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        //from--; to--;
        edge[from][to] = cost;
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
}