#include <iostream>
#include <list>
#include <climits>
#include <vector>
#include <algorithm>
#include <set>

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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int n,tmpW,tmpV,W;
int w[101],v[101];
int dp[101][10001];

int rec(int i, int j){   //i番目以降までで，jを超えないように選んだ時の最大価値
    if(dp[i][j]!=-1)return dp[i][j];
    int res=0;
    if(i==n){
        res=0;
    }else if(j-w[i]<0){
        res=rec(i+1,j);
    }else{
        res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
    }
    dp[i][j]=res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    cin>>W;
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < W + 1; ++j) {
            dp[i][j]=-1;
        }
    }
    cout<<rec(0,W)<<endl;

    return 0;
}