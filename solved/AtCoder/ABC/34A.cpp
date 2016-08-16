#include <iostream>
#include <stdio.h>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> P;
const int INF=INT_MAX/2;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

//-----Template---------

int x,y;

int main(int argc, char ** argv) {
    cin>> x>>y;
    if(x<y){
        cout<<"Better"<<endl;
    }else{
        cout<<"Worse"<<endl;
    }



    return 0;
}