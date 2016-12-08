#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXN = 100010;
const int B = 900;
int N, M;
int A[MAXN];
int nums[MAXN];
vector<int> bucket[MAXN/B];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", A+i);
    for (int i = 0; i < N; i++) {
        nums[i] = A[i];
        bucket[i/B].push_back(A[i]);
    }
    sort(nums, nums+N);
    for (int i = 0; i < N/B; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }
    while (M--) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        l--;
        int low = -1, high = N-1;
        while (high - low > 1) {
            int med = (high+low) / 2;
            int x = nums[med];
            int tl = l, tr = r, c = 0;
            while (tl < tr && tl%B != 0) if (A[tl++] <= x) c++;
            while (tl < tr && tr%B != 0) if (A[--tr] <= x) c++;

            while (tl < tr) {
                int b = tl/B;
                c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
                tl += B;
            }
            if (c >= k) high = med;
            else low = med;
        }
        printf("%d\n", nums[high]);
    }
    return 0;
}