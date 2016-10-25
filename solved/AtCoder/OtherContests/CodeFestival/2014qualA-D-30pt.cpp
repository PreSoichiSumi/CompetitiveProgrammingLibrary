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
const int INF = INT_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
LL a,k;
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>a>>k;
    assert(a<100001);   //assertはruntime errorで分かる
    LL minDist=INF;
    for (int i = 0; i < 100001; ++i) {
        LL tmpI=i;
        set<int> used;
        while(tmpI>0){
            used.insert(tmpI%10);
            tmpI/=10;
        }
        if(used.size()>k)
            continue;
        chmin(minDist,abs(i-a));
    }
    cout<<minDist<<endl;
}