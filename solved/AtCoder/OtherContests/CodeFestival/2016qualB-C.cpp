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
int n;
int a[100001];
int main(){
	ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	LL counter=a[0]-1;
	int maxNum=1;
	for (int i = 1; i < n; i++) {
		if(a[i]<(maxNum+2)) {//maxnum+1が割れる数の最小値，maxnum+2より小さいとあまりが出ない
			chmax(maxNum,a[i]);
			continue;
		}

		if(a[i]%(maxNum+1)!=0) { //a[i]が割れる数の最小の倍数なら
			counter+=a[i]/(maxNum+1);
			chmax(maxNum,a[i]%(maxNum+1));
		}else{
			a[i]-=maxNum+2;
			counter+=a[i]/(maxNum+1) +1;
			chmax(maxNum,a[i]%(maxNum+1));
		}
	}
	cout<<counter<<endl;
}