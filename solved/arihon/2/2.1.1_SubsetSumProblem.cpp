#include <iostream>

using namespace std;

const int MAX_N=20;
int n,k;
int a[MAX_N];
bool dfs(int i, int sum){
    if(i==n)
        return sum==k;

    if(dfs(i+1,sum))
        return true;

    if(dfs(i+1,sum+a[i]))
        return true;

    return false;
}

void solve(){
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    if(dfs(0,0)){
        cout << "yes" <<endl;
    } else{
        cout<<"no"<< endl;
    }
}

int main() {
    solve();
    return 0;
}
