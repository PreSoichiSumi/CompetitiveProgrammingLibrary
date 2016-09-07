#include <iostream>
#include <climits>
#include <array>
#include <cmath>
#include <vector>
#include <queue>

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

/*struct edge {   //structとclassの違いは，メンバが初期状態でpublicとなっているかprivateとなっているか
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/
bool graph[MAXN+1][MAXN+1];
int color[MAXN+1];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int n,k;

bool dfs(int i,int c){    //0,1,-1で書くときれい
    color[i]=c;
    for(int j=0;j<n;j++){
        if(graph[i][j]){
            if(color[j]==0){
                return dfs(j,-c);
            }else if(color[i]==color[j]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n>>k;
    for (int i = 0; i < n; ++i) {
        color[i]=0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j]= false;
        }
    }
    for(int i=0;i<k;i++){
        int tmpI,tmpJ;
        cin>>tmpI>>tmpJ;
        graph[tmpI][tmpJ]=true;
        graph[tmpJ][tmpI]=true;
    }
    bool flag=true;
    for (int i = 0; i < n; ++i) {
        if(color[i]==0){
            if(!dfs(i,1)) {
                flag = false;
                break;
            }
        }
    }
    cout<<(flag?"Yes":"No")<<endl;
}