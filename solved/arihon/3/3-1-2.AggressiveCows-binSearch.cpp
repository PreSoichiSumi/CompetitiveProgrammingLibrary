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
int n,m;
int l[100000];

bool C(int mid){
    int counter=1;
    int nowPos=l[0];
    for (int i = 1; i < n; ++i) {
        if(l[i]>=(nowPos+mid)) {//mid以上離れているなら
            counter++;
            nowPos=l[i];//ここで判定してreturnしてもいい
        }
    }
    return counter>=m;
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&l[i]);
    }
    sort(l,l+n);
    int lb=0,ub=INF;//lbを条件を満たさない値に，ubを条件を満たす値に初期化し，解の存在範囲が十分小さくなるまで繰り返す
    while(ub-lb>1){
        int mid=(lb+ub)/2;
        if(C(mid)){ //全ての牛の感覚をmid以上にできる
            lb=mid;
        }else{
            ub=mid;
        }
    }
    printf("%d\n", lb);
}