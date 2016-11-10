//--Euclidの互除法--
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
//---試し割り素数判定 O(√n)
bool isPrime(int n){
    for (int i = 2; i*i<=n; ++i) {
        if(n%i==0)return false;
    }
    return n!=1;
}
//---エラトステネスのふるい  n以下の素数を列挙--------------- O(nlog(logn))
vector<LL> getPrimesEratos(LL n){ 
    LL rootN= static_cast<long>(sqrt(n));
    bool prime[n+1];
    fill(prime,prime+n+1,true);
    prime[0]=prime[1]=false;
    for (LL i = 2; i <= rootN ; i++) {  //√nを超えないすべての素数で割り切れなければnは素数
        if(prime[i]) {
            for (LL j = i * 2; j <= n; j+=i) prime[j] = false;
        }

    }
    vector<LL> res;
    for(LL i=0;i<=n;i++){
        if(prime[i])
            res.push_back(i);
    }
    return res;
}

//素因数分解
map<LL, LL> primeDecomposition(LL num, vector<LL> &primes) {
    map<LL, LL> res;
    for (int i = 0; i < primes.size(); ++i) {
        while (num % primes[i] == 0) {
            num /= primes[i];
            res[primes[i]]++;
        }
    }
    printMap(res);
    return res;
}
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

