#include <bits/stdc++.h>
using namespace std;

#define all(c) ((c).begin()), ((c).end())
#define dump(c) cerr << "> " << #c << " = " << (c) << endl;
#define iter(c) __typeof((c).begin())
#define tr(i, c) for (iter(c) i = (c).begin(); i != (c).end(); i++)
#define REP(i, a, b) for (int i = a; i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//const int INF = 1 << 29;
const ll INF= 1LL << 60;    //1はint
const double EPS = 1e-10;

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
ll stoi(T &str){
    ll ret;
    stringstream ss;
    ss << str;
    ss >> ret;
    return ret;
}

template<class T>
string toString(T i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

struct prepare {
    prepare() {
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(8);
        ios_base::sync_with_stdio(false);
    }
} _prepare;

//priority_queueは最小をtopに持ってくる
class Edge{
public:
    int to,col;
    Edge(){};
    Edge(int b,int c){to=b,col=c;}

    bool operator<(const Edge &rhs) const {
        if (to < rhs.to)
            return true;
        if (rhs.to < to)
            return false;
        return col < rhs.col;
    }

    bool operator>(const Edge &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Edge &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Edge &rhs) const {
        return !(*this < rhs);
    }

    bool operator==(const Edge &rhs) const {
        return to == rhs.to &&
               col == rhs.col;
    }

    bool operator!=(const Edge &rhs) const {
        return !(rhs == *this);
    }
};
class Memo{
public:
    ll point,kaisha,cost;

    bool operator<(const Memo &rhs) const {
        return cost > rhs.cost;
    }
    Memo(ll point, ll kaisha, ll cost) : point(point), kaisha(kaisha), cost(cost) {}
};


int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    unordered_map<ll,vector<Edge> > graph(N);
    vector<unordered_map<int, ll>> dist(N);
    vector<unordered_map<int, bool>> used(N);

    priority_queue<Memo> que;
    rep(i,M){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--;
        b--;
        graph[a].push_back(Edge(b,c));
        graph[b].push_back(Edge(a,c));
        used[a][c]=false;
        used[b][c]=false;
        dist[a][c]=INF;
        dist[b][c]=INF;
    }
    ll ans=INF;
    que.push(Memo(0,-1,0));
    dist[0][1]=true;
    while(!que.empty()){
        int v=que.top().point; //pop
        int col=que.top().kaisha;
        ll cost=que.top().cost;
        if(v==N-1){
            ans=cost;
            break;
        }
        que.pop();
        if(used[v][col])continue;

        used[v][col]=true;

        for(Edge e:graph[v]){
            if(dist[e.to][e.col]>cost+((col==-1 || col!=e.col)?1:0)){
                dist[e.to][e.col]=cost+(col!=e.col?1:0);
                que.push(Memo(e.to,e.col,dist[e.to][e.col]));
            }
        }
    }
    cout<<(ans==INF?-1:ans)<<endl;
}