#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

#define MODULE 1000000007
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()

template<class T, class U>
inline void chmin(T &t, U f) { if (t > f)t = f; }

template<class T, class U>
inline void chmax(T &t, U f) { if (t < f)t = f; }

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
void swap2(string &s, int i, int j) {
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
}

string getMinStr(string &s) {    //4*4->16
    string m = s;
    for (int i = 0; i < 3; ++i) {
        chmin(m, s.substr(1 + i, 4 - (1 + 1)) + s.substr(0, i + 1));    //substr(i,j)iから長さjぶん
    }
    return m;
}


int n, counter;
string tile[401];
string tmp;
unordered_map<string,int> memo;
unordered_map<string,int> way;

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        tile[i] = getMinStr(tmp);
        memo[tile[i]]++;
    }
    for(auto it:memo){
        int wayNum=1;
        if(it.first[0] == it.first[1] && it.first[1]==it.first[2] && it.first[2]==it.first[3]){
            wayNum=4;
        }else if(it.first[0]==it.first[2] && it.first[1]==it.first[3]){
            wayNum=2;
        }
        way[it.first]=wayNum;
    }
    int ans=0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = 0; k < 4; ++k) {   //上を回転

                string ue = tile[i];        //0-1:mae   2-3:usiro
                string sita = tile[j];    //3-2:mae  	0-1:usiro
                swap2(sita, 0, 2);
                swap2(sita, 1, 3);
                //std::swap(sita[1],sita[3]);
                map<string,int> sokuTile;
                for (int l = 0; l < 4; ++l) {   //側面
                    string tmpTile;
                    if (l != 3) {
                        tmpTile += ue.substr(l, 2);
                        tmpTile += sita.substr(l, 2);
                    } else {
                        tmpTile += ue[3];
                        tmpTile += ue[0];
                        tmpTile += sita[3];
                        tmpTile += sita[0];
                    }
                    tmpTile=getMinStr(tmpTile);
                    sokuTile[tmpTile]++;
                }
                int resTmp=1;
                for (auto it : sokuTile) {
                    if(memo.find(it.first)==memo.end()){
                        resTmp*=0; continue;
                    }

                    if(it.second==1){
                        resTmp*=memo[it.first]*way[it.first];
                    }else{
                        for (int l = 0; l < it.second; ++l) {
                            resTmp*=(memo[it.first]-l)*way[it.first];
                        }
                    }
                }
                ans+=resTmp;

            }
        }
    }

}