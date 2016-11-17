#include <climits>
#include <utility>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
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
const int INF = INT_MAX / 2;    //int_max->2*e+9
/*const int MAXN = 100001;

struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/

//-----Template---------
const double g = 10.0;

int n, h, r, t, c;
double y[101];

double calc(int T) {
    if (T < 0)return h;
    double t = sqrt(2 * h / g);
    int k = (int) (T / t);
    if (k % 2 == 0) {
        double d = T - k * t;
        return h - g * d * d / 2;
    } else {
        double d = k * t + t - T;
        return h - g * d * d / 2;
    }
}

int main() {
    scanf("%d", &c);
    for (int i = 0; i < c; ++i) {
        scanf("%d%d%d%d", &n, &h, &r, &t);
        for (int j = 0; j < n; ++j) {
            y[j] = calc(t - j);
        }
        sort(y, y + n);
        for (int j = 0; j < n; ++j) {
            printf("%.2f%c", y[j] + 2 * r * j / 100.0, j + 1 == n ? '\n' : ' ');
        }
    }
}