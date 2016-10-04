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
/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<int> graph[MAXN];*/

//-----Template---------
unordered_map<char,int> counter;
typedef pair<int,char> pic;
set<pic,std::greater<pic> > st;//mapは<A,B>のpairでソートされる
vector<set<pic>::iterator> vec;
string s;   int N,K;
int main(){
    ios::sync_with_stdio(false);
    cin>>N>>K;
    for (int i = 0; i < N; ++i) {
        cin>>s;
        counter[s[0]]+=1;
    }
    for(auto it=counter.begin();it!=counter.end();it++){
        st.insert(make_pair(it->second,it->first));
    }

    int res=0;
    while (!st.empty()){
        for(set<pic>::iterator it=st.begin();it!=st.end();it++){
            vec.push_back(it);
            if(vec.size()==K) {
                res++;
                break;
            }
        }
        for(auto it : vec){//取り出した値を上書き
            if(((it->first)-1)!=0){//減らす
                pic p=make_pair(it->first,it->second);
                st.erase(p);
                st.insert(make_pair(p.first-1,p.second));
            }else{                  //消す
                st.erase(make_pair(it->first,it->second));
            }
        }
        vec.clear();
    }

    cout<<res<<endl;
}