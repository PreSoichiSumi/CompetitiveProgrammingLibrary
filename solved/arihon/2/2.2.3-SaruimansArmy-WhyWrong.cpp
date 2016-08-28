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
        vector<int> x;

        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            x.push_back(tmp);
        }
        sort(x.begin(), x.end());
        int left = x[0], count = 0;
        for (int index = 0; index < n; index++) {
            if ((left + r) < x[index]) {//index-1にしるしをつける
                count++;
                int index2 = index - 1;
                int mid = x[index - 1];
                while (index2 < n && x[index2] <= (mid + r)) {
                    index2++;
                }
                left = x[index2];
                index = index2 - 1;
            }
        }
        res.push_back(count+1);
    }
    for (int i = 0; i < res.size(); ++i) {
        cout<<res.at(i)<<endl;
    }
    return 0;
}