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

typedef pair<int, int> P;
typedef long long LL;
const LL INF = LLONG_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/

//-----Template---------
int h, w;
char color[301][301];
LL dp[301][301];
LL cost[301][301];
LL ans[301];
LL sum = 0;
string tmpS;

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        cin >> tmpS;
        for (int j = 0; j < w; ++j) {
            color[i][j] = tmpS[j];
        }
    }


    for (int i = 0; i < w - 1; ++i) {     //2列毎の最小コストを求める
        for (int j = 0; j <= h; ++j) {   //先にcostテーブルを作っておく．
            // 毎回計算するとdp更新にO(h)かかってTLE
            //cost[i][j]:i,j押されているときに
            //どちらかの列を押すコスト(2列の内どちらを押しても同じコスト)
            for (int k = 0; k <= h; ++k) {
                if (j == 0 || k == 0) {
                    LL tmp = 0;
                    for (int l = 0; l < h; ++l) {//0 .. h-1まで回して，変なとこを飛ばす
                        if (l - j >= 0 && l - k >= 0 && color[l - j][i] == color[l - k][i + 1])
                            tmp++;
                    }
                    cost[j][k] = tmp;
                } else {
                    cost[j][k] = cost[j - 1][k - 1] - (color[h - j][i] == color[h - k][i + 1] ? 1 : 0);
                }
            }
        }
        for (int j = 0; j <= h; ++j) {
            for (int k = 0; k <= h; ++k) {
                dp[j][k] = INF;
            }
        }
        dp[0][0] = 0;
        for (int j = 0; j <= h; ++j) {
            for (int k = 0; k <= h; ++k) {
                LL tmpA = j > 0 ? dp[j - 1][k] + cost[j - 1][k] : INF;
                LL tmpB = k > 0 ? dp[j][k - 1] + cost[j][k - 1] : INF;
                chmin(dp[j][k], min(tmpA, tmpB));
            }
        }
        sum += dp[h][h];
    }
    cout << sum << endl;
}