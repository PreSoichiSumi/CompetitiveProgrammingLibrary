#include <iostream>
#include <climits>
#include <array>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 100001;

/*struct edge {   //structとclassの違いは，メンバが初期状態でpublicとなっているかprivateとなっているか
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int n,k,x,y;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k>>x>>y;
    int res=0;
    if(n<=k){
        res=x*n;
    }else{
        res=x*k+(n-k)*y;
    }
    cout<<res<<endl;
}