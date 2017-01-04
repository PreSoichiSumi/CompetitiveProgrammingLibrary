#include <bits/stdc++.h>

using namespace std;

#define MODULE 1000000007
#define MP make_pair
#define CONTAINS(x, y) (x.find(y)!=x.end()) //x<T1,T2>, T1 y
#define getPair(x) MP(x->first,x->second)

template<typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val) { //usage: int dp[10][10]; Fill(dp,INF);
    std::fill((T *) array, (T *) (array + N), val);
}

void replaceStr(string &base, string from, string to) {
    auto pos = base.find(from);
    while (pos != string::npos) {
        base.replace(pos, from.size(), to);
        pos = base.find(from, pos + to.size());
    }
}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
//-----Template---------
LL n;

int getS(int s) {
    int low = s % 100;
    int high = s / 100;
    if (low % 10 >= 5) {
        low = low / 10 * 10 + 5;
    } else {
        low = low / 10 * 10;
    }
    return high * 100 + low;
}

int getE(int e) {
    int low = e % 100;
    int high = e / 100;
    if (low % 10 > 5) {
        low = low / 10 * 10;
        low += 10;
        if (low == 60) {
            low = 0;
            high++;
        }
    } else if (0 < low % 10 && low % 10 < 5) {
        low = low / 10 * 10 + 5;
    }
    return high * 100 + low;
}

string s;
int memo[2000];

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10); ///cout<<setw(4)<<setfill('0')<<"hoge"<<endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int S, E;
        cin >> s;
        replaceStr(s, "-", " ");
        stringstream ss(s);
        ss >> S >> E;
        //S = getS(S);
        //E = getE(E);

        S = S / 5 * 5;
        if (S % 100 == 60)S += 40;
        E = (E + 4) / 5 * 5;
        if (E % 100 == 60)E += 40;

        int Shigh = S / 100;
        int Slow = S % 100;
        int Ehigh = E / 100;
        int Elow = E % 100;
        memo[Shigh * 12 + Slow / 5]++;
        memo[Ehigh * 12 + Elow / 5]--;
    }
    bool in = false;
    int counter = 0;
    int S, E;
    for (int i = 0; i <= 12 * 24; i++) {
        counter += memo[i];
        if (in) {
            if (counter <= 0) {
                E = (i / 12) * 100;
                E += (i % 12) * 5;
                in = false;
                cout << setw(4) << setfill('0') << S << "-" << E << endl;
            }
        } else {
            if (counter > 0) {
                S = (i / 12) * 100 + (i % 12) * 5;
                in = true;
            }
        }
    }
}

