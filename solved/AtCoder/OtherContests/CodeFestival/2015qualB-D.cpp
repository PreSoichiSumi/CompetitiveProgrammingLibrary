#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

#define MODULE 1000000007
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second

template<class T, class U>
inline void chmin(T &t, U f) { if (t > f)t = f; }

template<class T, class U>
inline void chmax(T &t, U f) { if (t < f)t = f; }

typedef pair<int, int> P;
typedef long long LL;
//int_max->2*e+9
//const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/

//-----Template---------
LL n, tmpS, tmpC;
map<LL, LL> memo;   //範囲の開始と，次の白をメモ

int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &tmpS, &tmpC);

        auto it = memo.begin();
        LL startKey = -1;
        LL lastKey=-1;
        vector<LL> deleteKeys;
        LL nowS=it->second;//最初の白を指す
        LL nowC=tmpC;

        while (it != memo.end() && nowC!=0) {  //探して，消して，追加する

            if (it->first <= nowS && nowS <= it->second) {    //secondまで移動

                startKey=it->first;
                lastKey=it->second;
                deleteKeys.push_back(startKey);
                auto it2 = it;
                auto it2next=it2;
                it2next++;

                while(it2next!=memo.end()){
                    LL dist = it2next->first - it->second;
                    if(nowC>=dist){ //つなげる
                        nowC-=dist;
                        nowS=it2next->first;
                        lastKey=it2next->second;
                    }else{  //終わり
                        nowC=0;
                        nowS=it2->first;
                        lastKey=it2->second+dist;
                    }
                    //nowC -= nowC > dist ? dist : nowC; //次の区間までの距離より進める量が大きいなら距離だけ引く

                    deleteKeys.push_back(it->first);

                    if(nowC==0) {
                        break;
                    }

                    it2++;
                    it2next++;
                }

                for (LL tmp:deleteKeys) {
                    memo.erase(tmp);
                }
                if(nowC==0) {
                    memo.insert(startKey, lastKey);
                }else{
                    memo.insert(startKey, lastKey+nowC);
                }

            } else if (nowS < it->first) {   //
                startKey=nowS;
                LL dist1=it->first-nowS;
                if(nowC<dist1){
                    lastKey=nowS+nowC;
                    memo.insert(startKey,lastKey);
                    break;
                }else if(nowC==dist1){
                    lastKey=it->second;
                    memo.erase(it->first);
                    memo.insert(startKey,lastKey);
                    break;
                }else{
                    nowC-=dist1;
                    nowS=it->first;
                }
                //つながる
                auto it2 = it;
                auto it2next=it2;
                it2next++;

                while(it2next!=memo.end()){
                    LL dist = it2next->first - it->second;
                    if(nowC>=dist){ //つなげる
                        nowC-=dist;
                        nowS=it2next->first;
                        lastKey=it2next->second;
                    }else{  //終わり
                        nowC=0;
                        nowS=it2->first;
                        lastKey=it2->second+dist;
                    }
                    //nowC -= nowC > dist ? dist : nowC; //次の区間までの距離より進める量が大きいなら距離だけ引く

                    deleteKeys.push_back(it->first);

                    if(nowC==0) {
                        break;
                    }

                    it2++;
                    it2next++;
                }

                for (LL tmp:deleteKeys) {
                    memo.erase(tmp);
                }
                if(nowC==0) {
                    memo.insert(startKey, lastKey);
                }else{
                    memo.insert(startKey, lastKey+nowC);
                }
            }

            it++;
            if(it==memo.end())
                memo.insert(tmpS,tmpS+tmpC);
        }
    }

}