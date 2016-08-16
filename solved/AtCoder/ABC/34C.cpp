#include <iostream>
#include <climits>

using namespace std;

#define MODULE 1000000007

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;
const int MAXWH = 1000;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------

//素因数分解を使った組み合わせ計算.mod下でも動作する
LL modComb(LL n, LL k, LL mod) {
    LL prime[n + 1];
    LL i, j;

    for (i = 2; i <= n; i++) {
        prime[i] = 1;
    }
    for (i = 2; i <= n; i++) {
        if (prime[i]) {
            for (j = i * 2; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }
    for (i = 2; i <= n; i++) {
        if (prime[i]) {
            prime[i] = 0;
            for (j = i; j <= n; j *= i) {
                prime[i] += n / j;
                if (j <= n - k) prime[i] -= (n - k) / j;
                if (j <= k) prime[i] -= k / j;
            }
        }
    }

    LL res = 1;
    for (LL i = 2; i <= n; i++) {
        if (prime[i] == 0) continue;
        for (int j = 0; j < prime[i]; j++) {
            res *= i;
            res %= mod;
        }
    }
    return res;
}



int w, h;

int main(int argc, char **argv) {
    cin >> w >> h;
    w--;
    h--;
    
    cout << modComb(w + h, h, MODULE) << endl;

    return 0;
}