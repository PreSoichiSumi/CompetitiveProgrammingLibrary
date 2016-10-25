#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;
#define int long long
#define MODULE 1000000007
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second

template<class T, class U>
inline void chmin(T &t, U f) { if (t > f)t = f; }

template<class T, class U>
inline void chmax(T &t, U f) { if (t < f)t = f; }

typedef pair<int, int> P;
typedef long long LL;
const LL INF = LLONG_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
string aStr;
LL a, k;
LL minDist = INF;

signed main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> aStr;
    a = stoll(aStr);  //O( |s| )
    cin >> k;

    set<int> hoge;
    LL tmpNum = 0;

    int keta=0;
    while (keta < aStr.length() && hoge.size() < k - 1) {
        tmpNum *= 10;
        int num = aStr[keta] - '0';
        tmpNum += num;
        hoge.insert(num);
        keta++;
    }
    if (keta == aStr.length()) {    //k内で全て決定できたら
        cout << 0 << endl;
        return 0;
    } else {//k-1までに決まらなかったら
        tmpNum *= 10;
        for (int i = 0; i < 10; ++i) {
            LL tmpKeta = keta;
            LL tmpNum2 = tmpNum + i;
            set<int> tmpHoge = hoge;
            tmpHoge.insert(i);
            tmpKeta++;
            if (tmpKeta == aStr.length()) {
                chmin(minDist, abs(tmpNum2 - a));
                continue;
            }

            for (int j:tmpHoge) {   //残りの桁を今までに使った数字で埋める
                LL tmpKeta2=tmpKeta;
                LL tmpNum3=tmpNum2;
                while (tmpKeta2 < aStr.length()) {
                    tmpNum3 = tmpNum3 * 10 + j;
                    tmpKeta2++;
                }
                chmin(minDist,abs(tmpNum3-a));
            }

        }
    }
    cout << minDist << endl;
}