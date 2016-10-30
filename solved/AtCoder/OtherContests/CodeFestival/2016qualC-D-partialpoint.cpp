#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

#define MODULE 1000000007
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef pair<int, int> P;
typedef long long LL;
const LL INF = LLONG_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int h,w;
char color[301][3+1];
LL dp[301][301][301];
LL cost1[301][301];
LL cost2[301][301];
string tmpS;
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>> h>>w;
    assert(w<=3);
    for (int i = 0; i < h; ++i) {
        cin>>tmpS;
        for (int j = 0; j < w; ++j) {
            color[i][j]=tmpS[j];
        }
    }

    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j <= h; ++j) {
            for (int k = 0; k <= h; ++k) {
                dp[i][j][k]=INF;
            }
        }
    }

    for (int i = 0; i <=h; ++i) {
        for (int j = 0; j <=h; ++j) {
            if(i==0 || j==0){
                LL tmp=0;
                for (int k = 0; k <h; ++k) {//0-h-1まで回して，変なとこを飛ばす
                    if(k-i>=0 && k-j>=0 && color[k-i][0]==color[k-j][1])
                        tmp++;
                }
                cost1[i][j] = tmp;
            }else{
                cost1[i][j] = cost1[i-1][j-1] - (color[h-i][0]==color[h-j][1]?1:0);
            }
        }
    }
    for (int i = 0; i <=h; ++i) {
        for (int j = 0; j <=h; ++j) {
           if(i==0 || j==0){
                LL tmp=0;
                for (int k = 0; k <h; ++k) {

                    if(k-i>=0 && k-j>=0 && color[k-i][1]==color[k-j][2])
                        tmp++;
                }
                cost2[i][j] = tmp;
            }else {
                cost2[i][j] = cost2[i-1][j-1] - (color[h-i][1]==color[h-j][2]?1:0);
            }
        }
    }


    dp[0][0][0]=0;
    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j <= h; ++j) {
            for (int k = 0; k <= h; ++k) {
                /*if(i>0){
                    chmin(dp[i][j][k], dp[i-1][j][k] + cost1[i-1][j]);
                }
                if(j>0){
                    chmin(dp[i][j][k], dp[i][j-1][k] + cost1[i][j-1] + cost2[j-1][k]);
                }
                if(k>0) {
                    chmin(dp[i][j][k], dp[i][j][k - 1] + cost2[j][k - 1]);
                }*/

                LL tmpA=i>0?dp[i-1][j][k] + cost1[i-1][j]:INF; //どっちでも行ける．コンテスト中はi-1>0?と書いていた..
                LL tmpB=j>0?dp[i][j-1][k] + cost1[i][j-1] + cost2[j-1][k]:INF;
                LL tmpC=k>0?dp[i][j][k-1] + cost2[j][k-1]:INF;
                dp[i][j][k]=min(dp[i][j][k],min(tmpA,min(tmpB,tmpC)));
            }
        }
    }
    cout<< dp[h][h][h]<<endl;
}