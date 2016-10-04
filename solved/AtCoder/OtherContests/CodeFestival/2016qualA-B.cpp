#include <bits/stdc++.h>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 100001;
struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<int> graph[MAXN];

set<P> like;
int n,K;
//-----Template---------


int main(){
    ios::sync_with_stdio(false);
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&K); K--;
        if((find(graph[K].begin(),graph[K].end(),i)!=graph[K].end()) //すかれていて
                &&(like.find(P(i,K))==like.end())) {        //まだカウントされて無いなら
            like.insert(P(i, K));
        }
        graph[i].push_back(K);
    }
    cout<<like.size()<<endl;
}