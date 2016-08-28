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

LL n,tmp;

multiset<LL> l;

int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for (LL i = 0; i < n; ++i) {
        cin>>tmp;
        l.insert(tmp);
    }
    LL cost=0;
    while(l.size()>1){
        LL first=*l.begin();   l.erase(l.begin());
        LL second=*l.begin();    l.erase(l.begin());
        l.insert(first+second);
        cost+=first;
        cost+=second;
    }
    cout<<cost<<endl;
    return 0;
}