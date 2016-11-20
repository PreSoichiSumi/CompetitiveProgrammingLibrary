#include <bits/stdc++.h>
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
    LL tmp = num;
    map<int, int> res;

    if (num < 2)return res;

    for (int i = 0; i < primes.size(); ++i) {
        while (tmp % primes[i] == 0) {
            tmp /= primes[i];
            res[primes[i]]++;
        }
    }
    if (tmp > 1)
        res[tmp]++;
    return res;
}

int countDivisor(map<int, int> decomposed) {
    int counter = 1;
    for (auto it = decomposed.begin(); it != decomposed.end(); it++) {
        counter *= it->second != 0 ? it->second + 1 : 1;
    }
    return counter;
}
#define CAND_THRES 500
vector<LL> primes;
std::mutex iosMtx;
using inv_pqueue = priority_queue<pair<int, int>, vector<pair<int, int> >, std::greater<pair<int, int>>>;

inv_pqueue getNums(int from, int to) {
    inv_pqueue pqueue;
    for (int i = from; i > to; --i) {
        LL divis = countDivisor(primeDecomposition(i, primes));
        if (divis > CAND_THRES) {
            pqueue.push(MP(divis, i));
        }
        if (i % (int) 1e6 == 0) {
            lock_guard<mutex> guard(iosMtx);
            cout << "now : " << i << endl;
        }
        if (pqueue.size() >= RESSIZE + 10)
            pqueue.pop();
    }
    return pqueue;
}

#define MAX_THREADS 12
#define NUM_MAX 1000000000
#define NUM_MIN 800000000

#define DIFF ((NUM_MAX-NUM_MIN)/MAX_THREADS)

//10^9
vector<LL> getInitialSeq(vector<LL> &primes) {
    cout << "creatingInitialSeq..." << endl;
    vector<future<inv_pqueue>> vec;
    for (int i = NUM_MAX; i >= NUM_MIN; i -= DIFF) {
        vec.push_back(async(launch::async, getNums, i, i - DIFF));
    }
    vector<inv_pqueue> resPqtmp;
    for (int i = 0; i < vec.size(); ++i) {
        inv_pqueue res = vec[i].get();
        resPqtmp.push_back(res);
    }

    set<pair<int, int>> tmp;
    for (int i = 0; i < vec.size(); ++i) {
        while (!resPqtmp[i].empty()) {
            tmp.insert(resPqtmp[i].top());
            resPqtmp[i].pop();
        }
    }
    vector<LL> res;
    int counter = 0;
    for (auto it = tmp.rbegin(); it != tmp.rend(); it++) {
        res.push_back(it->second);
        counter++;
        if (counter >= RESSIZE)
            break;
    }
    return res;
}


int main() {
    std::ofstream ofs("C:\\Users\\s-sumi\\ClionProjects\\marathon-match\\nums-1e9to1e9-1e7.txt",
                      ios::trunc);    //trunc: overwrite
    std::ofstream ofs2("C:\\Users\\s-sumi\\ClionProjects\\marathon-match\\divs1e9to1e9-1e7.txt", ios::trunc);
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cout << "geting primes.." << endl;
    primes = getPrimesEratos(100000);
    cout << "geting initial nums.." << endl;
    vector<LL> nums = getInitialSeq(primes);    //10^7
    for (int i = 0; i < nums.size(); ++i) {
        ofs << nums[i] << endl;
    }
    {
        cout << "geting initial divs.." << endl;
        for (int i = 0; i < nums.size(); ++i) {
            cout << "div " << i << " .." << endl;
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
            for (auto it = divMemo.begin(); it != divMemo.end();) {
                ofs2 << (*it);
                it++;
                if (it != divMemo.end())
                    ofs2 << " ";
            }
            ofs2 << endl;
        }
    }
}