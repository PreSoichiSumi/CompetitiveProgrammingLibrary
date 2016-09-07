#include <cstdio>
#include <utility>
#include <climits>
#include <vector>

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
int n, k, tmpI, tmpX, tmpY;
struct UnionFind {
    vector<int> data;

    UnionFind(int size) : data(size, -1) {}

    bool unionSet(int x, int y) {   //併合
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }

    bool findSet(int x, int y) {    //同じ集合か判定
        return root(x) == root(y);
    }

    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    int size(int x) {
        return -data[root(x)];
    }
};

int main() {
    //ios::sync_with_stdio(false);
    scanf("%d %d",&n,&k);//scanf(" ");
//    cin >> n >> k;

    UnionFind uf(n * 3);
    int count = 0;
    for(int i=0;i<k;i++){
  //      cin>>tmpI>>tmpX>>tmpY;
        scanf("%d %d %d",&tmpI,&tmpX,&tmpY);//scanf(" ");
        tmpX--;tmpY--;
        bool conflict = false;
        if(tmpX<0 || n<=tmpX ||tmpY<0 || n<=tmpY ){
            count++;
            continue;
        }
        if (tmpI == 1) {
            conflict = uf.findSet(tmpX, tmpY + n) || uf.findSet(tmpX, tmpY + 2 * n);
            if (conflict) {
                count++;
                continue;
            }
            uf.unionSet(tmpX, tmpY);
            uf.unionSet(tmpX + n, tmpY + n);
            uf.unionSet(tmpX + n * 2, tmpY + n * 2);
        } else {
            conflict = uf.findSet(tmpX, tmpY) || uf.findSet(tmpY, tmpX + n);
            if (conflict) {
                count++;
                continue;
            }
            uf.unionSet(tmpX, tmpY + n);
            uf.unionSet(tmpX + n, tmpY + n * 2);
            uf.unionSet(tmpX + 2 * n, tmpY);
        }
    }
    printf("%d",count);//cout << count << endl;

}