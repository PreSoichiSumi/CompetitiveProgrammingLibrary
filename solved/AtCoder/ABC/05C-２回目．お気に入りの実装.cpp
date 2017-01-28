#include <bits/stdc++.h>
using namespace std;

#define MP make_pair

typedef pair<int, int> P;
const int hogeee = INT_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX

int n, q;
//int p[2501];
int d[51][51];
map<P, int> rectmemo;
map<int,int> rectmemo2;
vector<P> rects;


int getSum(int x, int y) {
    int res = 0;
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j) {
            res += d[i][j];
        }
    }
    return res;
}

int getrect(int x, int y) {
    return (x >= 0 && y >= 0) ? rectmemo[MP(x, y)] : 0;
}

int getSum2(int sx, int sy, int gx, int gy) {
    return getrect(gx, gy) - getrect(gx, sy - 1) - getrect(sx - 1, gy) + getrect(sx - 1, sy - 1);
}


int main() {
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    //cout<<setw(4)<<setfill('0')<<"hoge"<<endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rectmemo[MP(i, j)] = getSum(i, j);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = i; k < n; ++k) {
                for (int l = j; l < n; ++l) {
                    int masu=(k-i+1)*(l-j+1);
                    int sum=getSum2(i,j,k,l);
                    rectmemo2[masu]=max(rectmemo2[masu],sum);
                    /*if(CONTAINS(rectmemo2,masu)){
                        rectmemo2[masu]=max(rectmemo2[masu],sum);
                    }else{
                        rectmemo2[masu]=sum
                    }*/
                    //rectmemo2.insert(MP((k-i+1)*(l-j+1),getSum2(i,j,k,l)));
                }
            }
        }
    }
    auto it=rectmemo2.begin();
    rects.push_back(MP(it->first,it->second));
    for(;it!=rectmemo2.end();it++){
        P& p=rects.back();
        if(p.second<it->second){
            rects.push_back(MP(it->first,it->second));
        }
    }
    vector<int> res;
    cin >> q;
    int tmp;
    for (int i = 0; i < q; ++i) {
        cin >> tmp;
        auto it = upper_bound(rects.begin(),rects.end(),MP(tmp,hogeee));//tmpは１以上なので，--しても大丈夫
        it--;
        res.push_back(it->second);
    }
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<endl;
    }
}