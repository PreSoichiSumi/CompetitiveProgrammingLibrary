//notさんの解
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    constexpr int SIZE = 1e9;
    vector<int> cnt(SIZE + 1);
    vector<pair<int, int>> u;
    for (int i = 1; i <= SIZE; ++i) {
        for (int j = i; j <= SIZE; j += i) ++cnt[j];
        if (SIZE / 2 < i && 300 < cnt[i]) u.emplace_back(cnt[i], i);
    }
    sort(u.begin(), u.end(), greater<pair<int, int>>());
    vector<bool> s(SIZE + 1);
    for (int i = 0; i < 100; ++i) {
        int r = 0, t = -1;
        for (int jj = 0; jj < (int)u.size(); ++jj) {
            if (u[jj].first <= r) continue;
            int j = u[jj].second, x = 0;
            for (int k = 1; k * k <= j; ++k) {
                if (j % k) continue;
                if (!s[k]) ++x;
                if (!s[j / k] && k != j / k) ++x;
            }
            u[jj].first = x;
            if (r < x) {
                t = j;
                r = x;
            }
        }
        for (int j = 1; j * j <= t; ++j) {
            if (t % j) continue;
            s[j] = true;
            s[t / j] = true;
        }
        cout << t << endl;
    }
}