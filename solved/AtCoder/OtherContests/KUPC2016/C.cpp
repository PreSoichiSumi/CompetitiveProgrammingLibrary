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

int t;
int n[1001];
unsigned char d[1001];

int main(){
    ios::sync_with_stdio(false);
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        scanf("%d%d",&n[i],&d[i]);
        //cin>>n[i]>>d[i];
    }
    for (int i = 0; i < t; ++i) {
        if(n[i]==1){
            printf("%d\n",d[i]);
        }else if(n[i]%2==1) {
            printf("%d\n",d[i] + 127 * (n[i] - 1));
        }else{
            printf("%d\n",127*(n[i]-1)+(~d[i]&0b01111111));
        }
    }
}