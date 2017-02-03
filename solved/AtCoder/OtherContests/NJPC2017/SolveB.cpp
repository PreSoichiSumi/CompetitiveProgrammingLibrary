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
#define CONTAINS(x, y) (x.find(y)!=x.end()) //x<T1,T2>, T1 y
#define getPair(x) MP(x->first,x->second)

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}
template<typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val){ //usage: int dp[10][10]; Fill(dp,INF);
    std::fill( (T*)array, (T*)(array+N), val );
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
LL h,w,n;
LL sublines=0;

set<P> dots;

bool contained(int r,int c){
    return dots.find(MP(r,c))!=dots.end();
}

int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    //cout<<setw(4)<<setfill('0')<<"hoge"<<endl;
    cin>>h>>w>>n;
    for (int i = 0; i < n; ++i) {
        int tmpr,tmpc;
        cin>>tmpr>>tmpc;
        tmpr--; tmpc--;
        if(tmpr>0 && !contained(tmpr-1,tmpc) )
            sublines++;
        if(tmpr<h-1 && !contained(tmpr+1,tmpc))
            sublines++;
        if(tmpc>0 && !contained(tmpr,tmpc-1))
            sublines++;
        if(tmpc<w-1 && !contained(tmpr,tmpc+1))
            sublines++;
        dots.insert(MP(tmpr,tmpc));
    }
    cout<<(h-1)*w+(w-1)*h-sublines<<endl;
}