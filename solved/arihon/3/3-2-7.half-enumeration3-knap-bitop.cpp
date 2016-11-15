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
LL INF = LLONG_MAX/ 2;    //int_max->2*e+9 LLの時はLLONG_MAX
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

vector<pair<LL, LL>> half1;

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> n >> W;
    for (int i = 0; i < n; ++i) { cin >> w[i]; }
    for (int i = 0; i < n; ++i) { cin >> v[i]; }
    //最初を全列挙
    int n2=n/2;
    for (int i = 0; i < 1<<n2; ++i) {
        int tmpW1=0,tmpV1=0;
        for (int j = 0; j < n2; ++j) {
            if(i>>j & 1){
                tmpW1+=w[j];
                tmpV1+=v[j];
            }
        }
        half1.push_back(MP(tmpW1,tmpV1));
    }
    {
        sort(half1.begin(), half1.end());
        vector<pair<LL, LL>> res;
        res.push_back(half1[0]);
        LL preW1=half1[0].first, preV1=half1[0].second;
        for (int i = 1; i < half1.size(); ++i) {
            if(preV1<half1[i].second){
                res.push_back(half1[i]);
            }
        }
        half1=res;
    }

    LL res=0;
    for (int i = 0; i < 1 << n - n2; ++i) {
        LL tmpW2=0,tmpV2=0;
        for (int j = 0; j <n-n2 ; ++j) {
            if(i>>j&1){
                tmpW2+=w[n2+j];
                tmpV2+=v[n2+j];
            }
        }
        auto it=lower_bound(half1.begin(),half1.end(),MP(W-tmpW2,INF))-1;
        LL tmpV1=it->second;
        chmax(res,tmpV1+tmpV2);
    }
    cout << res << endl;
    return 0;
}