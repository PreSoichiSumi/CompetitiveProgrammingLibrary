#include <bits/stdc++.h>

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

int dp[101][102];   //dp[i][j]　A[i]-A[j]間の囚人全てを開放するのに必要な最小のお金
int A[102];

int testCase, p, q;
vector<LL> ans;
std::string fileName = "C:\\Users\\s-sumi\\ClionProjects\\GCJ\\output.txt";
std::ofstream writing_file(fileName, std::ios::out);

int main() {
    ios::sync_with_stdio(false);
    //writing_file.open(fileName,std::ios::out);
    scanf("%d", &testCase);
    for (int i = 0; i < testCase; ++i) {
        scanf("%d%d", &p, &q);
        int tmp;
        for (int j = 0; j < q; ++j) {
            scanf("%d", &A[j + 1]);
        }
        A[0] = 0;
        A[q + 1] = p + 1;
        for (int j = 0; j <= q; ++j) {
            dp[j][j + 1] = 0;
        }
        for (int w = 2; w <= q + 1; ++w) {
            for (int j = 0; j + w <= q + 1; ++j) {
                int jj = j + w, t = INF;
                for (int k = j + 1; k < jj; k++) {
                    chmin(t,dp[j][k]+dp[k][jj]);
                }
                dp[j][jj]=t+A[jj]-A[j]-2;
            }
        }
        ans.push_back(dp[0][q+1]);
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << "Case #" + to_string(i + 1) + ": " + to_string(ans.at(i)) << endl;
        writing_file << "Case #" + to_string(i + 1) + ": " + to_string(ans.at(i)) << endl;
    }


}