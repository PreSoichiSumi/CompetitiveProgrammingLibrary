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
vector<int> graph[MAXN+1];
int color[MAXN+1];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
LL a,b,c,myCount=0;
priority_queue<int> qu;     //これで最大値を取り出せる　最小値なら <int ,std::vector<int>, std::greater<int>>
int main() {
    ios::sync_with_stdio(false);
    cin >> a>>b>>c;
    if(a%2==0)
        myCount++;
    if(b%2==0)
        myCount++;
    if(c%2==0)
        myCount++;
    qu.push(a);
    qu.push(b);
    qu.push(c);
    if(myCount>=1){
        cout<<0<<endl;
    }else{
        LL Max=qu.top()/2;qu.pop();
        LL a=qu.top();qu.pop();
        LL b=qu.top();qu.pop();
        cout<<a*b<<endl;
    }


}