#include <iostream>
#include <climits>
#include <array>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------

#define MAXN 1000
#define REPEAT 100
int k, n;
int w[MAXN];
int p[MAXN];

class SaltWater {
public:
    double w, p;
    double base;

    SaltWater(double w, double p, double base) : w(w), p(p), base(base) {}

    bool operator<(const SaltWater &rhs) const {
        return w * (p - base) > rhs.w * (rhs.p - base);    //降順ソート
    }
};

multiset<SaltWater> tmpWaters;

bool isCreatable(double base) {
    for (int i = 0; i < n; i++) {
        tmpWaters.insert(SaltWater(w[i], p[i], base));
    }
    double saltSum = 0;
    double wSum = 0;
    auto itr = tmpWaters.begin();
    for (int i = 0; i < k; i++, itr++) {//上位k個を選択
        saltSum += itr->w * itr->p;
        wSum += itr->w;
    }
    tmpWaters.clear();
    return (saltSum / wSum) > base;
}

int main(int argc, char **argv) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> p[i];
    }

    double HIGH = 100;
    double LOW = 0;
    double MID = (HIGH + LOW) / 2;
    for (int i = 0; i < REPEAT; i++) {
        if (isCreatable(MID)) {
            LOW = MID;
        } else {
            HIGH = MID;
        }
        MID = (HIGH + LOW) / 2;
    }
    cout << fixed << setprecision(10);
    cout << MID << endl;
    return 0;
}