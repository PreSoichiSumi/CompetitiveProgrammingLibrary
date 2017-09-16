//#include <bits/stdc++.h>
#include <algorithm>
#include <climits>
#include <ios>
#include <iostream>
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

bool checkNoko() {

}

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    int A, B, C, D, E, F;
    double maxRate = -1;
    int maxSugWat = 0;
    int maxSug = 0;
    cin >> A >> B >> C >> D >> E >> F;

    for (int i = 1; 100 * A * i <= F; i++) {
        int wA = 100 * A * i;
        int rem1 = F - wA;
        for (int j = 0; 100 * B * j <= rem1; j++) { //重さ超えないように
            int wB = 100 * B * j;
            int rem2 = rem1 - wB;

            int sugerLim = (A * i + B * j) * E; //溶け残らない最大の量

            if (wA + wB + sugerLim > F) //そこまで入れると重さを超えるなら
                sugerLim = F - wA - wB;


            for (int k = 0; C * k <= sugerLim; k++) { //砂糖が溶け残らない間
                int wC = C * k;

                //D
                int l = (sugerLim-wC) / D;

                int suger = wC + D * l;
                int allWeight = wA + wB + wC + D * l;

                if (allWeight == 0)
                    continue;
                if(wA+wB<suger)
                    continue;

                double tmp = (double) suger / (double) allWeight;
                if (maxRate < tmp) {
                    maxRate = tmp;
                    maxSugWat = allWeight;
                    maxSug = suger;
                }

            }
        }
    }

    cout << maxSugWat << " " << maxSug << endl;
}