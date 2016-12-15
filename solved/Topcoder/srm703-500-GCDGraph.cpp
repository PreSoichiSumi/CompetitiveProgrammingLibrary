#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
    vector<int> data;

    UnionFind(int size) : data(size, -1) {}

    bool unite(int x, int y) {   //併合
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }

    bool isSame(int x, int y) {    //同じ集合か判定
        return root(x) == root(y);
    }

    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    int size(int x) {
        return -data[root(x)];
    }
};

class GCDGraph {
public:
    string possible(int n, int k, int x, int y) {
        UnionFind uf(n + 1);

        for (int i = k + 1; i <= n; i++) {
            for (int j = 2; i * j <= n; ++j) {
                uf.unite(i,i*j);
            }
        }
        bool flag = uf.isSame(x, y);
        return (flag ? "Possible" : "Impossible");


        /*for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int res = gcd(i, j);
                if (res > k) {
                    uf.unite(i, j);
                }
            }
        }
        bool flag = uf.isSame(x, y);
        return (flag ? "Possible" : "Impossible");*/
    }

    int gcd(int a, int b) {
        if (b == 0)return a;
        return gcd(b, a % b);
    }


};

// CUT begin
ifstream data("GCDGraph.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template<typename T>
void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template<typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int n, int k, int x, int y, string __expected) {
    time_t startClock = clock();
    GCDGraph *instance = new GCDGraph();
    string __result = instance->possible(n, k, x, y);
    double elapsed = (double) (clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    } else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int n;
        from_stream(n);
        int k;
        from_stream(k);
        int x;
        from_stream(x);
        int y;
        from_stream(y);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(n, k, x, y, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1481687550;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if (string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "GCDGraph (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
