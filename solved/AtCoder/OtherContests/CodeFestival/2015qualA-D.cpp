#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

#define MODULE 1000000007
#define MP make_pair

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
//-----Template---------

int n,m;
int x[100001];

int dp[101][100001];    //dp[i][j]:iより前の人まででjまで点検するのにかかる時間の最小値
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>n>>m;
    if(n>100){
        cout<<"hoge"<<endl;
        return 0;
    }

    for (int i = 1; i <= m; i++) {//dp[i][j]=dp[i-1][j]の形になったらデータのほうを
        cin>>x[i];//x[i]--;
    }
    for (int i = 0; i <=m; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    for (int i = 1; i <= m; i++) {   //O(MN^2)
        for (int j = 0; j < x[i]; j++) {    //各iについて，xiの前までと後ろについて更新する
            for (int k = x[i]; k <n ; ++k) {
                int time=min(2*(x[i]-j)+k,x[i]-j+2*k);
                chmin(dp[i][k],max(dp[i-1][j],time));
            }
        }
    }
    cout<<dp[m][n-1]<<endl;
}