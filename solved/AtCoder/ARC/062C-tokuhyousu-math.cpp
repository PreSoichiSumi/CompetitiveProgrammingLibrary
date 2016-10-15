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
LL n;
LL t[1001];
LL a[1001];
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>t[i]>>a[i];
    }
    LL pastT,pastA;
    LL nowT=t[0],nowA=a[0];
    for (int i = 1; i < n; ++i) {
        pastT=nowT; pastA=nowA;
        if(t[i]==1 && a[i]==1){
            nowT=max(pastT,pastA);
            nowA=max(pastT,pastA);
        }else if(pastT<=t[i] && pastA<=a[i]){//最小はt[i],a[i]
            nowT=t[i]; nowA=a[i];
        }else if(t[i]<a[i]){//まずtをt[i]の倍数にして,次にa[i]をあわせる．now>=pastならOK．NGなら反対を試す．それでもNGならassert
            LL prod=pastT%t[i]==0? pastT/t[i] :(pastT/t[i] +1);
            nowT=t[i]*prod;
            nowA=nowT/t[i]*a[i];
            if(nowT>=pastT && nowA>=pastA)
                continue;
            prod=pastA%a[i]==0?pastA/a[i]:(pastA/a[i]+1);
            nowA=a[i]*prod;
            nowT=nowA/a[i]*t[i];
            if(nowT<pastT && nowA<pastA)
                throw std::runtime_error("んああ");
        }else{ //aが小さい
            LL prod=pastA%a[i]==0?pastA/a[i]:(pastA/a[i]+1);
            nowA=a[i]*prod;
            nowT=nowA/a[i]*t[i];
            if(nowT>=pastT && nowA>=pastA)
                continue;
            prod=pastT%t[i]==0? pastT/t[i] :(pastT/t[i] +1);
            nowT=t[i]*prod;
            nowA=nowT/t[i]*a[i];
            if(nowT<pastT || nowA<pastA)
                throw std::runtime_error("んああ");
        }
    }
    cout<<nowT+nowA<<endl;
}