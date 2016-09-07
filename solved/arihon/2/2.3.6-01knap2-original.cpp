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
int dp[101][100*100+1];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cin >> W;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 100*100+1; ++j) {
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    for (int i = 1; i <= n; ++i) {       //iまでの品物   v,wのindexは0から始まるので，dp[i+1][j]を更新するように書いたほうがきれい
        for (int j = 0; j < 100*100+1; ++j) { //価値
            if(j-v[i-1]<0) {
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=min(dp[i-1][j-v[i-1]]+w[i-1],dp[i-1][j]);
            }
        }
    }
    int res=0;
    for(int i=0;i<100*100+1;i++)
        if(dp[n][i]<=W)res=i;

    cout << res << endl;

    return 0;
}