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

/*struct edge {   //structとclassの違いは，メンバが初期状態でpublicとなっているかprivateとなっているか
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
string w;   //alpha=26
int chars[26];
int main(){
    ios::sync_with_stdio(false);
    cin>>w;
    for (int i = 0; i < 26; ++i) {
        chars[i]=0;
    }
    for(int i=0;i<w.length();i++){
        chars[w[i]-97]++;
    }
    bool flag=true;
    for (int i = 0; i < 26; ++i) {
        if(chars[i]%2!=0){
            flag=false;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    } else{
        cout<<"No"<<endl;
    }
    cout<<(flag?"Yes":"No")<<endl;
}