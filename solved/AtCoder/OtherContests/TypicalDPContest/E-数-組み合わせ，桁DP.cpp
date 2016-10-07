#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MP make_pair

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

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

int D;
string N;
//dp[i][j][k]　iより前まで読んで，
LL dp[10001][100][2];  //kについて　1..Nより大きくなる可能性がある　/　0 ない
//10^6 * 10  10...0-9ループ分

//-----Template---------
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>D; cin>>N;
    //dp[0][0][0]=1;
    dp[0][0][1]=1;
    for (int i = 0; i < N.length(); ++i) {
        for (int j = 0; j < 100; ++j) {
            for (int k = 0; k < 2; ++k) {
                if(dp[i][j][k]==0)
                    continue;

                if(k==0){
                    for (int l = 0; l < 10; ++l) {
                        dp[i+1][(j+l)%D][0]+=dp[i][j][0];
                        dp[i+1][(j+l)%D][0]%=MOD;
                    }
                } else{
                    for (int l = 0; l < N[i]-'0'; ++l) {
                        dp[i+1][(j+l)%D][0]+=dp[i][j][1];
                        dp[i+1][(j+l)%D][0]%=MOD;
                    }

                    dp[i+1][(j+N[i]-'0')%D][1]+=dp[i][j][1];
                    dp[i+1][(j+N[i]-'0')%D][1]%=MOD;
                }
            }
        }
    }
    LL ans=(dp[N.length()][0][0]+dp[N.length()][0][1]-1)%MOD;
    cout<<ans<<endl;

}