#include <climits>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>

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

//--Euclid--
int gcd(int a, int b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}

//----ExtendedEuqlid
LL extgcd(LL a, LL b, LL &x, LL &y) {
    LL g = a;
    x = 1;
    y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}
//----

LL a, b, resX, resY;

int main() {
    cin >> a >> b;
    int gcdres = gcd(a, b);
    if (gcdres != 1)
        cout << "-1" << endl;
    else {
        extgcd(a, b, resX, resY);
        if (resX > 0) {
            cout << resX << " 0 ";
        } else {
            cout << "0 " << -resX << " ";
        }

        if (resY > 0) {
            cout << resY << " 0 ";
        } else {
            cout << "0 " << -resY << " ";
        }

    }

}