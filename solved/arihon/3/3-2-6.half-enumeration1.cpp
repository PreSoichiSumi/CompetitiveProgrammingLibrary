
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef pair<int, int> P;
typedef long long LL;


//-----Template---------
int n;
int A[4001];
int B[4001];
int C[4001];
int D[4001];
vector<int> ab;
vector<int> cd;
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ab.push_back(A[i]+B[j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cd.push_back(C[i]+D[j]);
        }
    }
    sort(ab.begin(),ab.end());
    LL counter=0;
    for (int i = 0; i < cd.size(); ++i) {
        counter+=upper_bound(ab.begin(),ab.end(),-cd[i])-lower_bound(ab.begin(),ab.end(),-cd[i]);
        //counter+=upb-lob; //another way: distance(upb,lob)
    }
    cout<<counter<<endl;



}