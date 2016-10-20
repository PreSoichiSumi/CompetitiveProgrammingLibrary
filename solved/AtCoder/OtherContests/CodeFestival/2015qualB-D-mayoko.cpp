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
const LL INFINF = 1LL << 60;//LONG_MAX/2;
//int_max->2*e+9
//const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/

//-----Template---------
LL n, tmpS, tmpC;
set<pair<LL, LL> > memo;   //範囲の開始と，次の白をメモ
vector<LL> ans;
LL oriS;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    scanf("%ld", &n);
    //cin>>n;
    memo.insert(MP(-1, -2));
    memo.insert(MP(2 * INFINF, INFINF));
    for (int i = 0; i < n; ++i) {
        scanf("%ld%ld", &tmpS, &tmpC);
        //cin>>tmpS>>tmpC;
        oriS = tmpS;
        {
            auto ss = memo.lower_bound(MP(tmpS, 0));
            if (tmpS >= ss->second) {
                tmpC += ss->first - ss->second + 1;
                tmpS = oriS = ss->second;
                memo.erase(ss);
            }
        }
        while (tmpC) {
            auto ss = memo.lower_bound(MP(tmpS, 0));
            if (tmpS + tmpC - 1 == ss->second - 1) {
                ans.push_back(tmpS + tmpC - 1);
                pair<LL, LL> p(ss->first, oriS);
                memo.erase(ss);
                memo.insert(p);
                break;
            } else if (tmpS + tmpC - 1 < ss->second - 1) {
                ans.push_back(tmpS + tmpC - 1);
                pair<LL, LL> p(tmpS + tmpC - 1, oriS);
                memo.insert(p);
                break;
            } else {
                tmpC -= ss->second - tmpS;
                tmpS = ss->first + 1;
                memo.erase(ss);
            }
        }
    }
    for (LL po:ans) {
        cout << po << endl;
    }
    return 0;
}