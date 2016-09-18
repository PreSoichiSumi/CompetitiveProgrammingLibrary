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

//------繰り返し二乗法
LL fastPow(LL x,LL n){ // O(logN)
    LL res=1;
    while(n>0){
        if(n&1)res=res*x;
        x=x*x;
        n>>=1;
    }
    return res;
}

LL res=0;

void sumVector(vector<LL> &nums){
    for (int i = 0; i < nums.size(); ++i) {
        res+=nums.at(i);
    }
}

string s;

void rec(int index,LL num, vector<LL> emittedNums){
    if(index!=s.length()) {
        rec(index + 1, num * 10 + s.at(index) - 48, emittedNums);
        emittedNums.push_back(num);
        rec(index + 1, s.at(index) - 48, emittedNums);
    }else{
        sumVector(emittedNums);
        res+=num;
        return;
    }
}

int main() {
    cin>>s;
    vector<LL> v;
    rec(0,0,v);
    cout<<res/2<<endl;
    return 0;
}