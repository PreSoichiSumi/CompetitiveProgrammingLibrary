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
int num[7];
double dp[101][70][70][70];//dp[n][i][j][k]:=さいころをn回振って2がi，3がj，5がk回でる確率
LL n, d;

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin >> n >> d;
    while (d % 2 == 0) {
        num[2]++;
        d /= 2;
    }
    while (d % 3 == 0) {
        num[3]++;
        d /= 3;
    }
    while (d % 5 == 0) {
        num[5]++;
        d /= 5;
    }

    if (d > 1) {
        cout << 0 << endl;
        return 0;
    }


    dp[0][0][0][0] = 1;


    for (int kaisu = 0; kaisu < n; kaisu++) {
        for (int i = 0; i < 70; i++) {
            for (int j = 0; j < 70; j++) {
                for (int k = 0; k < 70; k++) {
                    if (dp[kaisu][i][j][k] == 0)
                        continue;
                    dp[kaisu + 1][i][j][k] += dp[kaisu][i][j][k] / 6.0;
                    dp[kaisu + 1][min(i + 1, 69)][j][k] += dp[kaisu][i][j][k] / 6.0;
                    dp[kaisu + 1][i][min(j + 1, 69)][k] += dp[kaisu][i][j][k] / 6.0;
                    dp[kaisu + 1][min(i + 2, 69)][j][k] += dp[kaisu][i][j][k] / 6.0;
                    dp[kaisu + 1][i][j][min(k + 1, 69)] += dp[kaisu][i][j][k] / 6.0;
                    dp[kaisu + 1][min(i + 1, 69)][min(j + 1, 69)][k] += dp[kaisu][i][j][k] / 6.0;
                }
            }
        }
    }
    double res = 0;
    for (int i = num[2]; i < 70; i++) {
        for (int j = num[3]; j < 70; j++) {
            for (int k = num[5]; k < 70; k++) {
                res += dp[n][i][j][k];
            }
        }
    }
    cout << res << endl;
}