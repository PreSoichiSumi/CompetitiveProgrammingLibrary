#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;
#define int long long
#define MODULE 1000000007
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef pair<int, int> P;
typedef long long LL;
const LL INF = LLONG_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
string aStr;
LL a,k;
LL minDist=INF;
void getMinNum(LL now,set<int> used,int keta){
    if(keta>=aStr.length()){
        chmin(minDist,abs(now-a));
        return;
    }
    LL tmpNow=now*10;
    if(used.size()<k) {
        set<int> used1 = used;
        used1.insert(aStr[keta] - '0');
        set<int> used2 = used;
        used2.insert((aStr[keta] - '0' + 1) % 10);
        set<int> used3 = used;
        used3.insert((aStr[keta] - '0' + 9) % 10);

        getMinNum(tmpNow + aStr[keta] - '0', used1, keta + 1);
        getMinNum(tmpNow + (aStr[keta] - '0' + 1) % 10, used2, keta + 1);
        getMinNum(tmpNow + (aStr[keta] - '0' + 9) % 10, used3, keta + 1);
    }else{
        //LL mindiff=INF;
        for(int i:used){
            getMinNum(tmpNow+i,used,keta+1);
        }
    }
}
signed main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>> aStr;
    a=stoll(aStr);
    cin>>k;
    set<int> hoge;
    getMinNum(0,hoge,0);
    cout<<minDist<<endl;
}