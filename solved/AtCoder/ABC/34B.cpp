#include <iostream>
#include <stdio.h>
#include <queue>
#include <climits>
using namespace std;
 
typedef pair<int,int> P;
typedef long long LL;
const int INF=INT_MAX/2;
 
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
 
//-----Template---------
 
LL x,y;
 
int main(int argc, char ** argv) {
    cin>> x;
    if(x%2==0){
        cout<<x-1<<endl;
    }else{
        cout<<x+1<<endl;
    }
 
 
 
    return 0;
}