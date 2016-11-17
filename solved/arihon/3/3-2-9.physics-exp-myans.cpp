
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define MODULE 1000000007
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second


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
int c;
double g = 10;
int n, h, r, t;    //ball height diameter time
int main() {
    //ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    scanf("%d", &c);
    for (int i = 0; i < c; ++i) {
        scanf("%d%d%d%d", &n, &h, &r, &t);

        vector<double> positions;
        for (int j = 0; j < n; j++) {
            double t1 = t - j;
            if (t1 < 0) {
                positions.push_back(h);
                continue;
            }
            double t0 = sqrt(2 * h / g);
            int x = (int) (t1 / t0);
            double t_rem = t1 - t0 * x;
            if (x % 2 == 0) {//下

                double x2 = h - g / 2 * t_rem * t_rem;
                positions.push_back(x2);
            } else {  //上
                double x2 = sqrt(2*g*h)*t_rem-g/2*t_rem*t_rem;//h - g * (x * t0 + t0 - t1) * (x * t0 + t0 - t1)/2;
                positions.push_back(x2);
            }
        }
        sort(ALL(positions));
        for (int j = 0; j < positions.size(); ++j) {
            printf("%.2f%c", positions[j] + 2 * r * j / 100.0, j + 1 == n ? '\n' : ' ');
            /*if(j!=n-1)
                printf(" ");*/
        }
        positions.clear();
        //printf("\n");
    }
}