#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

#define MODULE 1000000007
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second

template<class T, class U>
inline void chmin(T &t, U f) { if (t > f)t = f; }

template<class T, class U>
inline void chmax(T &t, U f) { if (t < f)t = f; }

template<typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val) { //usage: int dp[10][10]; Fill(dp,INF);
    std::fill((T *) array, (T *) (array + N), val);
}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
/*const int MAXN = 100001;

struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/

void replaceStr(string &base, string from, string to) {
    auto pos = base.find(from);
    while (pos != string::npos) {
        base.replace(pos, from.size(), to);
        pos = base.find(from, pos + to.size());
    }
}

//-----Template---------
int n;
bool ame[5000];
int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>n;
    fill(ame,ame+5000,false);
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        replaceStr(s,"-"," ");
        stringstream ss(s);
        int S,E;
        ss>>S>>E;
        S=S/5*5;//5単位で切り下げ
        if(S%100==60)S+=40;
        E=(E+4)/5*5;//切り上げ
        if(E%100==60)E+=40;
        for(int j=S;j<=E;j++){
            ame[j]=true;
        }
    }
    {
        bool in = false;
        int S, E;
        for (int i = 0; i < 5000; i++) {
            if (in && !ame[i]) {
                in = false;
                E=i-1;
                cout<<setw(4)<<setfill('0')<<S<<"-";
                cout<<setw(4)<<setfill('0')<<E<<endl;
            } else if (!in && ame[i]) {
                in=true;
                S=i;
            }
        }
    }
}