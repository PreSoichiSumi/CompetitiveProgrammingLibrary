#include <iostream>
#include <list>
#include <climits>

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

int n;
char c;
list<char> tmp;
list<char> str;

bool nextIsFront(std::list<char> &list) {
    std::list<char>::iterator itf = list.begin();
    std::list<char>::iterator itb = --list.end();
    while (itf != itb) {
        if (*itf < *itb) {
            return true;
        } else if (*itf > *itb) {
            return false;
        } else {
            ++itf;
            if (itf == itb)break;
            --itb;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    //scanf_s("%d ",&n);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        //  scanf_s("%c ",&c);]
        cin >> c;
        tmp.push_back(c);
    }

    while (!tmp.empty()) {
        if (nextIsFront(tmp)) {
            c = tmp.front();
            tmp.pop_front();
        } else {
            c = tmp.back();
            tmp.pop_back();
        }
        str.push_back(c);
    }
    int count = 0;
    for (std::list<char>::iterator it = str.begin(); it != str.end(); it++) {
        if (count == 80) {
            cout << endl;
            count = 0;
        }
        cout << *it;
        count++;

    }
    cout << endl;
    return 0;
}