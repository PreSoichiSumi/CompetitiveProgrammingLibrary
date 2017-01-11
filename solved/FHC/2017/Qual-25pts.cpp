#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
#include <math.h>
#include <lcms.h>

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
//-----Template---------

//1から2への距離
double getLen(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double getProduct(int x1, int y1, int x2, int y2) {
    return x1 * x2 + y1 * y2;
}

double getDeg(int x1, int y1, int x2, int y2) {
    double l1 = getLen(0, 0, x1, y1);
    double l2 = getLen(0, 0, x2, y2);
    double costheta = getProduct(x1, y1, x2, y2) / (l1 * l2);
    double deg = acos(costheta) * 180 / M_PI;
    return deg;
}

int t, n;
vector<int> w;
vector<int> ans;
std::string fileName = "C:\\Users\\s-sumi\\ClionProjects\\GCJ\\outputB.txt";
std::ofstream writing_file(fileName, std::ios::out);

int main() {
    ios::sync_with_stdio(false);
    //writing_file.open(fileName,std::ios::out);
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            w.push_back(tmp);
        }
        sort(w.begin(), w.end(), std::greater<int>());
        int res = 0;
        int counter = 0;
        for (int j = 0; j < n && counter<n; ++j) {
            counter += ceil(50.0 / w[j]);
            if(counter<=n)
                res++;
        }
        ans.push_back(res);
        w.clear();
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << "Case #" + to_string(i + 1) + ": " + to_string(ans[i])<< endl;
        writing_file << "Case #" + to_string(i + 1) + ": " + to_string(ans[i]) << endl;
    }


}