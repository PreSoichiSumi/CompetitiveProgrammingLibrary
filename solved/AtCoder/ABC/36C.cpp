#include <iostream>
#include <climits>
#include <array>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

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
int a[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    map<int,int> compress;
    for (int i = 0; i < n; ++i) {
        compress[a[i]]=0;	//mapからvalueを取得する方法．他にはcompress.at(a[i])=0がある
    }
    int count=0;
    for (auto it=compress.begin();it!= compress.end();it++){	//itrのループ．　
        it->second=count;
        count++;
    }
    for (int i = 0; i < n; ++i) {
        cout<<compress[a[i]]<<endl;
    }

    return 0;
}