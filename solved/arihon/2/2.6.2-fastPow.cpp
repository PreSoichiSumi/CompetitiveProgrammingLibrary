#include <climits>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

template<class T, class U>
inline void chmin(T &t, U f) { if (t > f)t = f; }

template<class T, class U>
inline void chmax(T &t, U f) { if (t < f)t = f; }

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 1001;

bool isPrime(int n){
    for (int i = 2; i*i<=n; ++i) {
        if(n%i==0)return false;
    }
    return n!=1;
}

LL modPow(LL x,LL n,LL mod){ // O(logN)
    LL res=1;
    while(n>0){
        if(n&1)res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
bool check(int N){
    for(int i=2;i<N;i++){
        if(modPow(i,N,N)!=i)return false;
    }
    return true;
}

int N;
int main() {
    while(true) {
        cin >> N;
        if(N==0)break;
        if (isPrime(N)) {
            cout << N<<" is normal." << endl;
        } else {
            if(check(N)){
                cout<< "The number "<<N<<" is a Carmichael number."<<endl;
            }else{
                cout << N<<" is normal." << endl;
            }
        }

    }
    return 0;
}