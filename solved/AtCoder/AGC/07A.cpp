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
vector<edge> graph[MAXN];*/
int dx[2] = {0, 1};
int dy[2] = {1, 0};
//-----Template---------

int h, w;
string tmp;
char grid[10][10];
char grid2[10][10];

bool isMovable(int x, int y) {
    /*for (int i = 0; i < h; ++i) {
        int lim = i < x ? w : y;
        for (int j = 0; j < lim; ++j) {
            if (grid[i][j] == '#')
                return false;
        }
    }
    return true;*/
}

bool isValid(int x, int y) {
    return 0 <= x && x < h && 0 <= y && y < w;
}

bool passedAllGrid(){
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(grid2[i][j]=='#')
                return false;
        }
    }
    return true;
}

bool bfs(int sx, int sy, int gx, int gy) {
    std::queue<P> qu;
    qu.push(P(sx, sy));
    while (!qu.empty()) {
        P now = qu.front();
        qu.pop();
        grid2[now.first][now.second]='.';
        if (now.first == gx && now.second == gy)
            return true;

        for (int i = 0; i < 2; i++) {
            int x = now.first + dx[i];
            int y = now.second + dy[i];
            if (0 <= x && x < h && 0 <= y && y < w && grid[x][y] == '#') {
                qu.push(P(x, y));
            }
        }

        if ((isValid(now.first + 1, now.second) && (grid[now.first + 1][now.second] == '#'))
            == (isValid(now.first, now.second + 1) && (grid[now.first][now.second + 1] == '#')))
            return false;//両方イケたら終わり
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        cin >> tmp;
        for (int j = 0; j < w; ++j) {
            grid[i][j] = tmp[j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            grid2[i][j] = grid[i][j];
        }
    }
    cout << (bfs(0, 0, h - 1, w - 1)&&passedAllGrid() ? "Possible" : "Impossible") << endl;

}