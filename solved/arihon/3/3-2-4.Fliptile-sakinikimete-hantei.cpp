#include <climits>
#include <utility>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
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
template<typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val){ //usage: int dp[10][10]; Fill(dp,INF);
    std::fill( (T*)array, (T*)(array+N), val );
}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
/*const int MAXN = 100001;
struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/
int dx[5] = {-1, 0, 0, 1, 0};
int dy[5] = {0, -1, 0, 0, 1};
//-----Template---------
int m,n;
int resCount=INF;
int grid[20][20];
int res[20][20];
int flip[20][20];

int get(int i,int j){
    int num=grid[i][j];
    for (int k = 0; k < 5; ++k) {
        int dx2=i+dx[k],dy2=j+dy[k];
        if(0<=dx2 && dx2<m && 0<=dy2 && dy2<n)
            num+=flip[dx2][dy2];
    }
    return num%2;
}

int main(){
    scanf("%d %d",&m,&n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %d",&grid[i][j]);
        }
    }
    for (int i = 0; i < 1<<n; ++i) {
        int count=0;
        memset(flip,0,sizeof(flip));
        for (int j = 0; j < n; ++j) {
            if(i>>j & 1){
                flip[0][n-1-j]=1;
                count++;
            }
        }

        for (int j = 1; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                if(get(j-1,k)==1){
                    flip[j][k]=1;
                    count++;
                }
            }
        }
        bool flag=true;
        for (int j = 0; j < n; ++j) {
            if(get(m-1,j)==1){
                flag=false;
            }
        }
        if(flag && count<resCount){
            memcpy(res,flip, sizeof(flip));
            resCount=count;
        }
    }
    if(resCount==INF){
        printf("IMPOSSIBLE\n");
    }else {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d", res[i][j]);
                if (j != n - 1)
                    printf(" ");
            }
            printf("\n");
        }
        //printf("\n");
    }
}