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

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef pair<int, int> P;
typedef long long LL;
const int INF = LLONG_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int h,w;
char color[301][3+1];
LL dp[301][301][301];

LL push(LL x,LL y,LL z,LL num){//num:0-2 x,y,z:0-h x,y,zからnumを押すコスト
    LL cost=0;
    LL arr[3];
    arr[0]=x;
    arr[1]=y;
    arr[2]=z;
    for (int i = 0; i < h-arr[num]; ++i) {
        if(num-1>=0 && arr[num-1]+i<h){
            cost+=color[i][num]==color[arr[num-1]+i][num-1]?1:0;
        }
        if(num+1<=2 && arr[num+1]+i<h){
            cost+=color[i][num]==color[arr[num+1]+i][num+1]?1:0;
        }
    }
    return cost;
}
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>> h>>w;
    assert(w<=3);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%c",&color[i][j]);
        }
    }
    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j <= h; ++j) {
            for (int k = 0; k <= h; ++k) {
                dp[i][j][k]=INF;
            }
        }
    }
    dp[0][0][0]=0;
    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j <= h; ++j) {
            for (int k = 0; k <= h; ++k) {
                LL tmpA=i-1>0?dp[i-1][j][k] + push(i-1,j,k,0):INF;
                LL tmpB=j-1>0?dp[i][j-1][k] + push(i,j-1,k,1):INF;
                LL tmpC=k-1>0?dp[i][j][k-1] + push(i,j,k-1,2):INF;
                dp[i][j][k]=min(tmpA,min(tmpB,tmpC));
            }
        }
    }
    cout<< dp[h][h][h]<<endl;
}