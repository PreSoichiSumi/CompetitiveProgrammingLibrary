#include <iostream>
#include <climits>
#include <array>
#include <cmath>
#include <vector>
#include <queue>

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
int n;
int a[1001];
int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        dp[i]=INF;
    }
    dp[0]=a[0];     //dp[i]：長さi+1の部分増加列の最大値　の最小値
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(j==0){
                chmin(dp[0],a[i]);
            }else if(dp[j-1]<a[i]){
                chmin(dp[j],a[i]);
            }
        }
    }
    int res=1;
    for (int i = 0; i < n; ++i) {
        if(dp[i]!=INF)res=i+1;
    }
    cout<<res<<endl;

}