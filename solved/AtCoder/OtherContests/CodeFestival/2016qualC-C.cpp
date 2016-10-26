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
LL n;
LL t[100001];
LL a[100001];
LL tCount[100001];
LL tMemo[100001];   //最大値を書き込む．tCountが1で最大値がaと食い違えばありえない
LL aCount[100001];
LL aMemo[100001];
LL finalCount[100001];
LL res=1;
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&t[i]);
        if(i==0){
            tCount[0]=1;
        }else{
            tCount[i]=t[i]!=t[i-1]?1:t[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = n-1; i >=0; --i) {
        if(i==n-1){
            aCount[n-1]=1;
        }else{
            aCount[i]=a[i]!=a[i+1]?1:a[i];
        }
    }
    bool flag=true;
    for (int i = 0; i < n; ++i) {
        if(tCount[i]==1 && t[i]>a[i]) {
            flag = false;
        }
        if(aCount[i]==1 && a[i]>t[i]){
            flag=false;
        }

        finalCount[i]=min(tCount[i],aCount[i]);
    }
    for (int i = 0; i < n; ++i) {
        res*=finalCount[i];
        res%=MODULE;
    }

    cout<<(flag?res:0)<<endl;




}