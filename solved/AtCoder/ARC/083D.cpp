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
#define V 301

int a[V][V];
int test[V][V];
int n;

LL sumCost=0;

void warshallFloid(){
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                test[i][j]=min(test[i][j],test[i][k]+test[k][j]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> n;
    Fill(a, 0);
    Fill(test, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            cin >>a[i][j];
            sumCost+=a[i][j];
            test[i][j] = a[i][j];
        }
    }

    sumCost/=2;

    warshallFloid();

    bool flag = true;
    for (int i = 0; i < n; ++i) {//ほんとに最短経路の表だったか調べる  2.7*10^6
        for (int j = 0; j < n; ++j) {
            if(a[i][j] != test[i][j]){
                flag=false;
            }

        }
    }

    if(flag){
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                for (int k = 0; k < n; ++k) {  //もし他の頂点を通ってiからjへ行っても最短距離がかわらないなら辺を取る
                    if( k==i || k==j )continue;

                    if(test[i][j]==(test[i][k]+test[k][j])){
                        sumCost-=test[i][j];
                        break;
                    }
                }
            }
        }
        cout<<sumCost<<endl;
    }else{
        cout<<-1<<endl;
    }


}