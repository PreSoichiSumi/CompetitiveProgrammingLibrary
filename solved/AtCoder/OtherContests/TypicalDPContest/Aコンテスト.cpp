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

/*struct edge {   //structとclassの違いは，メンバが初期状態でpublicとなっているかprivateとなっているか
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/
//-----Template---------
int n;
int p[101];
int dp[100];
unordered_set<int> memo;
unordered_set<int> updates;
int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&p[i]);
    }
    dp[0]=2;
    memo.insert(p[0]);
    memo.insert(0);
    for (int i = 1; i < n; ++i) {
        for(int num :memo ){//メモ内の全てとの組み合わせ
            int tmp=num+p[i];
            if(memo.find(tmp)==memo.end() && updates.find(tmp)==updates.end()){
                updates.insert(tmp);
            }
        }
        dp[i]=dp[i-1]+updates.size();
        memo.insert(updates.begin(),updates.end());
        updates.clear();
    }
    printf("%d\n",dp[n-1]);
}