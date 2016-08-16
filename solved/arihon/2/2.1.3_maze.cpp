#include <iostream>
#include <stdio.h>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> P;

const int INF=INT_MAX/2;
//const int INF=1000;
const int MAXRC=50;
char maze[MAXRC + 1][MAXRC + 1];
int dist[MAXRC + 1][MAXRC + 1];
int r,c,sx,sy,gx,gy;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

int bfs(){
    std::queue<P> qu;
    qu.push(P(sx,sy));
    dist[sx][sy]=0;
    while (!qu.empty()){
        P now=qu.front();qu.pop();
        if(now.first==gx && now.second==gy)
            break;
        for (int i = 0; i < 4; i++) {
            int x=now.first+dx[i];
            int y=now.second+dy[i];
            if(0<=x && x<r && 0<=y && y<c && maze[x][y]=='.' && dist[x][y]==INF){
                dist[x][y]=dist[now.first][now.second]+1;
                qu.push(P(x,y));
            }

        }
    }
    return dist[gx][gy];
}

void printMat(int* arr){
    for (int i = 0; i < r; i++) {
        for (int j = 0; j <c ; j++) {
            cout<<arr[i*(MAXRC+1)+j]<<" \t ";
        }
        cout<<endl;
    }
}


int main(int argc, char ** argv) {
    cin>> r>>c;
    cin>>sx>>sy;
    cin>>gx>>gy;
    sx--;sy--;gx--;gy--;
    for (int i = 0; i < r ; i++) {
        scanf("%s", maze[i]);
    }

    fill(dist[0], dist[MAXRC+1], INF);
//    printMat(dist[0]);
//    cout<<endl<<bfs()<<endl<<endl;
//    printMat(dist[0]);
    cout<<bfs()<<endl;
    return 0;
}