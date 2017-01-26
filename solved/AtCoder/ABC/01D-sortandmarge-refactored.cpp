
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

#define MODULE 1000000007
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define CONTAINS(x, y) (x.find(y)!=x.end()) //x<T1,T2>, T1 y
#define getPair(x) MP(x->first,x->second)

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
const int INF = INT_MAX / 2;     //int_max->2*e+9 LLの時はLLONG_MAX
/*const int MAXN = 100001;

struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/

//-----Template---------

int n, si, ei;
string s;
vector<pair<int, int>> memo;
vector<pair<int, int>> res;


int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    //cout<<setw(4)<<setfill('0')<<"hoge"<<endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        si = stoi(s.substr(0, 4));
        ei = stoi(s.substr(5, 4));
        si = si / 5 * 5;
        ei = (ei + 4) / 5 * 5;
        if(ei%100 ==60)ei+=40;
        memo.push_back(MP(si, ei));
    }
    sort(memo.begin(), memo.end());

    res.push_back(memo[0]);
    for (int i = 1; i < memo.size(); ++i) {
        P &last = res.back();
        if (memo[i].first <= last.second) {//重なっている
            last=MP(last.first,max(last.second,memo[i].second));
        } else {
            res.push_back(memo[i]);
        }
    }
    for (int i=0;i<res.size();i++) {
        cout << setw(4) << setfill('0') << res[i].first << "-";
        cout << setw(4) << setfill('0') << res[i].second << endl;
    }



}