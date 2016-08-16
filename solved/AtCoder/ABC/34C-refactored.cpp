#include <iostream>
#include <climits>
#include <array>
#include <cmath>
#include <vector>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;
const int MAXWH = 1000;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
vector<LL> getPrimesEratos(LL n){ //エラトステネスの篩　n以下の素数を列挙
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

//素因数分解を使った組み合わせ計算.mod下でも動作する
LL modComb(LL n, LL k, LL mod) {

    vector<LL> primes=getPrimesEratos(n);
    vector<pair<LL,LL>> res;
    for (LL i = 0; i < primes.size(); i++) {
        LL resTmp=0;
        const LL tmpPrime=primes.at(i);
        for (LL j = tmpPrime; j <= n; j *= tmpPrime) { //ルジャンドル 　[n/(p^i)]↓　i:1~∞
            resTmp += n / j;
            if (j <= n - k) resTmp -= (n - k) / j;
            if (j <= k) resTmp -= k / j;
        }
        res.push_back(MP(tmpPrime,resTmp));
    }

    LL result = 1;
    for (LL i = 0; i < res.size(); i++) {
        LL tmpPrime=res.at(i).first;
        LL tmpNum=res.at(i).second;
        for (int j = 0; j < tmpNum; j++) {
            result *= tmpPrime;
            result %= mod;
        }
    }
    return result;
}
int w, h;

int main(int argc, char **argv) {
    cin >> w >> h;
    w--;
    h--;
    cout << modComb(w + h, h, MODULE) << endl;

    return 0;
}