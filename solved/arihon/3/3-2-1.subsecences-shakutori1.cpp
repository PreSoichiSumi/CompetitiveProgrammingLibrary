
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
#include <climits>
#include <utility>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

#define MODULE 1000000007
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int T,N,S;
int a[100001];
vector<int> res;
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    scanf("%d",&T);
    for (int i = 0; i < T; ++i) {
        scanf("%d%d",&N,&S);
        for (int j = 0; j < N; ++j) {
            scanf("%d",&a[j]);
        }
        int minLen=INF;
        int begin=0;
        int end=0;
        int sum=a[0];
        while(true){
            if(sum<S){
                end++;
                if(end>=N)
                    break;
                sum+=a[end];
            }else{
                chmin(minLen,end-begin+1);
                sum-=a[begin]; begin++;
            }
        }
        res.push_back(minLen);
    }
    for (int i = 0; i < T; ++i) {
        printf("%d\n",(res[i]==INF?0:res[i]));
    }
}