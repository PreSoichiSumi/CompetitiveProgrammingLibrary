#include <iostream>
#include <climits>
#include <array>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

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

int n,s,t;
vector<P> work;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>s>>t;
        work.push_back(P(t,s));//おわり，はじまり
    }
    sort(work.begin(),work.end());
    int index=0,now=0,res=0;
    while(index<n){
        if(now<work[index].second){
            now=work[index].first;
            res++;
        }
        index++;
    }
    cout<<res<<endl;
}