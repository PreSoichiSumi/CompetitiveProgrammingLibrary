#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

#define MODULE 1000000007
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 1<<24;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------

bool grid[100001]; //false->white
int ss[100001];
int c[100001];
int n,tmpS,tmpC;
LL counter,now;
LL ans[100001];

int N;
bool dat[2*MAXN-1];
void init(int n_){ //O(n)
    N=1;
    while(N<n_){
        N*=2;
    }
    for (int i = 0; i < 2*N-1; ++i) {
        dat[i]=false;
    }
}
void update(int k){ //O(logn) 0-indexedでk番目の値をtrueに変更　つまり黒く塗る
    k+=N-1;
    dat[k]=true;
    while(k>0){
        k=(k-1)/2;
        dat[k]=min(dat[k*2+1],dat[k*2+2]);
    }
}

bool query(int a,int b,int k,int l,int r){ //O(logn)
    if(b>N)return false;
    if(r<=a || b<=l)return false;
    if(a<=l&& r<=b)return dat[k];
    else{
        bool vl=query(a,b,k*2+1,l,(l+r)/2);
        bool vr=query(a,b,k*2+2,(l+r)/2,r);
        return min(vl,vr);
    }
}

int getNextNow(int tmpNow){ //O((logn)^2)
    int lb=tmpNow,ub=n+5;
    while(ub-lb>1){
        int mid=(lb+ub)/2;
        if(query(tmpNow,tmpNow+mid+1,0,0,N)){
            lb=mid;
        }else{
            ub=mid;
        }
    }
    return lb;//連続した黒の最大を返す
}

int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    scanf("%d",&n);
    assert(n<=100001);
    init(100001);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&tmpS,&tmpC);
        ss[i]=tmpS; c[i]=tmpC;
        if(tmpS>100000 || tmpC>100000) {
            assert(n<=100001);
            printf("0\n");
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {//O(n(logn+(logn)^2))
        counter=0;
        now=ss[i];
        while(counter<c[i]){
            if(grid[now]==false){
                grid[now]=true;
                update(now);
                counter++;
            }else{
                now=getNextNow(now);
                now++;
            }
        }
        ans[i]=now;
    }
    for (int i = 0; i < n; ++i) {
        printf("%ld\n",ans[i]);
    }
    return 0;
}