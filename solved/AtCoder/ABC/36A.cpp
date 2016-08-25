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
int a,b;
int main()
{
    ios::sync_with_stdio(false);
    cin>>a>>b;
    int res=b%a==0 ? b/a : b/a+1;
    cout<< res<<endl;
    return 0;
}