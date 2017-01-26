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
const int INF = INT_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
/*const int MAXN = 100001;

struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};


//-----Template---------

char maze[51][51];
int r, c;
int sx, sy;
int gx, gy;

int d[51][51];

int bfs() {
    queue<P> que;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            d[i][j] = INF;
        }
    }
    que.push(P(sy, sx));
    d[sy][sx] = 0;
    while (que.size()) {
        P &p = que.front();
        que.pop();
        if (p.first == gy && p.second == gx)break;

        for (int i = 0; i < 4; ++i) {
            int ny = p.first + dx[i], nx = p.second + dy[i];
            if (0 <= ny && ny < r && 0 <= nx && nx < c
                && maze[ny][nx] != '#' && d[ny][nx] == INF){
                que.push(P(ny,nx));
                d[ny][nx]=d[p.first][p.second]+1;
            }
        }
    }
    return d[gy][gx];
}

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    //cout<<setw(4)<<setfill('0')<<"hoge"<<endl;
    cin >> r >> c;
    cin>>sy>>sx; sx--; sy--;
    cin>>gy>>gx; gy--; gx--;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin>>maze[i][j];
        }
    }
    cout<<bfs()<<endl;
}