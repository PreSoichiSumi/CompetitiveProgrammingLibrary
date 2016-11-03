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
const int MAXN = 1000000000;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/

//-----Template---------
//---エラトステネスのふるい  n以下の素数を列挙---------------
vector<LL> getPrimesEratos(LL n){
    LL rootN= static_cast<long>(sqrt(n));
    bool prime[n+1];
    fill(prime,prime+n+1,true);
    prime[0]=prime[1]=false;
    for (LL i = 2; i <= rootN ; i++) {  //√nを超えないすべての素数で割り切れなければnは素数
        if(prime[i]) {
            for (LL j = i * 2; j <= n; j+=i) prime[j] = false;
        }

    }
    vector<LL> res;
    for(LL i=0;i<=n;i++){
        if(prime[i])
            res.push_back(i);
    }
    return res;
}
void printres(map<LL,LL> hoge){
    cout<<"いきます"<<endl;
    for (auto it=hoge.begin();it!=hoge.end();it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }
}
set<LL> bunkai(LL num,vector<LL>& primes){
    int i=0;
    set<LL> res;
    while(primes[i]<sqrt(num)){
        if(num/primes[i]){
            res.insert(primes[i]);
        }
        i++;
    }
    //printres(res);
    return res;
}
/*
map<LL,LL> bunkai(LL num,vector<LL>& primes){
    int i=0;
    map<LL,LL> res;
    while(primes[i]<sqrt(num)){
        while(num%primes[i]==0){
            num/=primes[i];
            res[primes[i]]++;
        }
        i++;
    }
    printres(res);
    return res;
}*/


vector<LL> koudof(){
    vector<LL> res;
    res.push_back(2);
    res.push_back(4 );
    res.push_back(6 );
    res.push_back(12 );
    res.push_back(24 );
    res.push_back(36 );
    res.push_back(48 );
    res.push_back(60 );
    res.push_back(120 );
    res.push_back(180 );
    res.push_back(240 );
    res.push_back(360 );
    res.push_back(720 );
    res.push_back(840 );
    res.push_back(1260 );
    res.push_back(1680 );
    res.push_back(2520 );
    res.push_back(5040 );
    res.push_back(7560 );
    res.push_back(10080 );
    res.push_back(15120 );
    res.push_back(20160 );
    res.push_back(25200 );
    res.push_back(27720 );
    res.push_back(45360 );
    res.push_back(50400 );
    res.push_back(55440 );
    res.push_back(83160 );
    res.push_back(110880 );
    res.push_back(166320 );
    res.push_back(221760 );
    res.push_back(277200 );
    res.push_back(332640 );
    res.push_back(498960 );
    res.push_back(554400 );
    res.push_back(665280 );
    res.push_back(720720 );
    res.push_back(1081080 );
    res.push_back(1441440 );
    res.push_back(2162160 );
    res.push_back(2882880 );
    res.push_back(3603600 );
    res.push_back(4324320 );
    res.push_back(6486480 );
    res.push_back(7207200 );
    res.push_back(8648640 );
    res.push_back(10810800 );
    res.push_back(14414400 );
    res.push_back(17297280 );
    res.push_back(21621600 );
    res.push_back(32432400 );
    res.push_back(36756720 );
    res.push_back(43243200 );
    res.push_back(61261200 );
    res.push_back(73513440 );
    res.push_back(110270160 );
    res.push_back(122522400 );
    res.push_back(147026880 );
    res.push_back(183783600 );
    res.push_back(245044800 );
    res.push_back(294053760 );
    res.push_back(367567200 );
    res.push_back(551350800 );
    res.push_back(698377680 );
    res.push_back(735134400);
    sort(res.begin(),res.end(),std::greater<LL>());
    return res;
}

vector<LL> getRes(vector<LL> v){
    vector<LL> tmp(100,1);
    bool left=true;
    bool contFlag=true;

    LL vIt=0;
    while(contFlag){
        if(left) {
            for (int i = 0; i < 100; ++i) {
                LL prodNum = v[vIt++];
                if (prodNum * tmp[i]<=MAXN) {
                    tmp[i] *= prodNum;
                }else{
                    contFlag=false;
                    break;
                }
            }
            for (int i = 99; i >=0 ; --i) {
                LL prodNum = v[vIt++];
                if (prodNum * tmp[i]<=MAXN){
                    tmp[i] *= prodNum;
                }else{
                    contFlag=false;
                    break;
                }
            }
        }else{
            for (int i = 99; i >=0 ; --i) {
                LL prodNum = v[vIt++];
                if (prodNum * tmp[i]<=MAXN) {
                    tmp[i] *= prodNum;
                }else{
                    contFlag=false;
                    break;
                }
            }
            for (int i = 0; i < 100; ++i) {
                LL prodNum = v[vIt++];
                if (prodNum * tmp[i]<=MAXN){
                    tmp[i] *= prodNum;
                }else{
                    contFlag=false;
                    break;
                }
            }
        }

        left=!left;
    }
    return tmp;
}

//not pure
LL marge(map<LL,LL>& post,map<LL,LL>& now){
    LL oldNums=0;
    for(auto it=now.begin();it!=now.end();it++) {
        oldNums+=it->second<post[it->first]?0:it->second;
        if (post[it->first] < it->second) {
        //    oldNums += it->second - post[it->first];
            post[it->first] = it->second;
        }
    }
    return oldNums;
}


int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    vector<LL> primes = getPrimesEratos(1000000);
    sort(primes.begin(), primes.end());
    vector<LL> koudo = koudof();
    vector<LL> res(101, 1);
    res[0] = koudo[0];
    LL indexP=0;
    LL indexK=0;
    for (int i = 1; i < 100; ++i) {
        LL pr;
        indexP++;   //同じのにならないようにずらしておく
        while (primes[indexP]<7){
            indexP++;
        }
        indexK=0;
        while(koudo[indexK]*primes[indexP]>=MAXN) {
            indexK++;
        }
        LL restmp=koudo[indexK];
        while(restmp*primes[indexP]<MAXN){  //してもしなくても変わらなかった
            restmp*=primes[indexP];
        }
        res[i]=restmp;
    }
    for (int i = 0; i < 100; ++i) {
        cout<<res[i]<<endl;
    }
}