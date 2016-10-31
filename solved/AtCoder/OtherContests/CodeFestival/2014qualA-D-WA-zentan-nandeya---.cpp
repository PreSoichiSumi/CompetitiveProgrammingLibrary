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
template<typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val){ //usage: int dp[10][10]; Fill(dp,INF);
    std::fill( (T*)array, (T*)(array+N), val );
}
typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
#define int LL
/*const int MAXN = 100001;

struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/

//-----Template---------
string aStr;
LL a, k;
LL minDist = INF;

void updateMin(set<LL>& used,LL num,LL keta){
    if(used.size()<=k && keta==aStr.length()){
        chmin(minDist,abs(a-num));
    }
}

signed main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> aStr;
    a = stoll(aStr);  //O( |s| )
    cin >> k;
    for (int i = 0; i <= aStr.length(); ++i) {//aに揃える桁数
        set<LL> usedNum;
        LL tmpKeta=0;
        LL tmpNum=0;
        while(tmpKeta<i){
            LL num=aStr[tmpKeta]-'0';
            tmpNum=tmpNum*10+num;
            usedNum.insert(num);
            tmpKeta++;
        }
        for (int j = 0; j < 10; ++j) {
            LL tmpNum2=tmpNum*10+j;
            LL tmpKeta2=tmpKeta+1;
            set<LL> usedNum2=usedNum;
            if(!(tmpKeta==0 && j==0)){
                usedNum2.insert(j);
            }

            if(usedNum2.size()==k){
                for (LL x:usedNum2) {
                    LL tmpNum3=tmpNum2;
                    LL tmpKeta3=tmpKeta2;
                    set<LL> usedNum3=usedNum2;
                    while(tmpKeta3<aStr.length()){
                        tmpNum3=tmpNum3*10+x;
                        tmpKeta3++;
                    }
                    updateMin(usedNum3,tmpNum3,tmpKeta3);
                }
            }else{
                for (int k = 0; k < 10; ++k) {
                    LL tmpNum3=tmpNum2;
                    LL tmpKeta3=tmpKeta2;
                    set<LL> usedNum3=usedNum2;
                    usedNum3.insert(k);
                    while(tmpKeta3<aStr.length()){
                        tmpNum3=tmpNum3*10+k;
                        tmpKeta3++;
                    }
                    updateMin(usedNum3,tmpNum3,tmpKeta3);
                }
            }
        }
    }
    cout<<minDist<<endl;
}