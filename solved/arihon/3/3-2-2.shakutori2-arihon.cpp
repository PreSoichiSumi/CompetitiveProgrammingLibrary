#include <climits>
#include <utility>
#include <vector>
#include <cstdio>
#include <iostream>
#include <set>
#include <map>
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


int p;
int a[1000000];
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);

    set<int> all;
    scanf("%d",&p);
    for (int i = 0; i < p; ++i) {
        scanf("%d",&a[i]);
        all.insert(a[i]);
    }
    int n= all.size();
    int s=0,t=0,num=0;
    map<int,int> count;
    int res=p;
    for(;;){
        while(t<p&& num<n){
            if(count[a[t++]]++==0){
                num++;
            }
        }
        if(num<n)break;
        chmin(res,t-s);
        if (--count[a[s++]]==0){
            num--;
        }
    }
    printf("%d\n",res);
}
