#include <bits/stdc++.h>

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

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
//-----Template---------

LL n, k;
LL dp[1000003];
LL sum[1000003];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    dp[0] = sum[0] = 1;
    dp[1] = 0;
    sum[1] = 1;
    for (int i = 2; i <= n + 1; ++i) {
        if (i != 1 && i != n) dp[i] = (sum[i - 1] - (i - 1 - k >= 0 ? sum[i - 1 - k] : 0) + MODULE) % MODULE;
        sum[i] = (dp[i] + sum[i - 1]) % MODULE;
    }
    cout << dp[n + 1] << endl;
    return 0;
}