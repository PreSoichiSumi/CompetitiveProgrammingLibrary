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
const int MAXN = 100001;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------

class Permutation {
    bool *used;
    int *perm;
    int n;
public:
    Permutation(int n) : n(n) {
        used = new bool[n + 1];
        perm = new int[n + 1];
    }

    void permutation1(int pos) { //関数のみを使う場合は，int pos,int n
        if (pos == n) {//process permutation
            printPerm();
        }
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                perm[pos] = i;
                used[i] = true;
                permutation1(pos + 1);
                used[i] = false;
            }
        }
        return;
    }

    void permutation2() {
        for (int i = 0; i < n; ++i) {
            perm[i] = i;
        }
        do {
            printPerm();
        } while (next_permutation(perm, perm + n));//全ての順列を生成し終わったらnext_permはfalseを返す
        return;
    }

    void printPerm() {
        cout << "[";
        for (int i = 0; i < n; ++i) {
            cout << perm[i];
            if (i != n - 1)cout << ",";
        }
        cout << "]" << endl;
    }
};

int storages, b;

int main() {
    ios::sync_with_stdio(false);
    Permutation p(5);
    p.permutation1(0);
    Permutation p2(5);
    p2.permutation2();
    return 0;
}