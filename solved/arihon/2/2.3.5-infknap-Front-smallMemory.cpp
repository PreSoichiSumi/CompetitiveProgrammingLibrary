#include <iostream>
#include <list>
#include <climits>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

template<class T, class U>
inline void chmin(T &t, U f) { if (t > f)t = f; }

template<class T, class U>
inline void chmax(T &t, U f) { if (t < f)t = f; }

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 100001;

/*struct edge {   //structとclassの違いは，メンバが初期状態でpublicとなっているかprivateとなっているか
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int n, tmpW, tmpV, W;
int w[101], v[101];
int dp[10001];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cin >> W;

    for (int j = 0; j < W + 1; ++j) {
        dp[j] = 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = w[i]; j <= W; ++j) {	//前と同じか，変わるとしたらj=w[i]以降のため

            if(j-w[i]<0) {
                dp[j]=dp[j];
            }else{
                dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
            }

        }
    }
    cout << dp[W] << endl;

    return 0;
}