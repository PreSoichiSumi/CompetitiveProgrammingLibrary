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

int t,n;
vector<LL> ans;
std::string fileName="C:\\Users\\s-sumi\\ClionProjects\\Atcoder-new\\output.txt";
std::ofstream writing_file(fileName,std::ios::out);
int main() {
    //writing_file.open(fileName,std::ios::out);
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d",&n);
        int x[n];
        int y[n];
        for (int j = 0; j < n; ++j) {
            scanf("%d",&x[j]);
        }
        for(int j=0;j<n;j++){
            scanf("%d",&y[j]);
        }
        sort(x,x+n);
        sort(y,y+n,std::greater<int>());
        LL sum=0;
        for (int j = 0; j < n; ++j) {
             sum+=(LL)x[j]*(LL)y[j];
        }
        ans.push_back(sum);
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout<<"Case #"+to_string(i+1)+": "+to_string(ans.at(i))<<endl;
        writing_file<<"Case #"+to_string(i+1)+": "+to_string(ans.at(i))<<endl;
    }


}