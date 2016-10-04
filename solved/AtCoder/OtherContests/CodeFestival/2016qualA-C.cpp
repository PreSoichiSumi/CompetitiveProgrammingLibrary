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
vector<edge> graph[MAXN];*/

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
//-----Template---------
bool isLoopable(char c,int tmpK){
    return ('z'-c+1)<=tmpK;
}
int getRemainK(char c,int tmpK){
    return tmpK-('z'-c+1);
}
string s;
int K,tmp;
int main(){
    ios::sync_with_stdio(false);
    cin>>s;
    cin>>K;
    tmp=K;
    for(int i=0;i<s.length();i++){
        if(isLoopable(s[i],tmp) && s[i]!='a'){
            tmp=getRemainK(s[i],tmp);
            s[i]='a';
        }
    }
    if(tmp!=0){
        tmp=tmp%26;
        if(isLoopable(s[s.length()-1],tmp)){
            s[s.length()-1]='a'+getRemainK(s[s.length()-1],tmp);
        }else{
            s[s.length()-1]+=tmp;
        }
    }
    cout<<s<<endl;

}