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
template<typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val){ //usage: int dp[10][10]; Fill(dp,INF);
    std::fill( (T*)array, (T*)(array+N), val );
}

typedef pair<int, int> P;
typedef unsigned long long LL;
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
vector<LL> getFib(LL lim){
    vector<LL> res;
    res.push_back(1);
    res.push_back(1);
    LL it=2;
    LL tmp=1;
    while(tmp<lim){
        tmp=res[it-1]+res[it-2];
        res.push_back(tmp);
        it++;
    }
    return res;
}

LL n;
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>n;
    if(n==2){
        cout<<1<<endl;
        return 0;
    }

    vector<LL> fib=getFib((LL)1e18 + 100);
    LL it=2;
    while(fib[it]<=n){
        it++;
    }
    //n<=tmp
    cout<<it-2<<endl;

}