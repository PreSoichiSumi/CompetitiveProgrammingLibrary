#include <iostream>
#include <stdio.h>
#include <utility>
#include <climits>
#include <iomanip>
#include <cmath>
#include <algorithm>

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
//-----Template---------
int n,m,M;
int dp[1001][1001];

int main() {
    scanf("%d%d%d",&n,&m,&M);
    dp[0][0]=1;
    for (int i = 1; i <=m; ++i) {
        for (int j = 0; j <=n; ++j) {
            if(j-i>=0){
                dp[i][j]=(dp[i-1][j]+dp[i][j-i])%M;
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    printf("%d\n",dp[m][n]);
}