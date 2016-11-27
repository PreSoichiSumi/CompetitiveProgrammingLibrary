#define _USE_MATH_DEFINES
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
vector<edge> graph[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};*/

//-----Template---------
#define MAX_N 10001
#define MAX_C 10001


const int ST_SIZE=(1<<15)-1;
int N,C;
int L[MAX_N];
int S[MAX_C],A[MAX_N];

double vx[ST_SIZE],vy[ST_SIZE];
double ang[ST_SIZE];

double prv[MAX_N];

void init(int k, int l, int r){
    ang[k]=vx[k]=0.0;
    if(r-l==1){
        vy[k]=L[l];
    }else{
        int chl=k*2+1,chr=k*2+2;
        init(chl,l,(l+r)/2);
        init(chr,(l+r)/2,r);
        vy[k]=vy[chl]+vy[chr];
    }
}

void change(int s,double a,int v,int l,int r){
    if(s<=l)return ;
    else if(s<r){
        int chl=v*2+1,chr=v*2+2;
        int m=(l+r)/2;
        change(s,a,chl,l,m);
        change(s,a,chr,m,r);
        if(s<=m)ang[v]+=a;
        double s=sin(ang[v]),c=cos(ang[v]);
        vx[v]=vx[chl]+(c*vx[chr]-s*vy[chr]);
        vy[v]=vy[chr]+(s*vx[chr]+c*vy[chr]);
    }
}


int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>N>>C;
    for (int i = 0; i < N; ++i) {
        cin>>L[i];
    }
    for (int i = 0; i < C; ++i) {
        cin>>S[i]>>A[i];
    }
    init(0,0,N);
    for(int i=1;i<N;i++){
        prv[i]=M_PI;
    }
    for(int i=0;i<C;i++){
        int s=S[i];
        double a=A[i]/360.0*2*M_PI;
        change(s,a-prv[s],0,0,N);
        prv[s]=a;
        printf("%.2f %.2f\n",vx[0],vy[0]);
    }
}