#include <climits>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

template<class T, class U>
inline void chmin(T &t, U f) { if (t > f)t = f; }

template<class T, class U>
inline void chmax(T &t, U f) { if (t < f)t = f; }

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 1001;

//---Bellman-Ford--O(VE)--------------
#define MAXE 20001
#define MAXV 1001
struct edge{
    edge() {}

    edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
    int from,to,cost;
};
edge es[MAXE];
int d[MAXV];
int V,E;
bool hasLoop=false;
void shortest_path(int s){
    for(int i=0;i<V;i++)d[i]=INF;
    d[s]=0;

    for (int j=0;j<V;j++){
        bool update=false;
        for (int i = 0; i < E; ++i) {
            edge e=es[i];
            if(d[e.from]!=INF && d[e.to]>d[e.from] +e.cost){
                d[e.to]=d[e.from] +e.cost;
                update = true;
            }
        }
        if(!update)break;
        if(j==V-1)hasLoop=true;
    }
}

bool findNegativeLoop(){
    memset(d,0, sizeof(d));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < E; ++j) {
            edge e=es[j];
            if(d[e.to]>d[e.from]+e.cost)
                d[e.to]=d[e.from]+e.cost;
            if(i==V-1)return true;
        }
    }
    return false;
}
//------------


LL n, ml,md,tmpA,tmpB,tmpD,edgeCount=0;
int main() {
    scanf("%d %d %d",&n,&ml,&md);
    for (int i = 0; i < ml; ++i) {
        scanf("%d %d %d",&tmpA,&tmpB,&tmpD);
        tmpA--;tmpB--;
        es[edgeCount++]=edge(tmpA,tmpB,tmpD);
    }
    for (int i = 0; i < md; ++i) {
        scanf("%d %d %d",&tmpA,&tmpB,&tmpD);
        tmpA--;tmpB--;
        es[edgeCount++]=edge(tmpB,tmpA,-tmpD);
    }
    V=n; E=ml+md;
    shortest_path(0);
    if(hasLoop){
        printf("-1\n");
    }else if(d[n-1]!=INF){
        printf("%d\n", d[n - 1]);
    }else{  //無限に大きくすることができる
        printf("%d\n",-2);
    }
}