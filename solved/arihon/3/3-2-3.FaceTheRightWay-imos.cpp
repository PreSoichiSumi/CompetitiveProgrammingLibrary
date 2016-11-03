#include <climits>
#include <utility>
#include <vector>
#include <cstdio>
#include <iostream>
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
vector<edge> graph[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/

//-----Template---------
int n;
char c[5001];
int imos[5001];
int resCount=INF;
int resK=0;
int main(){
    scanf("%d\n",&n);
    for (int i = 0; i < n; ++i) {
        scanf(" %c",&c[i]);
    }
    for (int k = 1; k <= n ; ++k) {
        Fill(imos,0);
        int sum=0;
        int count=0;
        for (int i = 0; i+k <= n; ++i) {
            int num=c[i]=='F'?0:1;
            if((num+sum)%2!=0){
                imos[i]=1;
                sum+=imos[i];
                count++;
            }
            if(i-k+1>=0){
                sum-=imos[i-k+1];
            }
        }
        bool flag=true;
        for(int i=n-k+1;i<n;i++){
            int num=c[i]=='F'?0:1;
            if((num+sum)%2!=0){
                flag=false;
                break;
            }
            if(i-k+1>=0){
                sum-=imos[i-k+1];
            }
        }
        if(flag && resCount>count){
            resCount=count;
            resK=k;
        }
    }
    printf("%d %d\n",resK,resCount);

    //std::cin.clear();
    return 0;
}