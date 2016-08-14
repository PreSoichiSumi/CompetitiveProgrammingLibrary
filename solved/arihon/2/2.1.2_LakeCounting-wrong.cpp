#include <iostream>

using namespace std;

const int MAX_N = 100;
int n, m;
char lake[MAX_N+1][MAX_N+1];
int count = 0;

bool isValidPosition(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}


void dfsUpdate(int i, int j) {
    if (!isValidPosition(i, j))
        return;
    if (lake[i][j]=='W'){
        lake[i][j]='.';
        for (int k = i-1; k <=i+1; k++) {
            for (int l = j-1; l <=j+1 ; l++) {
                if(k==l)continue;
                dfsUpdate(k,l);
            }
        }
    }
}

void update(int i, int j) {
    if (lake[i][j] == 'W') {
        lake[i][j] = 'd';
        count++;
        for (int k = i-1; k <=i+1; k++) {
            for (int l = j-1; l <=j+1 ; l++) {
                if(k==i && l==j)continue;
                dfsUpdate(k,l);
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
}


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s",&lake[i][0]);
    }
    printLakes();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            update(i, j);
        }
    }
    printLakes();
    cout << count << endl;
    return 0;
}

