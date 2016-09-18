#include <iostream>
#include <stdio.h>
#include <utility>
#include <climits>
#include <iomanip>
#include <cmath>
#include <algorithm>

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
//-----Template---------
int n,k;
int w[10001];
int v[10001];
double memo[10001];
bool C(double mid){
    for (int i = 0; i < n; ++i) {
        memo[i]=v[i]-mid*w[i];
    }
    sort(memo,memo+n,std::greater<double>());
    double sum=0;
    for (int i = 0; i < k; ++i) {
        sum+=memo[i];
    }
    return sum>=0;
}

int main() {
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&w[i],&v[i]);
    }
    double lb=0,ub=1000001;
    for(int i=0;i<100;i++){
        double mid=(lb+ub)/2;
        if(C(mid)){
            lb=mid;
        }else{
            ub=mid;
        }
    }
    printf("%.2lf\n", lb);
}