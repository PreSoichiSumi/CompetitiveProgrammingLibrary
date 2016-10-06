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

double dp[11][4001];
int K;
int R[4001];

double getPercent(int i, int j) {
    return 1.0 / (1.0 + pow(10, (R[j] - R[i]) / 400.0));
}


int main() {
    ios::sync_with_stdio(false); cout<< fixed << setprecision(10);
    cin >> K;
    for (int i = 0; i < 1 << K; i++) {    //1<<iで2^iになる
        cin >> R[i];
    }
    for (int i = 0; i < 1 << K; i++) {
        dp[0][i] = 1.0;
    }
    for (int k = 1; k <= K; k++) {
        for (int i = 0; i < 1 << K; i++) {   //dp[k][i]の更新を行う
            //update dp table
            //ラウンドKではk-1bit目を反転してk-2bit以下を
            //0 - 1<<(k-1)としたものが対戦相手になる．
            int base = i ^(1 << k - 1);
            base &= (0xFFFFFFFF << k - 1);
            if(k==1) {
                dp[k][i]=getPercent(i,base)*dp[k-1][base];
            }else{
                double p=0;
                for (int j = 0; j < 1 << k - 1; j++) {
                    int tmp = base | j;
                    p += getPercent(i, tmp) * dp[k-1][tmp];
                }
                dp[k][i]=p*dp[k-1][i];
            }
        }
    }
    for (int i = 0; i < 1 << K; i++) {
        cout<<dp[K][i]<<endl;
    }
}