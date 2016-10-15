#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

#define MODULE 1000000007
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int nowG=0;
int nowP=0;
int point=0;
string s;
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>s;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i]=='g'){
            if(nowP<nowG){
                nowP++;
                point++;
            }else{
                nowG++;
            }
        }else{
            if(nowP<nowG) {
                nowP++;
            }else{
                nowG++;
                point--;
            }
        }
    }
    cout<<point<<endl;
}