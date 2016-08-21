#include <iostream>
#include <climits>
#include <array>
#include <cmath>
#include <vector>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

typedef pair<int, int> P;
typedef long long LL;
const int MAXN = 200001;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

//-----Template---------
int n, q;
int l[MAXN], r[MAXN];
int memo[MAXN];


int main(){
	cin >> n >> q;
	for (int i = 0; i < q; ++i){
		cin >> l[i] >> r[i];
	}
	fill(begin(memo), end(memo), 0);
	for (int i = 0; i < q; ++i){
		memo[l[i] - 1]++;
		memo[r[i]]--;
	}
	int count=0;
	for (int i = 0; i < n; ++i)
	{
		count += memo[i];
		cout << abs(count) % 2;
	}
	cout << endl;

	return 0;
}