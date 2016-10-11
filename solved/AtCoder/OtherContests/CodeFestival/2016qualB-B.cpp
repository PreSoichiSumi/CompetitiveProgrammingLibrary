#include <bits/stdc++.h>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 100001;

struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int n,a,b;
string s;
int kokunaiT=0;
int kaigaiT=0;
bool hoge[100001];
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);

    cin>>n>>a>>b;
    cin>>s;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i]=='a'){
            if((kokunaiT+kaigaiT)<(a+b)) {
                kokunaiT++;
                hoge[i]=true;
            }
        }else if(s[i]=='b'){
            if((kokunaiT+kaigaiT)<(a+b) &&(kaigaiT<b)){
                kaigaiT++;
                hoge[i]= true;
            }
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        cout<<(hoge[i]?"Yes":"No")<<endl;
    }
}