#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAX_M 35
#define MAX_N 10
#define INF 1000000000
using namespace std;

int main(){
    while(true){
        int n, m, p, a, b;
        scanf("%d %d %d %d %d", &n, &m, &p, &a, &b);
        if((n || m || p || a || b) == 0) break;

        int t[1 << MAX_N];
        for(int i = 1; i < (1 << n); i <<= 1) scanf("%d", &t[i]);

        int d[MAX_M][MAX_M];
        memset(d, -1, sizeof(d));
        for(int i = 0; i < p; i++){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            d[x][y] = d[y][x] = z;
        }

        double dp[1 << MAX_N][MAX_M];
        for(int i = 0; i < (1 << MAX_N); i++){
            fill(dp[i], dp[i] + MAX_M, INF);
        }

        dp[(1 << n) - 1][a] = 0;
        double ans = INF;
        // for all S
        for(int i = (1 << n) - 2; i >= 0; i--){
            //for all current city
            for(int j = 1; j <= m; j++){

                // this is dp[i][j]
                // for all used ticket
                for(int bit = 1; bit < (1 << n); bit <<= 1){
                    if((i & bit) != 0) continue; // skip if unused
                    // for all previous city
                    for(int pre = 1; pre <= m; pre++){
                        if(d[pre][j] < 0) continue;
                        dp[i][j] = min(dp[i][j], dp[i | bit][pre] + (double)d[pre][j] / t[bit]);
                    }
                }
                if(j == b) ans = min(ans, dp[i][j]);
            }
        }

        if(ans == INF){
            printf("Impossible\n");
        }else{
            printf("%.3f\n", ans);
        }
    }
}