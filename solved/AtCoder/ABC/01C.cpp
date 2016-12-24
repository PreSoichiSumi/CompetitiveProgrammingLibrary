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
int deg;
int dist;

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> deg >> dist;

    string dir;
    {
        int numArr[] = {1125, 3375, 5625, 7875, 10125,
                        12375, 14626, 16875, 19125, 21375,
                        23625, 25875, 28125, 30375, 32625,
                        34875};
        string resArr[] = {"NNE","NE","ENE","E","ESE",
                           "SE","SSE","S","SSW","SW",
                           "WSW","W","WNW","NW","NNW"};
        deg *= 10;
        if (deg < numArr[0] || numArr[15] <= deg) {
            dir = "N";
        } else{
            for (int i = 0; i < 15; ++i) {
                if(numArr[i]<=deg && deg<numArr[i+1]){
                    dir=resArr[i];
                    break;
                }
            }
        }
    }


    int p;
    {
        int comparr[] = {15, 93, 201, 327, 477, 645, 831, 1029, 1245, 1467, 1707, 1959};
        p = -1;
        for (int i = 0; i < 12; ++i) {
            if (dist < comparr[i]) {
                p = i;
                break;
            }
        }
        if (p == -1)
            p = 12;
    }
    if (p == 0)
        dir = "C";

    cout << dir << " " << p << endl;
}