#include <iostream>
#include <climits>
#include <array>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 100001;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------



int n;
char s[100][100];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin>>s[i][j];

    for (int i = 0; i <n ; ++i) {
        for (int j = n-1; j >=0 ; --j) {
            cout<<s[j][i];
        }
        cout<<endl;
    }
    return 0;
}