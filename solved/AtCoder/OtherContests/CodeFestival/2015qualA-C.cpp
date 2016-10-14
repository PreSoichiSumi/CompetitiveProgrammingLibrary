#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

#define MODULE 1000000007
#define MP make_pair

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
struct homework{
    int a,b;

    bool operator<(const homework &rhs) const { //差の降順になるはず
        return (rhs.a-rhs.b)<(a-b);
    }
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int n,t;
homework W[100001];

bool zenbu(){
    int sum=0;
    for (int i = 0; i < n; ++i) {
        sum+=W[i].b;
    }
    return sum<=t;
}

bool C(int mid){    //終わらせられないか
    int sum=0;
    for (int i = 0; i < mid; ++i) {
        sum+=W[i].b;
    }
    for (int i = mid; i < n; ++i) {
        sum+=W[i].a;
    }
    return sum>t;
}

int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>n>>t;
    for (int i = 0; i < n; ++i) {
        cin>>W[i].a>>W[i].b;
    }
    if(!zenbu()){
        cout<<-1<<endl;
        return 0;
    }

    sort(W,W+n);
    int lb=-1,ub=n;//0-indexed lb行けるubいけない
    while((ub-lb)>1){
        int mid=(ub+lb)/2;
        if(C(mid)){
            lb=mid;
        }else{
            ub=mid;
        }
    }
    if(n==1){
        if(W[0].a<=t){//maniau
            cout<<0<<endl;
        }else if(W[0].b<=t){
            cout<<1<<endl;
        }else{
            cout<<-1<<endl;
        }
    }else {
        cout << ub << endl;
    }

}