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
/*const int MAXN = 100001;*/

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[1001];*/
/*int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/


bool graph[1001][1001];
bool indep[1001];

//-----Template---------
map<int,set<int>> counter;
set<int> gov;
int n,m,k;

/*int countEdgeOfCompGraph(int x){
    return counter[x].size()
}*/

void updateCounter(int x,int government){
    for (int i = 0; i < n; ++i) {
        if(x==-1){
            if(graph[government][i] && counter[government].find(i)==counter[government].end()){
                counter[government].insert(i);
                indep[i]=false;
                updateCounter(i,government);
            }
        }else if(graph[x][i] && counter[government].find(i)==counter[government].end()){
            counter[government].insert(i);
            indep[i]=false;
            updateCounter(i,government);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>n>>m>>k;
    Fill(indep,true);
    for (int i = 0; i < k; ++i) {
        int tmp;
        cin>>tmp;tmp--;
        gov.insert(tmp);
        indep[tmp]=false;
        counter[tmp].insert(tmp);
    }
    for (int i = 0; i < m; ++i) {
        int from,to;
        cin>>from>>to;
        from--;
        to--;
        graph[from][to]=true;
        graph[to][from]=true;
    }
    for (int i = 0; i < n; ++i) {
        if(gov.find(i)!=gov.end()){//govなら
            updateCounter(-1,i);
        }
    }
    int indepCount=0;
    for (int i = 0; i < n; ++i) {
        if(indep[i])
            indepCount++;
    }

    LL res=0;
    vector<LL> edges;
    for (auto it = gov.begin();it!=gov.end();it++) {
        edges.push_back(counter[*it].size());
    }
    sort(edges.begin(),edges.end(),std::greater<LL>());
    edges[0]+=indepCount;
    for (int i = 0; i < edges.size(); ++i) {
        res+=edges[i]*(edges[i]-1)/2;
    }
    cout<<res-m<<endl;
}