#include <iostream>

using namespace std;

const int MAX_N = 100;
int n, m;
char lake[MAX_N+1][MAX_N+1];
int count = 0;

bool isValidPosition(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}


void dfs(int i, int j) {
    if (isValidPosition(i,j) && lake[i][j]=='W'){
        lake[i][j]='.';
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1 ; dj++) {
                int x=i+di,y=j+dj;
                dfs(x, y);
            }
        }
    }
}

void printLakes(){
    for (int i = 0; i <n ; i++) {
        for (int j = 0; j <m ; j++) {
            cout<<lake[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s",&lake[i][0]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lake[i][j] == 'W') {
                dfs(i,j);
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}

