#include <climits>
#include <utility>
#include <vector>
#include <cstdio>
#include <iostream>
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
//const int INF = INT_MAX / 2;    //int_max->2*e+9
const double INF= 1000000000;
/*const int MAXN = 100001;

struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/

//-----Template---------
int n, m, p, a, b;

int d[31][31];
int t[10];

//dp[S][v] := Sの各チケットを未使用の状態で都市vにたどり着く最短距離
//dp[i][j]:iの乗車券が残っておりjにいる状態でゴールまで行く最小コスト
double dp[(1 << 10) - 1][31];

int main() {
    while (true) {
        scanf(" %d %d %d %d %d", &n, &m, &p, &a, &b);
        if (n == 0 && m == 0 && p == 0 && a == 0 && b == 0)  //if((n || m || p || a || b) == 0) break; koresuki
            break;
        a--;
        b--;

        Fill(d, -1);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &t[i]);
        }

        Fill(dp, INF);

        for (int i = 0; i < p; ++i) {
            int from, to, cost;
            scanf(" %d %d %d", &from, &to, &cost);
            from--;
            to--;
            d[from][to] = cost;
            d[to][from]=cost;
        }
        dp[(1 << n) - 1][a] = 0;
        double res = INF;
        for (int s = (1 << n) - 1; s >= 0; --s) {//各チケット枚数について
            chmin(res, dp[s][b]);
            for (int v = 0; v < m; ++v) {   //各都市について
                for (int i = 0; i < n; ++i) {//チケットiを使う
                    if ((s >> i) & 1) { //iをまだ使ってないなら
                        for (int u = 0; u < m; ++u) {//vから出る全ての道について
                            if (d[v][u] >= 0) { //道があるなら
                                //chmin(dp[s&~(1<<i)][u],dp[s][v]+(double)d[v][u]/t[i]);
                                dp[s & ~(1 << i)][u] = min(dp[s & ~(1 << i)][u], dp[s][v] + (double) d[v][u] / t[i]);
                            }
                        }
                    }
                }
               // if(v==b)res=min(res,dp[s][b]);
            }
        }
        if (res == INF) {
            printf("Impossible\n");
        } else {
            printf("%.3f\n", res);
        }
    }
}