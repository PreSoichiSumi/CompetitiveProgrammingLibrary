#include <iostream>
#include <climits>
#include <array>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

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

//参考資料
//http://utpc2012.contest.atcoder.jp/tasks/utpc2012_08
//http://kmjp.hatenablog.jp/entry/2012/12/23/1100
//http://www.utpc.jp/2012/slides/intervalQuery.pdf
int n,q,s,t;
vector<P> work;
int startTimes[100001];
vector<P> query;
int nextIndex[100001][16];
int main(){
    ios::sync_with_stdio(false);

    for (int i = 0; i < 100001; ++i) {
        for (int j = 0; j < 16; ++j) {
            nextIndex[i][j]=INF;
        }
    }
    
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>s>>t;
        work.push_back(P(t,s));//おわり，はじまり
    }
    for (int i = 0; i < q; ++i) {
        cin>>s>>t;
        query.push_back(P(s,t));//はじまり，おわり
    }

    sort(work.begin(),work.end());

    for (int i = 0; i < n; ++i) {
        startTimes[i]=work[i].second;
    }
    
    for (int i = 0; i < n; ++i) {
        auto it=lower_bound(work.begin(),work.end(),work)
    }
}