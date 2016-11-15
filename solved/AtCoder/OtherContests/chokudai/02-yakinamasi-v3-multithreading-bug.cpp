#include <bits/stdc++.h>
//#include <thread>
//#include <functional>
//#include <boost/asio.hpp>
//#include <boost/asio/io_service.hpp>
//#include <boost/bind.hpp>
//#include <boost/thread/thread.hpp>

//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

#define MODULE 1000000007
#define RESSIZE 10000
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
//---エラトステネスのふるい  n以下の素数を列挙--------------- O(nlog(logn))
vector<LL> getPrimesEratos(LL n) {
    LL rootN = static_cast<long>(sqrt(n));
    bool prime[n + 1];
    fill(prime, prime + n + 1, true);
    prime[0] = prime[1] = false;
    for (LL i = 2; i <= rootN; i++) {  //√nを超えないすべての素数で割り切れなければnは素数
        if (prime[i]) {
            for (LL j = i * 2; j <= n; j += i) prime[j] = false;
        }
    }
    vector<LL> res;
    for (LL i = 0; i <= n; i++) {
        if (prime[i])
            res.push_back(i);
    }
    return res;
}
//素因数分解
//<prime,count> O(logn)
map<int, int> primeDecomposition(LL num, vector<LL> &primes) {
    map<int, int> res;
    for (int i = 0; i < primes.size(); ++i) {
        while (num % primes[i] == 0) {
            num /= primes[i];
            res[primes[i]]++;
        }
    }
    return res;
}

int countDivisor(map<int, int> decomposed) {
    int counter = 1;
    for (auto it = decomposed.begin(); it != decomposed.end(); it++) {
        counter *= it->second != 0 ? it->second : 1;
    }
    return counter;
}
//priority_queue<pair<int,int>> pqueue;
vector<LL> primes;
//std::mutex pqMtx;
std::mutex iosMtx;
/*void updatePqueue(int from,int to){
     for (int i = from; i >to ; --i) {
         LL divis = countDivisor(primeDecomposition(i,primes));
         if(divis>650) {
             //lock_guard<mutex> guard(pqMtx);
             //pqueue.push(MP(divis, i));
         }
         if(i%(int)1e6==0) {
             lock_guard<mutex> guard(iosMtx);
             cout << "now : " << i << endl;
         }
     }
 }*/
priority_queue< pair<int,int>,vector<pair<int,int> > ,std::greater<pair<int,int>>> getNums(int from,int to){
    priority_queue< pair<int,int>,vector<pair<int,int> > ,std::greater<pair<int,int>>> pqueue;
    for (int i = from; i >to ; --i) {
        LL divis = countDivisor(primeDecomposition(i,primes));
        if(divis>650){
            pqueue.push(MP(divis,i));
        }
        if(i%(int)1e6==0) {
            lock_guard<mutex> guard(iosMtx);
            cout << "now : " << i << endl;
        }
        if(pqueue.size()>=RESSIZE+10)
            pqueue.pop();
    }
    return pqueue;
}

//#define DIFF 20000000
#define DIFF 1000000

//10^9
vector<LL> getInitialSeq(vector<LL> &primes) {
    //priority_queue<pair<int, int>,vector<pair<int,int>>,std::greater<pair<int,int>>()> pqueue;

    cout<<"creatingInitialSeq..."<<endl;
    /*for (LL i = (int) 1e9; i > (int) 1e8//-(int)1e7; i--) {    //10^9 * log10^9
        LL divis = countDivisor(primeDecomposition(i, primes));
        if(divis>650)
            pqueue.push(MP(divis, i));
        if(i%(int)1e5==0)
            cout<<i<<endl;
    }*/
    /*vector<thread> thread_pool;
    for (int i = (int)1e9; i >=8e8 ; i-=DIFF) {
        thread_pool.push_back(thread(updatePqueue,i,i-DIFF));
    }
    for (int i = 0; i < thread_pool.size(); ++i) {
        thread_pool[i].join();
    }
    vector<LL> res;
    {
        lock_guard<mutex> guard(pqMtx);
        for (int i = 0; i < (int) 1e4; ++i) {
            res.push_back(pqueue.top().second);
            pqueue.pop();
        }
    }
     return res;
     */
    vector<future<priority_queue< pair<int,int>,vector<pair<int,int> > ,std::greater<pair<int,int>>>>> vec ;
    //for (int i = (int)1000000000; i >=800000000 ; i-=DIFF) {
    for (int i = (int)1000000000; i >=990000000 ; i-=DIFF) {
        vec.push_back(std::async(std::launch::async,getNums,i,i-DIFF));
    }

    priority_queue<pair<int,int>> qres;
    vector<priority_queue< pair<int,int>,vector<pair<int,int> > ,std::greater<pair<int,int>>>> resPqtmp;
    for (int i = 0; i < vec.size(); ++i) {
        resPqtmp.push_back(vec[i].get());
    }
    for (int i = 0; i < vec.size(); ++i) {
        while(!resPqtmp[i].empty()){
            qres.push(resPqtmp[i].top());
            resPqtmp[i].pop();
        }
    }


    vector<LL> res(RESSIZE);
    for (int i = 0; i < RESSIZE; ++i) {
        pair<int,int> pa=qres.top();
        res[i]=pa.second;
        qres.pop();
    }
    return res;
}


int main() {
    std::ofstream ofs("C:\\Users\\s-sumi\\ClionProjects\\marathon-match\\nums-1e9to1e9-1e7.txt",ios::trunc);
    std::ofstream ofs2("C:\\Users\\s-sumi\\ClionProjects\\marathon-match\\divs1e9to1e9-1e7.txt",ios::trunc);
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cout<<"geting primes.."<<endl;
    primes = getPrimesEratos(100000);
    cout<<"geting initial nums.."<<endl;
    vector<LL> nums = getInitialSeq(primes);    //10^7
    {
        lock_guard<mutex> guard(iosMtx);
        vector<set<int>> divs;
        cout<<"geting initial divs.."<<endl;
        for (int i = 0; i < nums.size(); ++i) {
            cout<<"div "<<i<<" .."<<endl;
            map<int, int> dec = primeDecomposition(nums[i], primes);
            set<int> divMemo;
            set<int> divTmp;
            for (auto it = dec.begin(); it != dec.end(); it++) {
                for (int j = 0; j < it->second; ++j) {
                    for (auto it2 = divMemo.begin(); it2 != divMemo.end(); it2++) {
                        divTmp.insert((*it2) * (it->first));
                    }
                    divMemo.insert(it->first);
                    divMemo.insert(divTmp.begin(), divTmp.end());
                }
            }
            divs.push_back(divMemo);
        }
        for (int i = 0; i < nums.size(); ++i) {
            ofs<<nums[i]<<endl;
        }
        for (int i = 0; i < divs.size(); ++i) {
            for (auto it = divs[i].begin(); it != divs[i].end();){
                ofs2<<(*it);
                it++;
                if(it!=divs[i].end())
                    ofs2<<" ";
            }
            ofs2<<endl;
        }
    }
}

