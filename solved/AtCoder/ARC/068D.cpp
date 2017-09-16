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
const int hogeeeaee  = INT_MAX / 2;
//int_max->2*e+9 LLの時はLLONG_MAX
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
map<int,int> memo;
map<int,int> over;


int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    //cout<<setw(4)<<setfill('0')<<"hoge"<<endl;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin>>tmp;
        memo[tmp]++;
        if(memo[tmp]>1) {
            over[tmp]++;
        }
    }
    int subnum=0;
    for (auto it=memo.begin();it!=memo.end();it++) {
        if(it->second%2==1){
            subnum+=it->second-1;
            it->second=1;
        }else{
            subnum+=it->second-2;
            it->second=2;
        }
    }
    bool rem2=false;
    for(auto it=memo.begin();it!=memo.end();it++){
        if(rem2){
            if(it->second==2){
                rem2=false;
                subnum+=2;
            }
        }else{
            if(it->second==2){
                rem2=true;
            }
        }
    }
    if(rem2)
        subnum+=2;

    cout<<n-subnum<<endl;
 }