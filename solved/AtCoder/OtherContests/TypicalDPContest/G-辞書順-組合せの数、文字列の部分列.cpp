#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
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

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
string s;
LL k;
LL dp[1000001][26];

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> s;
    cin >> k;
    LL inf=k+10;
    for (int i = 0; i < 26; ++i) {//実際は不要
        dp[s.length()][i] = 0;
    }
    for (LL i = s.length() - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            if ((s[i] - 'a') == j) {//s[i]で終わる文字を更新する場合
                dp[i][j] = 1;
                for (int l = 0; l < 26; ++l) {
                    dp[i][j]= min(dp[i][j] + dp[i + 1][l],inf);
                }
            } else {
                dp[i][j] = dp[i + 1][j];
            }
        }
    }
    LL tmp = 0;
    string res;
    for (int i = 0; i < s.length(); ++i) {
        int j;
        for (j = 0; j < 26; ++j) {
            tmp+=dp[i][j];  //これでi番目から続く部分文字列にjが来るパターンの最後まで行く
            if (tmp>=k) {
                tmp-=dp[i][j];
                tmp++;      //これでi番目から続く部分文字列にjが来るパターンの先頭，つまりjのみの文字列になる
                res+=(j+'a');
                while((s[i]-'a')!=j)i++;
                break;
            }
        }
        if(j>=26 || tmp==k)
            break;
    }
    cout << (res.empty() ? "Eel" : res) << endl;

}
/*　こっちの書き方でも良い
for (int i = 0; i < s.length(); ++i) {
    int j;
    for (j = 0; j < 26; ++j) {
        if (k-dp[i][j] > 0) {
            k-=dp[i][j];
        }else{
            res += (j + 'a');
            k--;
            while((s[i]-'a')!=j)i++;
            break;
        }
    }
    if(j>=26 || k==0)
    break;
}
cout << (res.empty() ? "Eel" : res) << endl;*/
