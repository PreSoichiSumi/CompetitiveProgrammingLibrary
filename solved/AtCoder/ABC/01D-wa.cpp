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

map<int, int> memo;

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
    int low  = e % 100;
    int high = e / 100;
    if (low % 10 > 5) {
        low = low / 10 * 10;
        low+=10;
        if(low==60){
            low=0;
            high++;
        }
    } else if (0 < low % 10 && low % 10 < 5) {
        low = low / 10 * 10 + 5;
    }
    return high * 100 + low;
}

string s;

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int S, E;
        cin >> s;
        replaceStr(s, "-", " ");
        stringstream ss(s);
        ss >> S >> E;
        S = getS(S);
        E = getE(E);

        if (!CONTAINS(memo, S) || (CONTAINS(memo, S) && E > memo.find(S)->second)) {
            memo.insert(MP(S, E));
            {
                auto it = memo.find(S);
                if (it != memo.begin()) {
                    P sec = getPair(it);
                    it--;
                    P fir = getPair(it);
                    if (fir.second >= sec.first) {
                        if (fir.second >= sec.second) {
                            memo.erase(sec.first);
                        } else {
                            memo.erase(fir.first);
                            memo.erase(sec.first);
                            memo.insert(MP(fir.first, sec.second));
                            S = fir.first;
                        }
                    }
                }
            }
            {
                auto it = memo.find(S);
                P fir = getPair(it);
                it++;
                if (it != memo.end()) {
                    P sec = getPair(it);
                    if (fir.second >= sec.first) {
                        if (fir.second >= sec.second) {
                            memo.erase(sec.first);
                        } else {
                            memo.erase(fir.first);
                            memo.erase(sec.first);
                            memo.insert(MP(fir.first, sec.second));
                        }
                    }
                }
            }
        }
    }
    //cout << memo.size() << endl;
    for (auto it = memo.begin(); it != memo.end(); it++) {
        cout << setw(4) << setfill('0') << (it->first) << "-" << (it->second) << endl;
    }
}

