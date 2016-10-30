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

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int n;
int x;
int kakikomu[200005];
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>n>>x;
    if(x==1 || x==2*n-1){
        cout<<"No"<<endl;
        return 0;
    }
    if(n==2 && x==2){
        cout<<"Yes"<<endl;
        cout<<"1"<<endl;
        cout<<"2"<<endl;
        cout<<"3"<<endl;
        return 0;
    }
    set<int> unused;
    for (int i = 1; i <= 2*n-1; ++i) {
        unused.insert(i);
    }
    
    if(x==2){
        kakikomu[n-2]=x+2;
        unused.erase(x+2);

        kakikomu[n-1]=x-1;
        unused.erase(x-1);

        kakikomu[n]=x;
        unused.erase(x);

        kakikomu[n+1]=x+1;
        unused.erase(x+1);
    }else{
        kakikomu[n-2]=x-1;
        unused.erase(x-1);

        kakikomu[n-1]=x;
        unused.erase(x);

        kakikomu[n]=x+1;
        unused.erase(x+1);

        kakikomu[n+1]=x-2;
        unused.erase(x-2);
    }
    for (int i = 0; i < 2*n-1 ; ++i) {
        if(kakikomu[i]==0) {
            int num=*unused.begin();
            kakikomu[i] = num;
            unused.erase(num);
        }
    }
    cout<<"Yes"<<endl;
    for (int i = 0; i < 2*n-1; ++i) {
        cout<<kakikomu[i]<<endl;
    }
        
}