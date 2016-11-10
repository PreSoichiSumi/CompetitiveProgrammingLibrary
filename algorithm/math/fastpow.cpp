//------繰り返し二乗法
LL fastPow(LL x,LL n){ // O(logN)
    LL res=1;
    while(n>0){
        if(n&1)res=res*x;
        x=x*x;
        n>>=1;
    }
    return res;
}
