#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

#define MODULE 1000000007
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define CONTAINS(x, y) (x.find(y)!=x.end()) //x<T1,T2>, T1 y
#define getPair(x) MP(x->first,x->second)

template<class T, class U>
inline void chmin(T &t, U f) { if (t > f)t = f; }

template<class T, class U>
inline void chmax(T &t, U f) { if (t < f)t = f; }

template<typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val) { //usage: int dp[10][10]; Fill(dp,INF);
    std::fill((T *) array, (T *) (array + N), val);
}

typedef pair<int, int> P;
typedef long long LL;
const int infff = INT_MAX / 2;

/*const int MAXN = 100001;

struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/

//-----Template---------
int n, q;
int d[51][51];
int p[2501];
map<pair<int, int>, int> rectmemo;
map<int, int> rects;

int getVal(int x, int y) {
    int sum = 0;
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j) {
            sum += d[i][j];
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    //cout<<setw(4)<<setfill('0')<<"hoge"<<endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
        }
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rectmemo.insert(MP(MP(i, j), getVal(i, j)));
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int i2 = i; i2 < n; ++i2) {
                for (int j2 = j; j2 < n; ++j2) {
                    int v = rectmemo[MP(i2, j2)];
                    if (i > 0 && j > 0) {
                        v -= (rectmemo[MP(i - 1, j2)] + rectmemo[MP(i2, j - 1)]);
                        v += rectmemo[MP(i - 1, j - 1)];
                    } else if (i > 0) {
                        v -= rectmemo[MP(i - 1, j2)];
                    } else if (j > 0) {
                        v -= rectmemo[MP(i2, j - 1)];
                    }
                    int x = (i2 - i + 1) * (j2 - j + 1);
                    if (CONTAINS(rects, x)) {
                        rects[x] = max(rects[x], v);
                    } else {
                        rects[x] = v;
                    }
                }
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int max=-1;
        for(auto it=rects.begin();it!=rects.end();it++){
           if(it->first > p[i])
               break;
           chmax(max,it->second);
        }
        cout<<max<<endl;
    }
    /*
    vector<pair<int, int>> rec1;
    for (auto it = rects.begin(); it != rects.end(); it++) {
        rec1.push_back(*it);
    }
    vector<pair<int, int>> rec2;//masu,val
    rec2.push_back(rec1[0]);
    //int minval = rec1[0].second;
    for (int i = 1; i < rec1.size(); ++i) {
        if (rec1[i-1].second >= rec1[i].second)
            continue;
        rec2.push_back(rec1[i]);
    }

    for (int i = 0; i < q; ++i) {
        auto it = upper_bound(rec2.begin(), rec2.end(), MP(p[i], infff));
        it--;
        cout << it->second << endl;
    }*/

}