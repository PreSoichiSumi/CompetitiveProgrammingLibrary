#include <climits>
#include <utility>
#include <vector>
#include <cstdio>
#include <iostream>
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
const int INF = INT_MAX / 2;    //int_max->2*e+9
/*const int MAXN = 100001;

struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/

//-----Template---------
//segtreeは区間に対する操作を効率的に行えないので、区間に対する加算は別のsegtreeで持ち、
//クエリの際に合算する
#define MAX_N 100001
#define MAX_Q 100001
const int DAT_SIZE = (1 << 18) - 1;

int N, Q;
int A[MAX_N];
char T[MAX_Q];
int L[MAX_Q], R[MAX_Q], X[MAX_Q];

LL data[DAT_SIZE], datb[DAT_SIZE];

void add(int a, int b, int x, int k, int l, int r) {
    if (a <= l && r <= b) {
        data[k] += x;
    } else if (l < b && a < r) {
        datb[k] += (min(b, r) - max(a, l)) * x;
        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
    }
}

LL sum(int a, int b, int k, int l, int r) {
    if (b <= l || r <= a) {
        return 0;
    } else if (a <= l && r <= b) {
        return data[k] * (r - l) + datb[k];
    } else {
        LL res = (min(b, r) - max(a, l)) * data[k];
        res += sum(a, b, k * 2 + 1, l, (l + r) / 2);
        res += sum(a, b, k * 2 + 2, (l + r) / 2, r);
        return res;
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        scanf(" %d",&A[i]);//cin >> A[i];
    }
    for (int i = 0; i < Q; ++i) {
        scanf(" %c",&T[i]);//cin >> T[i];
        if (T[i] == 'C') {
            scanf(" %d%d%d",&L[i],&R[i],&X[i]);//cin >> L[i] >> R[i] >> X[i];

        } else {
            scanf(" %d%d",&L[i],&R[i]);//cin >> L[i] >> R[i];
        }
    }
    for (int i = 0; i < N; i++) {
        add(i, i + 1, A[i], 0, 0, N);
    }
    for (int i = 0; i < Q; i++) {
        if (T[i] == 'C') {
            add(L[i]-1, R[i], X[i], 0, 0, N);
        } else {
            printf("%lld\n", sum(L[i]-1, R[i], 0, 0, N));
        }
    }
}
