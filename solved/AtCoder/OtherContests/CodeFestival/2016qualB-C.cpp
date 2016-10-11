#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

typedef pair<int, int> P;
typedef long long LL;

//-----Template---------

int main(){
    //cout<< fixed << setprecision(10);
    LL w,h;
    cin>>w>>h;

    vector<LL> p(w);
    vector<LL> q(h);

    for (int i = 0; i < w; ++i) cin>>p[i];
    for (int i = 0; i < h; ++i) cin>>q[i];

    vector<pair<LL,int>> hens;
    for (int i = 0; i < w; ++i)
        hens.emplace_back(p[i],0);  //x

    for (int i = 0; i < h; ++i)
        hens.emplace_back(q[i],1);  //y

    sort(hens.begin(),hens.end());

    LL sum=0;
    LL row=0,column=0; //row..x方向に舗装した数　column..y
    for(int i=0;i<hens.size();i++){
        LL a=hens[i].first;
        int t=hens[i].second;
        if(t==0){
            sum+=(h-column+1)*a;
            row++;
        }else{
            sum+=(w-row+1)*a;
            column++;
        }
    }
    cout<<sum<<endl;
}