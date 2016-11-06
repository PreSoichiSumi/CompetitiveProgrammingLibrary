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
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
/*const int MAXN = 100001;

struct graph {
    graph(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<graph> graph[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/
//-----Template---------
const P pINF=MP(-INF,INF);
const P fail=MP(INF,-INF);

vector<P> range;
vector<int> graph[100001];
bool visited[100001];

P dfs(int v){
    if(visited[v])
        return pINF;
    visited[v]=true;
    for (int i = 0; i < graph[v].size(); ++i) {
        int to=graph[v][i];
        P res=dfs(to);
        if(res==MP(pINF.first-1,pINF.second+1))res=pINF;
        if(res==fail){
            return fail;
        }else if(range[v]==pINF){
            range[v]=pINF;
        }else if(res==pINF){
            continue;
        }else if(range[v].first%2!=res.first%2){
            return fail;
        }else if(range[v].second<res.first){
            return fail;
        }else if(res.second<range[v].first){
            return fail;
        }else{
            range[v].second=min(range[v].second,res.second);
            range[v].first=max(range[v].first,res.first);
        }
    }
    if(range[v].second<range[v].first)
        return fail;
    return MP(range[v].first-1,range[v].second+1);
}

void decide(int v){
    if(visited[v]) return;
    visited[v]=true;
    range[v]=MP(range[v].first,range[v].first);
    for (int i = 0; i < graph[v].size(); ++i) {
        int to=graph[v][i];
        if(visited[to])continue;
        range[to]=MP(max(range[to].first,range[v].first-1),
                            min(range[to].second,range[v].second+1));
        decide(to);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    int n;
    cin>>n;
    for (int i = 0; i < n - 1; ++i) {
        int a,b;
        cin>>a>>b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        visited[i]=false;
    }
    range=vector<P>(n,pINF);
    int k; cin>>k;
    for (int i = 0; i < k; ++i) {
        int v,p; cin>>v>>p; v--;
        range[v]=MP(p,p);
    }
    P ret=dfs(0);
    if(ret==fail){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    for (int i = 0; i < n; ++i) {
        visited[i]=false;
    }
    decide(0);
    for (int i = 0; i < n; ++i) {
        cout<<range[i].first<<endl;
    }
    return 0;
}