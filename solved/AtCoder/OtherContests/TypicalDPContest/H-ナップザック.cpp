#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

#define MODULE 1000000007
#define ALL(i) (i).begin(),(i).end()

template<class T, class U>
inline void chmin(T &t, U f) { if (t > f)t = f; }

template<class T, class U>
inline void chmax(T &t, U f) { if (t < f)t = f; }

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
//-----Template---------

int dp[51][10001];  //dp[i][j]:i以下の色を使って重さj以下のときの価値の総和の最大値
int dp2[51][10001];
vector<pair<int, P> > t;    //color,weight,value   →ソートして，00..11..22..という色の順番になる


int N, W, C;

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> N >> W >> C;
    for (int i = 0; i < N; ++i) {
        int w, v, c;
        cin >> w >> v >> c;
        t.push_back(make_pair(c, make_pair(w, v)));
    }
    sort(ALL(t));
    int tIndex = 0;
    int nowCol;
    while (tIndex < t.size()) {//各物
        nowCol = t[tIndex].first;

         //同様　iを必ず使う．
        for (int i = 0; i < 51; ++i)
            for (int j = 0; j < 10001; ++j)
                dp2[i][j]=0;

        while (tIndex < t.size() && t[tIndex].first == nowCol) {//ある色
            for (int i = 1; i <= C; ++i) {
                for (int j = W; j >= 0; --j) {  //全てのjを更新
                   // chmax(dp2[i][j], dp[i][j]);
                    if (j - t[tIndex].second.first >= 0) {
                        chmax(dp2[i][j], dp[i - 1][j - t[tIndex].second.first] + t[tIndex].second.second);
                        chmax(dp2[i][j], dp2[i][j - t[tIndex].second.first] + t[tIndex].second.second);
                    }
                }
            }
            tIndex++;
        }
        //dp2からdp更新
        for (int i = 1; i <= C; ++i) {
            for (int j = W; j >= 0; --j) {
                chmax(dp[i][j],dp2[i][j]);
            }
        }
    }
    cout<<dp[C][W]<<endl;
}