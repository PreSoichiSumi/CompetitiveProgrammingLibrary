#include <iostream>
#include <list>
#include <climits>
#include <vector>
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
const int MAXN = 100001;

/*struct edge {   //structとclassの違いは，メンバが初期状態でpublicとなっているかprivateとなっているか
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------



int n,r;

vector<int> res;

int main() {
    ios::sync_with_stdio(false);
    while(true) {
        cin >> r >> n;
        if(n==-1 && r==-1) break;
        vector<int> x;      //x(N)はn個用意して，デフォルトコンストラクタの値で埋めるやつだからそのままpushbackすると死ぬ
        x.reserve(1001);    //これが一番いいけど，オーダ変わらんし，しなくてもいいかも
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            x.push_back(tmp);
        }
        sort(x.begin(), x.end());   //x.begin,endはとってあるサイズの最初と最後を返す
        int count = 0,index=0;
        while(index<n){
            int left=x[index];
            while(x[index]<=(left+r) && index<n)index++;
            int mid=x[index-1];
            while(x[index]<=(mid+r) && index<n)index++;
            count++;
        }
        res.push_back(count);
    }
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<endl;
    }
    return 0;
}