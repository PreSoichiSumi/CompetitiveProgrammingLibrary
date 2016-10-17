#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

#define module 1000000007
#define mp make_pair
#define all(v) (v).begin(),(v).end()

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
//pure
LL compress(vector<int>& v){ //10^3*4->10^12
    LL r=0;
    for (int i = 0; i < v.size(); ++i) {
        r=r*1000+v[i];
    }
    return r;
}

vector<int> getMinVector(vector<int> v){
    vector<vector<int>> tmpVecs;
    tmpVecs.push_back(v);
    for (int i = 1; i < 4; ++i) {
        rotate(v.begin(),v.begin()+1,v.end());  //begin to end, begin+1が先頭に来るように左に回す
                                                //右に回すときには rotate(v.rbegin(),v.rbegin()+1,v.rend()) とrbeginを使う
        tmpVecs.push_back(v);
    }
    //sort(all(tmpVecs));   //こっちでも良いけど，lambda練習用に↓
    sort(tmpVecs.begin(),tmpVecs.end(),[](vector<int>& a,vector<int>& b){//ちゃんと参照渡しするように
        if(a.size()==0)return true;
        for (int i = 0; i < a.size(); ++i) {
            if(a[i]!=b[i]){
                return a[i]<b[i];
            }
        }
        return true;
    });
    return tmpVecs[0];
}
//pure
int getWay(vector<int> v){
    set<vector<int>> s;
    for (int i = 0; i < 4; ++i) {
        s.insert(v);
        rotate(v.begin(),v.begin()+1,v.end());
    }
    return 4/s.size();
}
//pure　こっちでもいい
/*int getWay(vector<int>& v){
    int wayNum=1;
    if(v[0] == v[1] && v[1]==v[2] && v[2]==v[3]){
        wayNum=4;
    }else if(v[0]==v[2] && v[1]==v[3]){
        wayNum=2;
    }
    return wayNum;
}*/

int n;
vector<vector<int>> tile(401);
unordered_map<LL,LL> cnt;
unordered_map<LL,LL> way;

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        vector<int> v(4);
        for (int j = 0; j < 4; ++j) {
            cin>>v[j];
        }
        v=getMinVector(v);
        tile[i]=v;
        LL minTile=compress(v);
        cnt[minTile]++;
        way[minTile]= getWay(v);
    }
    LL ans=0;
    for (int i = 0; i < n; ++i) {
        vector<int> ue = tile[i];
        LL ueLL=compress(ue);
        cnt[ueLL]--;
        for (int j = i + 1; j < n; ++j) {
            vector<int> sita = tile[j];
            LL sitaLL=compress(sita);
            cnt[sitaLL]--;

            swap(sita[1],sita[3]);
            for (int k = 0; k < 4; ++k) {   //sitaを回転
                map<LL,int> sokuTile;
                for (int l = 0; l < 4; ++l) {   //側面のタイルを書き出す
                    vector<int> tmpTile(4);
                    tmpTile[0]=ue[l];
                    tmpTile[1]=ue[(l+3)%4];
                    tmpTile[2]=sita[(l+3)%4];
                    tmpTile[3]=sita[l];
                    /*tmpTile[0]=ue[(l+1)%4];   こっちはらて氏のパクリ
                    tmpTile[1]=ue[l];
                    tmpTile[2]=sita[l];
                    tmpTile[3]=sita[(l+1)%4];*/

                    tmpTile=getMinVector(tmpTile);
                    sokuTile[compress(tmpTile)]++;
                }
                LL resTmp=1;
                for (auto it : sokuTile) {
                    if(cnt.find(it.first)==cnt.end()){
                        resTmp*=0; break;
                    }

                    if(it.second==1){
                        resTmp*=cnt[it.first]*way[it.first];
                    }else{
                        for (int l = 0; l < it.second; ++l) {
                            resTmp*=(cnt[it.first]-l)*way[it.first];
                        }
                    }
                }
                ans+=resTmp;

                rotate(sita.begin(),sita.begin()+1,sita.end());
            }
            cnt[sitaLL]++;
        }
        cnt[ueLL]++;
    }
    cout<<ans/3<<endl;
}