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

LL modPow(LL x, LL y, LL mod) {
    LL res = 1;
    for (int i = 0; i < y; i++) {
        res = (res * x) % mod;
    }
    return res;
}

int memo[100001];
int n;

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        memo[tmp]++;
    }
    bool flag = true;
    LL res = 0;
    if (n % 2 == 0) {//1,3,5..n-1
        for (int i = 0; i < n; i++) {//0 to n-1
            if (i % 2 == 0){
                if(memo[i] != 0) {
                    flag = false;
                    break;
                }
            } else{
                if (memo[i] != 2) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            res = modPow(2, n / 2, MODULE);
    } else {
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                if (i == 0){
                    if(memo[0] != 1) {
                        flag = false;
                        break;
                    }
                } else {
                    if(memo[i]!=2){
                        flag=false;
                        break;
                    }
                }
            } else {
                if(memo[i]!=0){
                    flag=false;
                    break;
                }
            }
        }
        if (flag)
            res = modPow(2, (n - 1) / 2, MODULE);
    }
    cout << (flag ? res : 0) << endl;
}