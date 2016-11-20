//---ŽŽ‚µŠ„‚è‘f””»’è O(ãn)
bool isPrime(int n){
    for (int i = 2; i*i<=n; ++i) {
        if(n%i==0)return false;
    }
    return n!=1;
}
//---ƒGƒ‰ƒgƒXƒeƒlƒX‚Ì‚Ó‚é‚¢  nˆÈ‰º‚Ì‘f”‚ð—ñ‹“--------------- O(nlog(logn))
vector<LL> getPrimesEratos(LL n){ 
    LL rootN= static_cast<long>(sqrt(n));
    bool prime[n+1];
    fill(prime,prime+n+1,true);
    prime[0]=prime[1]=false;
    for (LL i = 2; i <= rootN ; i++) {  //ãn‚ð’´‚¦‚È‚¢‚·‚×‚Ä‚Ì‘f”‚ÅŠ„‚èØ‚ê‚È‚¯‚ê‚În‚Í‘f”
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

//‘fˆö”•ª‰ð
map<int, int> primeDecomposition(LL num, vector<LL> &primes) {
    LL tmp = num;
    map<int, int> res;

    if (num < 2)return res;

    for (int i = 0; i < primes.size(); ++i) {
        while (tmp % primes[i] == 0) {
            tmp /= primes[i];
            res[primes[i]]++;
        }
    }
    if (tmp > 1)
        res[tmp]++;
    return res;
}

int countDivisor(map<int, int> decomposed) {
    int counter = 1;
    for (auto it = decomposed.begin(); it != decomposed.end(); it++) {
        counter *= it->second != 0 ? it->second + 1 : 1;
    }
    return counter;
}