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

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int t[1001];
int N,A,B;
int main(){
    ios::sync_with_stdio(false);
    cin>>N>>A>>B;
    for(int i=0;i<N;i++){
        cin>>t[i];
    }
    int count=0;
    for (int i = 0; i < N; ++i) {
        if(!(A<=t[i] && t[i]<B)){
            count++;
        }
    }
    cout<<count<<endl;

}