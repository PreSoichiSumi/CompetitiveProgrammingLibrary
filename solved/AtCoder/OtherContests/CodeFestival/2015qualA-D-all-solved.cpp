#include <bits/stdc++.h>

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
#define ten(x) ((int)1e##x)
/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
LL n, m;
LL x[100001];

bool C2(LL L, LL R, LL mid) {  //l,r,mid
    return min(2 * L + R, L + 2 * R) <= mid;
}

bool C(LL mid) {//N
    LL last = 0; //1-indexed
    for (int i = 0; i < m; ++i) {
        if(x[i]-(last+1)>mid)
            return false;

        LL L = x[i] - (last + 1);
        LL lb2 = x[i];
        LL ub2 = (i+1)<m?x[i+1]:n+1;
        while (ub2 - lb2 > 1) {
            LL mid2 = (ub2 + lb2) / 2; //int+intだとオーバーフローする
            LL R=mid2-x[i];
            if (C2(L,R,mid)){
                lb2=mid2;
            }else{
                ub2=mid2;
            }
        }
        last=lb2;
        /*int tmpLast=last;
        for (int j = x[i]; j < ((i + 1) < m ? x[i + 1] : n+1); ++j) {
            int L=x[i]-(last+1);
            int R=j-x[i];
            int cost=min(2*L+R,L+2*R);
            if(cost<=mid)
                tmpLast=j;
        }
        last=tmpLast;
        if(last<x[i]-1) {//x[i-1]からx[i]までmidでは点検する事ができない
            return false;
        }*/

    }
    return last >= n;//ここ～～～～～～～
}

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
    }
    LL lb = -1;
    LL ub = n * 2;
    while (ub - lb > 1) { //logN
        LL mid = (ub + lb) / 2;
        if (C(mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    cout << ub << endl;

}