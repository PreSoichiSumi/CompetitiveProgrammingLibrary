#include <bits/stdc++.h>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

template<class T, class U>
inline void chmin(T &t, U f) { if (t > f)t = f; }

template<class T, class U>
inline void chmax(T &t, U f) { if (t < f)t = f; }

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/

int dx8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dx4[4] = {0, 0, -1, 1};
int dy4[4] = {-1, 1, 0, 0};
//-----Template---------

char grid[101][101];
int h, w, sakuCount = 0;
string tmp;

bool isValidPos(int x, int y) {
    return 0 <= x && x < w && 0 <= y && y < h;
}
//柵：#　外周柵：o　外周柵2:e　なし：.　チェック済み：x
void putSaku(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx4[i];
        int newY = y + dy4[i];
        if (isValidPos(newX,newY) && grid[newX][newY] != '#' && grid[newX][newY]!='X') {
            grid[newX][newY] = '#';
            sakuCount++;
        }
    }
}
void innerDFS(int x,int y){
    if(grid[x][y]=='#'){
        sakuCount--;
    }
    grid[x][y]='x';
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx4[i];
        int newY = y + dy4[i];
        if (isValidPos(newX,newY) && (grid[newX][newY]!='o' && grid[newX][newY]!='e' && grid[newX][newY]!='x')){   //柵2,3でない，または調べ済みでないなら
            innerDFS(newX,newY);
        }
    }
}
void deleteSaku(int x, int y) {
    int nowX = x, nowY = y;
    grid[x][y]='o';
    int lastI=0;
    bool flag=true;
    while (flag) {
        for (int i = 0; i < 8; ++i) {
            int nowI = (lastI + i) % 8;
            int tmpX= nowX + dx8[nowI];
            int tmpY= nowY + dy8[nowI];
            if (isValidPos(tmpX,tmpY) && grid[tmpX][tmpY]=='#'){//さくにきたら
                grid[tmpX][tmpY]='o';
                nowX=tmpX; nowY=tmpY; lastI=(nowI+4+1)%8; //更新
                break;
            }else if(isValidPos(tmpX,tmpY) && grid[tmpX][tmpY]=='o'){//1週したら
                flag=false;
                break;
            }
        }
    }
    flag=true;
    nowX=x; nowY=y; lastI=0;
    grid[x][y]='e';
    while(flag){
        for (int i = 0; i < 8; ++i) {
            int nowI = (lastI + i) % 8;
            int tmpX= nowX + dx8[nowI];
            int tmpY= nowY + dy8[nowI];
            if (isValidPos(tmpX,tmpY) && grid[tmpX][tmpY]=='o'){//まず外周探し
                grid[tmpX][tmpY]='e';
                innerDFS(nowX+dx8[(lastI+i+1)%8],nowY+dy8[(lastI+i+1)%8]); //1つ入ったところからDFS
                nowX=tmpX; nowY=tmpY; lastI=(nowI+4+1)%8; //更新
                break;
            }else if(isValidPos(tmpX,tmpY) && grid[tmpX][tmpY]=='e'){
                flag=false;
                break;
            }
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin >> h >> w;
    for(int j=0;j<h;++j){
        for(int i=0;i<w;++i){
            grid[i][j]='.';
        }
    }
    bool cannotPlaceFlag=false;
    for (int j = 0; j < h; ++j) {
        cin >> tmp;
        for (int i = 0; i < tmp.length(); ++i) {//==w
            if (tmp[i] == 'X') {
                if(i==0 || i==w-1 || j==0 || j==h-1)
                    cannotPlaceFlag=true;
                grid[i][j] = 'X';
            }
        }
    }
    for (int j = 0; j < h; ++j) {
        for (int i = 0; i < w; ++i) {//==w
            if (grid[i][j] == 'X') {
                putSaku(i, j);
            }
        }
    }
    if(!cannotPlaceFlag){
        for (int j = 0; j < h; ++j) {
            for (int i = 0; i < w; ++i) {
                if (grid[i][j] == '#') {
                    deleteSaku(i, j);
                }
            }
        }
        cout<<sakuCount<<endl;
    }else{
        cout<<-1<<endl;
    }

}