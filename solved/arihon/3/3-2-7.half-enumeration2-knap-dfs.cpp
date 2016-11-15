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

template<typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val) { //usage: int dp[10][10]; Fill(dp,INF);
    std::fill((T *) array, (T *) (array + N), val);
}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
/*const int MAXN = 100001;

struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/

//-----Template---------
int n, W;
LL w[50];
LL v[50];
vector<pair<LL, LL>> halfEnum1;
vector<pair<LL, LL>> halfEnum2;

void dfs1(int i, LL wei, LL val) {
    if (i == (n / 2 + 1)) {
        halfEnum1.push_back(MP(wei, val));
        return;
    }
    dfs1(i + 1, wei, val);
    dfs1(i + 1, wei + w[i], val + v[i]);
}

void dfs2(int i, LL wei, LL val) {
    if (i == n) {
        halfEnum2.push_back(MP(wei, val));
        return;
    }
    dfs2(i + 1, wei, val);
    dfs2(i + 1, wei + w[i], val + v[i]);
}

void modifEnum(vector<pair<LL, LL>> &en) {
    vector<pair<LL, LL>> resEnum;

    LL preV = en[0].second;
    resEnum.push_back(en[0]);
    for (int i = 1; i < en.size(); ++i) {
        if (preV < en[i].second) {
            resEnum.push_back(en[i]);
            preV = en[i].second;
        }
    }
    en = resEnum;
}

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> n >> W;
    for (int i = 0; i < n; ++i) { cin >> w[i]; }
    for (int i = 0; i < n; ++i) { cin >> v[i]; }
    dfs1(0, 0, 0);
    dfs2(n / 2 + 1, 0, 0);//4以上なら半分全 列挙にしようかな
    sort(halfEnum1.begin(), halfEnum1.end());
    modifEnum(halfEnum1);

    sort(halfEnum2.begin(), halfEnum2.end());
    modifEnum(halfEnum2);

    LL res = 0;
    for (int i = 0; i < halfEnum2.size(); ++i) {
        pair<LL, LL> tmpP = halfEnum2[i];
        LL tmpW = tmpP.first;
        LL tmpV = tmpP.second;
        if (tmpW <= W) {
            //chmax(res,tmpV); その必要は無いわ
            //同じ重さでも最大の価値をとりたいので，W-tmpWの次の重さのitを取得し，-1する
            auto it = lower_bound(halfEnum1.begin(), halfEnum1.end(),
                                  static_cast<pair<LL, LL>>(make_pair(W - tmpW, INF))) - 1;
            chmax(res, tmpV + it->second);
        }
    }
    cout << res << endl;
    return 0;
}