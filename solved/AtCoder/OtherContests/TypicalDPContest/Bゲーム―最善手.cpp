#include <iostream>
#include <stdio.h>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> P;
const int INF = INT_MAX / 2;

/*int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};*/
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

//-----Template---------
int dp[1001][1001]; //両方が最善てAの一番上がi，Bがjの時にAが得るスコア
int A, B;
int a[1001];
int b[1001];
//最善手は各プレーヤー1つに決まります．そのため複数回更新ということはないっぽい
int rec(int i, int j, int k) {
    if(i==A && j==B)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int tmp;
    if (k == 0) {
        tmp=-1;
        if(i<A)chmax(tmp,rec(i+1,j,1)+a[i]);
        if(j<B)chmax(tmp,rec(i,j+1,1)+b[j]);
    } else {
        tmp=INF;
        if(i<A)chmin(tmp,rec(i+1,j,0));
        if(j<B)chmin(tmp,rec(i,j+1,0));
    }
    return dp[i][j]=tmp;

}

int main(int argc, char **argv) {
    cin >> A >> B;
    for (int i = 0; i < A; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < B; i++) {
        cin >> b[i];
    }
    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= B; j++) {
            dp[i][j] = -1;
        }
    }
    //dp[0][0] = 0;
    cout<<rec(0,0,0)<<endl;
    return 0;
}