#include <iostream>
#include <climits>
#include <array>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 100001;

/*struct edge {   //structとclassの違いは，メンバが初期状態でpublicとなっているかprivateとなっているか
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int x[51];
int n,a;




int main(){
    ios::sync_with_stdio(false);
    cin>>n>>a;
    for (int i = 0; i < n; ++i) {
        cin>>x[i];
    }
    int max=pow(2,n);
    int tmp;
    int res;
    for (int i = 1; i < max; ++i) {
        int sum=0,count=0;
        tmp=i;
        for (int j = 0; j < 16; ++j) {
            if((tmp&0b1)!=0){
                sum+=x[j];count++;
            }
            tmp=tmp>>1;
        }

        if(((sum/count)==a)&&(sum%count==0))res++;
    }
    cout<<res<<endl;
}