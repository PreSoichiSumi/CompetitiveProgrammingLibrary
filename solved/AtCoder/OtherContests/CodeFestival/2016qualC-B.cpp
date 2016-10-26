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


/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


//-----Template---------

int main(){
    multiset<pair<int,int>,std::greater<pair<int,int>> > memo;
    int k=0,t=0,tmpA=0,last=-1;
    bool flag=false;
    int counter=0;
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>k>>t;
    for (int i = 0; i < t; ++i) {
        cin>>tmpA;
        memo.insert(MP(tmpA,i));
    }
    for (int i = 0; i < k; ++i) {
        flag=false;
        for (auto it=memo.begin();it!=memo.end();it++) {
            if(it->second!=last && it->first>0){
                last=it->second;
                pair<int,int> p=MP(it->first,it->second);
                memo.erase(p);
                memo.insert(MP(p.first-1,p.second));
                flag=true;
                break;
            }
            /*
            if(e.first!=last && e.second>0){    //残ってて，前回のと違うのがあれば
                last=e.first;
                memo[e.first]--;
                flag=true;
                break;
            }*/
        }
        //もし上でなければ残ってるのはlastしかない
        //バグりそう
        if (!flag){
            //auto it=memo.begin();
            //memo[last]--;
            for (auto e:memo) {
                if(e.second==last){
                    pair<int,int> p=e;
                    memo.erase(p);
                    memo.insert(MP(p.first-1,p.second));
                }
            }
            counter++;
        }
    }
    cout<<counter<<endl;
}