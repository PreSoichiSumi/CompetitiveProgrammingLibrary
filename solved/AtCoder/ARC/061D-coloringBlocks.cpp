#include <bits/stdc++.h>

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
const int MAXN = 100001;

/*struct edge {   //structとclassの違いは，メンバが初期状態でpublicとなっているかprivateとなっているか
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

//-----Template---------
LL mVertex(LL a, LL b){
    return a * ((LL)1e8) + b;
}
bool isInSpace(LL a, LL b,LL& h, LL& w){
    return 0<a && a<h-1 && 0<b && b<w-1;
}

LL h, w, n;
int a, b;
unordered_map<LL, int> blackCount;
int counter[10]={};
int main() {
    ios::sync_with_stdio(false);
    scanf("%d%d%d", &h, &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);a--;b--;
        for (int j = 0; j < 9; ++j) {
            if(isInSpace(a+dx[j],b+dy[j],h,w))
                blackCount[mVertex(a+dx[j],b+dy[j])]++; //もしmapに対応する値がなければ，新しい要素が作成されそのValueは0
        }
    }
    for(auto it= blackCount.begin();it!=blackCount.end();it++){
        counter[it->second]++;
    }
    int sum=0;
    for (int i = 1; i < 10; ++i) {
        sum+=counter[i];
    }
    cout<<(h-2)*(w-2)-sum<<endl;
    for (int i = 1; i < 10; ++i) {
        cout<<counter[i]<<endl;
    }


}