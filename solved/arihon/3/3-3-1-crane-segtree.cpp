//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define M_PI 3.14159265358979

using namespace std;

typedef pair<int, int> P;
typedef long long LL;

//-----Template---------
#define MAX_N 10010
#define MAX_C 10010

const int ST_SIZE = (1 << 15) - 1;
int N, C;
int L[MAX_N];
int S[MAX_C], A[MAX_N];

double vx[ST_SIZE], vy[ST_SIZE];
double ang[ST_SIZE];

double prv[MAX_N];

void init(int k, int l, int r) {
    ang[k] = vx[k] = 0.0;
    if (r - l == 1) {
        vy[k] = L[l];
    } else {
        int chl = k * 2 + 1, chr = k * 2 + 2;
        init(chl, l, (l + r) / 2);    //再帰的に葉まで
        init(chr, (l + r) / 2, r);
        vy[k] = vy[chl] + vy[chr];  //葉が終わったら親ノードの更新
    }
}

void change(int s, double a, int v, int l, int r) {
    if (s <= l)return;
    else if (s < r) {
        int chl = v * 2 + 1, chr = v * 2 + 2;
        int m = (l + r) / 2;
        change(s, a, chl, l, m);
        change(s, a, chr, m, r);
        if (s <= m)
            ang[v] += a;

        double s = sin(ang[v]), c = cos(ang[v]);
        vx[v] = vx[chl] + (c * vx[chr] - s * vy[chr]);
        vy[v] = vy[chl] + (s * vx[chr] + c * vy[chr]);
    }
}

int main() {
    //ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    while(scanf("%d%d", &N, &C)!=EOF) {

        for (int i = 0; i < N; ++i) scanf("%d", &L[i]);
        for (int i = 0; i < C; ++i) scanf("%d%d", &S[i], &A[i]);

        init(0, 0, N);
        for (int i = 1; i < N; ++i) prv[i] = M_PI;

        for (int i = 0; i < C; ++i) {
            int s = S[i];
            double a = A[i] / 360.0 * 2 * M_PI;
            change(s, a - prv[s], 0, 0, N);
            prv[s] = a;
            printf("%.2f %.2f\n", vx[0], vy[0]);
        }
    }
    return 0;
}