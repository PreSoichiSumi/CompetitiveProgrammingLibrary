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
const LL INF = LONG_MAX / 2;    //int_max->2*e+9
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int n;
LL tmpS,tmpC;
set<pair<LL,LL>> memo;
vector<LL> ans;
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    scanf("%ld",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%ld%ld",&tmpS,&tmpC);
        while (tmpC){
            auto it=memo.lower_bound(MP(tmpS,-1));//tmp以上で終わる最小の範囲を返す
            if(it==memo.end()){
                memo.insert(MP(tmpS+tmpC,tmpS));
                tmpC=0; ans.push_back(tmpS+tmpC);
                break;
            }
            if(it->first<=tmpS){
                if()
            }else { //始まりがtmpSよりあと

            }
        }

    }
}