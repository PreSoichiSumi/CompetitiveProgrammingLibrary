#include <iostream>
#include <stdio.h>
#include <utility>
#include <climits>
#include <iomanip>
#include <cmath>

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
double l[10000];

bool isCreatable(double mid){
    int counter=0;
    for (int i = 0; i < n; ++i) {
        counter+=l[i]/mid;
        if(counter>=k)
            return true;
    }
    return false;
}

int main() {
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; ++i) {
        scanf("%lf",&l[i]);
    }
    double lb=0,ub=INF;//lbを条件を満たさない値に，ubを条件を満たす値に初期化し，解の存在範囲が十分小さくなるまで繰り返す
    for(int i=0;i<100;i++){
        double mid=(lb+ub)/2;
        if(!isCreatable(mid)){
            ub=mid;
        }else{
            lb=mid;
        }
    }
    printf("%.2f\n", floor(ub * 100) / 100);
}