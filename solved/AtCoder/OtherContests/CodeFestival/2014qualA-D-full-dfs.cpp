#include <bits/stdc++.h>
using namespace std;
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}

typedef long long LL;
const LL INF =LLONG_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX

string aStr;
LL a;
int k;
LL minDist=INF;
void dfs(int keta,int used, bool lower,bool upper,string now){
    if(keta==aStr.length()){
        LL res=stoll(now);
        chmin(minDist,abs(a-res));
        return;
    }
    int num=aStr[keta]-'0';
    if(!lower&&!upper){     //今まで同じ
        for (int i = 0; i < 10; ++i) {
            bool flower=false, fupper=false;
            int nextUsed= used | 1<<i;
            if(__builtin_popcount(nextUsed)>k)continue;
            if(i<num) flower=true;
            if(i>num) fupper=true;
            string next=now+(char)(i+'0');
            dfs(keta+1,nextUsed,flower,fupper,next);
        }
    }else if(lower){//作れる中で最大を作る
        for(int i=9;i>=0;i--){
            int nextUsed=used|1<<i;
            if(__builtin_popcount(nextUsed)>k)continue;
            string next=now+(char)(i+'0');
            dfs(keta+1,nextUsed,true,false,next);
            break;
        }
    }else if(upper){
        for (int i = 0; i < 10; ++i) {
            int nextUsed=used|1<<i;
            if(__builtin_popcount(nextUsed)>k)continue;
            string next=now+(char)(i+'0');
            dfs(keta+1,nextUsed,false,true,next);
            break;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>aStr>>k;
    a=stoll(aStr);
    dfs(0,0,false,false,"");
    {
        string s;
        for (int i = 0; i < aStr.length() - 1; ++i) s += '9';

        if (s.length() != 0) {
            chmin(minDist, abs(a-stoll(s)));
        }
    }
    cout<<minDist<<endl;

}