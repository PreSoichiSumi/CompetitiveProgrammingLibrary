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

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;     //int_max->2*e+9
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
LL n, tmpA,ans=0;
vector<pair<int, int>> a;

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmpA;
        a.push_back(MP(tmpA, i));
    }
    sort(ALL(a));
    set<int> memo;
    memo.insert(-1);
    memo.insert(n);
    for (int i = 0; i < n; ++i) {
        auto it = memo.lower_bound(a[i].second);
        int bb = *it;
        int aa = (*(--it));
        int r = bb - a[i].second;// + (bb == n ? 0 : 1);
        int l = a[i].second - aa;// + (aa == -1 ? 0 : 1);
        ans+= 1LL*r*l*a[i].first;
        memo.insert(a[i].second);
    }
    cout<<ans<<endl;
}