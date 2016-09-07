#include <iostream>
#include <climits>
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
const int MAXN = 100001;

/*struct edge {   //structとclassの違いは，メンバが初期状態でpublicとなっているかprivateとなっているか
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int n, l, p;
int a[10001];
int b[10001];
vector<P> vec;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];        //場所，量
    }
    cin >> l >> p;
    for (int i = 0; i < n; i++) {
        vec.push_back(P(l - a[i], b[i]));
    }
    sort(vec.begin(), vec.end());

    int count = 0, drove = p, index = 0;
    bool flag = false;
    priority_queue<int> pq;
    while (true) {
        if (drove >= l) {
            flag = true;
            break;
        }

        while (index < n && vec[index].first <= drove) {    //いけるとこまでのガソリンスタンドを追加
            pq.push(vec[index].second);
            index++;
        }

        if (pq.empty())break;    //キューが空ならもう走れない．失敗

        drove += pq.top();
        pq.pop();   //最も補給できるガソリンスタンドを追加
        count++;
    }
    cout << (flag ? count : -1) << endl;
}