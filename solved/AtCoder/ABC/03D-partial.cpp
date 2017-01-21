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
#define CONTAINS(x, y) (x.find(y)!=x.end()) //x<T1,T2>, T1 y
#define getPair(x) MP(x->first,x->second)

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
const int hogeeeeee = INT_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
/*const int MAXN = 100001;

struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/

//-----Template---------
LL nfact[1001];
LL nInvFact[1001];

LL R, C, X, Y, D, L;

LL mod_pow(LL x, LL k, LL mod) {
    LL ret = 1;
    while (k) {
        if (k & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return ret;
}

//a^-1を求める
LL inv_mod(LL a, LL p) {
    return mod_pow(a, p - 2, p);
}

LL comb_mod(LL n, LL r, LL mod) {
    LL fac = 1;
    nfact[0] = 1;
    nInvFact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac *= i;
        fac %= mod;
        nfact[i] = fac;
        nInvFact[i] = inv_mod(fac, mod); //fac^-1
    }
    LL res = 1;
    res *= nfact[n];
    res %= mod;

    res *= nInvFact[n - r];
    res %= mod;

    res *= nInvFact[r];
    res %= mod;

    return res;
}


int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    //cout<<setw(4)<<setfill('0')<<"hoge"<<endl;
    cin >> R >> C;
    cin >> X >> Y;
    cin >> D >> L;
    //assert(X * Y == D + L);

    LL res = comb_mod(X * Y, D, MODULE) * comb_mod(X * Y - D, L, MODULE);
    res %= MODULE;
    res *= (R - X + 1) * (C - Y + 1);
    res %= MODULE;

    cout << res << endl;

}