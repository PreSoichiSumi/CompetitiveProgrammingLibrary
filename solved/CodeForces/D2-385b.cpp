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
int n, m;
char grid[501][501];

bool isValid(int x,int y){
    return 0<=x && x<n && 0<=y && y<m;
}

bool isRect(int x, int y) {
    int nowX=x;
    int nowY=y;
    int recEndX;
    int recEndY;

    while(isValid(nowX,nowY) && grid[nowX][nowY]=='X'){ //ここを抜けたらxでないか端
        nowX++;
    }
    recEndX=nowX;


    nowX=x;
    nowY=y;
    while(isValid(nowX,nowY) && grid[nowX][nowY]=='X'){
        nowY++;
    }
    recEndY=nowY;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(x<=i && i<recEndX && y<=j && j<recEndY){
                if(grid[i][j]!='X')
                    return false;
            }else{
                if(grid[i][j]!='.')
                    return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }


    bool flag = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'X') {
                flag = isRect(i, j);
                goto en;
            }
        }
    }

    en:
    cout << (flag ? "YES" : "NO") << endl;
}