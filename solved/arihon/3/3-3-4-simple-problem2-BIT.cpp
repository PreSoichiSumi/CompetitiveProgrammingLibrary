#include <climits>
#include <utility>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;
typedef long long LL;
#define MAX_N 100001
#define MAX_Q 100001

int N,Q;
int A[MAX_N+1];
char T[MAX_Q];
int L[MAX_Q],R[MAX_Q],X[MAX_Q];
LL bit0[MAX_N+1],bit1[MAX_N+1];

LL sum(LL *b, int i){
    LL s=0;
    while(i>0){
        s+=b[i];
        i-=i&-i;//iの最後の1のbitのみを残した値 0110->0010, 1100->0100
    }
    return s;
}

void add(LL *b,int i,int v){
    while(i<=N){
        b[i]+=v;
        i+=i&-i;
    }
}

int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    scanf(" %d%d",&N,&Q);
    for (int i = 0; i < N; ++i) {
        scanf("%d",&A[i+1]);
    }
    for (int i = 0; i < Q; ++i) {
        scanf(" %c",&T[i]);
        if(T[i]=='C'){
            scanf(" %d%d%d",&L[i],&R[i],&X[i]);
        }else{
            scanf(" %d%d",&L[i],&R[i]);
        }
    }
    for(int i=1;i<=N;i++){
        add(bit0,i,A[i]);
    }
    for(int i=0;i<Q;i++){
        if(T[i]=='C'){
            add(bit0,L[i],-X[i]*(L[i]-1));
            add(bit1,L[i],X[i]);
            add(bit0,R[i]+1,X[i]*R[i]);
            add(bit1,R[i]+1,-X[i]);
        }else{
            LL res=0;
            res+=sum(bit0,R[i])+sum(bit1,R[i])*R[i];
            res-=sum(bit0,L[i]-1)+sum(bit1,L[i]-1)*(L[i]-1);
            printf("%lld\n",res);
        }
    }
}