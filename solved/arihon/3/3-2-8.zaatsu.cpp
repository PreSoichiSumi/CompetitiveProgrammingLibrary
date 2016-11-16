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

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}
template<typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val){ //usage: int dp[10][10]; Fill(dp,INF);
    std::fill( (T*)array, (T*)(array+N), val );
}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
/*const int MAXN = 100001;

struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
#define MAXN 500
int w,h,n;
int X1[MAXN],X2[MAXN],Y1[MAXN],Y2[MAXN];
bool fld[MAXN*3][MAXN*3];

//座圧したい時は，必要な場所と，その前後をとって重複を削除．それを圧縮後のボードの幅とする
//その後，入力データと圧縮後のボードに対応付ける
int compress(int *x1,int *x2,int w){
    vector<int> xs;
    for (int i = 0; i < n; ++i) {
        for (int d = -1; d <=1 ; ++d) {
            int tx1=x1[i]+d,tx2=x2[i]+d;
            if(1<=tx1 && tx1<=w)xs.push_back(tx1);
            if(1<=tx2 && tx2<=w)xs.push_back(tx2);
        }
    }
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end()); //uniqueは，ゴミの始まりへのitを返す
    for(int i=0;i<n;i++){
        x1[i]=find(xs.begin(),xs.end(),x1[i])-xs.begin();
        x2[i]=find(xs.begin(),xs.end(),x2[i])-xs.begin();
    }
    return xs.size();
}

int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>w>>h>>n;
    for (int i = 0; i < n; ++i) {
        cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
    }

    w=compress(X1,X2,w);
    h=compress(Y1,Y2,h);
    memset(fld,0, sizeof(fld));
    for (int i = 0; i < n; ++i) {
        for (int y = Y1[i]; y <=Y2[i] ; ++y) {
            for (int x = X1[i]; x <=X2[i] ; ++x) {
                fld[y][x]=true;
            }

        }
    }
    int ans=0;
    for (int y = 0; y < h; ++y) {//マップが大きいので再帰は危ない．bfs．
        for (int x = 0; x < w; ++x) {
            if(fld[y][x])
                continue;
            ans++;
            queue<pair<int,int>> que;
            que.push(MP(x,y));
            while(!que.empty()){
                int sx=que.front().first,sy=que.front().second;
                que.pop();

                for(int i=0;i<4;i++){
                    int tx = sx+dx[i],ty=sy+dy[i];
                    if(tx<0||w<=tx || ty<0 ||h<=ty)continue;
                    if(fld[ty][tx])continue;
                    que.push(MP(tx,ty));
                    fld[ty][tx] = true;
                }
            }
        }
    }
    cout<<ans<<endl;
}
