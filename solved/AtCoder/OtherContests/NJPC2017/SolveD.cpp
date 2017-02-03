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
int n, m, k;
vector<vector<int>> res;
bool swapped = false;

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    //cout<<setw(4)<<setfill('0')<<"hoge"<<endl;
    cin >> n >> m >> k;
    if (n > m) {
        int tmp = n;
        n = m;
        m = tmp;
        swapped = true;
    }
    res.resize(n);
    int index = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res[i].push_back(index++);
        }
    }

    int tmpk = k;

    if(tmpk>=n*(n-1)*m/2){
        reverse(res.begin(),res.end());
        tmpk-=n*(n-1)*m/2;
    }else {
        for (int i = 0; i < n - 1; ++i) {//最終行を入れる場所
            int tmpsub = (n - i - 1) * m;
            /*if (tmpk - tmpsub < 0) {
                int diff = tmpk / m;
                if (diff > 0) {
                    auto itbegin = res.rbegin();
                    auto itend = res.rbegin() + 1 + diff; //+1:end分、diff:進めたい分
                    rotate(itbegin, itbegin + 1, itend);
                }

                break;
            }*/
            if(tmpk<tmpsub)
                continue;
            tmpk -= tmpsub;

            auto itbegin = res.rbegin();
            auto itend = res.rend() - i;
            rotate(itbegin, itbegin + 1, itend);
        }
    }
    for (int i = 0; i < n; ++i) {
        if(tmpk==0)
            break;
        if(tmpk>=(m-1)*m/2) { // 行で作れる最大の転倒数以上なら   sum:1..n = n(n+1)/2
            reverse(res[i].begin(),res[i].end());
            tmpk-=(m-1)*m/2;
        }else{
            for (int j = 0; j < m-1; ++j) {//挿入先
                if(m-1-j<=tmpk) {
                    rotate(res[i].rbegin(), res[i].rbegin() + 1,res[i].rbegin()+m-j);
                    tmpk -= m-1-j;
                }
            }
        }

    }
    assert(tmpk==0);
    if(swapped) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout<<res[j][i];
                if(j!=n-1)
                    cout<<" ";
            }
            cout<<endl;
        }
    }else{
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout<<res[i][j];
                if(j!=m-1)
                    cout<<" ";
            }
            cout<<endl;
        }
    }

}