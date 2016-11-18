//---‚µŠ„‚è‘f””»’è O(ãn)
bool isPrime(int n){
    for (int i = 2; i*i<=n; ++i) {
        if(n%i==0)return false;
    }
    return n!=1;
}
//---ƒGƒ‰ƒgƒXƒeƒlƒX‚Ì‚Ó‚é‚¢  nˆÈ‰º‚Ì‘f”‚ğ—ñ‹“--------------- O(nlog(logn))
vector<LL> getPrimesEratos(LL n){ 
    LL rootN= static_cast<long>(sqrt(n));
    bool prime[n+1];
    fill(prime,prime+n+1,true);
    prime[0]=prime[1]=false;
    for (LL i = 2; i <= rootN ; i++) {  //ãn‚ğ’´‚¦‚È‚¢‚·‚×‚Ä‚Ì‘f”‚ÅŠ„‚èØ‚ê‚È‚¯‚ê‚În‚Í‘f”
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

//‘fˆö”•ª‰ğ
map<LL, LL> primeDecomposition(LL num, vector<LL> &primes) {
    map<LL, LL> res;
    for (int i = 0; i < primes.size(); ++i) {
        while (num % primes[i] == 0) {
            num /= primes[i];
            res[primes[i]]++;
        }
    }
    return res;
}