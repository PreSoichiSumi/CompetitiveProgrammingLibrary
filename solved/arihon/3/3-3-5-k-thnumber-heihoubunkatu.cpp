#include <climits>
#include <utility>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MODULE 1000000007
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef pair<int, int> P;
typedef long long LL;

#define MAX_N 100010
#define MAX_M 5001
const int BSIZE = 512;
int nums[MAX_N];
int N, M;
int A[MAX_N];
vector<int> bucket[MAX_N / BSIZE];

int main() {
    //ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; ++i) {
        nums[i] = A[i];
        bucket[i / BSIZE].push_back(A[i]);
    }
    sort(nums, nums + N);
    for (int i = 0; i < N / BSIZE; ++i) {
        sort(bucket[i].begin(), bucket[i].end());
    }
    for (int i = 0; i < M; ++i) {
        int l,r,k;
        scanf("%d %d %d", &l, &r, &k);
        l--;
        int lb = -1, ub = N - 1;
        while (ub - lb > 1) {
            int md = (lb + ub) / 2;
            int x = nums[md];
            int tl = l, tr = r, c = 0;
            while (tl < tr && tl % BSIZE != 0) if (A[tl++] <= x)c++;
            while (tl < tr && tr % BSIZE != 0) if (A[--tr] <= x)c++;
            while (tl < tr) {
                int b = tl / BSIZE;
                c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
                tl += BSIZE;
            }
            if (c >= k)ub = md;
            else lb = md;
        }
        printf("%d\n", nums[ub]);
    }

}