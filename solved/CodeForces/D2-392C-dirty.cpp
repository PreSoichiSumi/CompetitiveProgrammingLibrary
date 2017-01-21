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
LL n, m, k, x, y;
LL loop = 0;
LL rem = 0;
LL maxNum = 0;
LL minNum = 0;
LL Sergei = 0;

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    //cout<<setw(4)<<setfill('0')<<"hoge"<<endl;
    cin >> n >> m >> k >> x >> y;
//    x--;    //0-indexed
//    y--;
    if (n > 2) {
        loop = k / (n * m + m * (n - 2));
        rem = k % (n * m + m * (n - 2));
        if (rem > 0) {
            maxNum = loop * 2;
            if (loop > 0) {
                maxNum += rem > (m) ? (rem > (n * m) ? 2 : 1) : 0;
            } else {
                maxNum += rem > 0 ? (rem > n * m ? 2 : 1) : 0;
            }
            minNum = rem >= n * m ? loop + 1 : loop;
        } else {
            maxNum = loop * 2;
            minNum = loop;
        }
        if (1 < x && x < n) {
            Sergei = loop * 2;
            if ((x - 1) * m + y <= rem) {
                if (n * m + (n - x-1) * m + y <= rem) {
                    Sergei += 2;
                } else {
                    Sergei += 1;
                }
            }
        } else {
            Sergei = loop;
            if ((x - 1) * m + y <= rem)
                Sergei++;
        }
    } else {
        loop = k / (n * m);
        rem = k % (n * m);
        maxNum = (rem > 0 ? loop + 1 : loop);
        minNum = loop;
        Sergei = (rem >= m * (x - 1) + y ? loop + 1 : loop);
    }
    cout << maxNum << " " << minNum << " " << Sergei << endl;
}