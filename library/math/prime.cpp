//試し割りによる素数判定
bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)return false;
    }
    return n != 1;
}

//エラトステネスの篩による素数判定 O( n log( log n ) )
vector <LL> getPrimesEratos(LL n) {
    LL rootN = static_cast<long>(sqrt(n));
    bool prime[n + 1];
    fill(prime, prime + n + 1, true);
    prime[0] = prime[1] = false;
    for (LL i = 2; i <= rootN; i++) {
        if (prime[i]) {
            for (LL j = i * 2; j <= n; j += i) prime[j] = false;
        }

    }
    vector <LL> res;
    for (LL i = 0; i <= n; i++) {
        if (prime[i])
            res.push_back(i);
    }
    return res;
}

//素因数分解
map<int, int> primeDecomposition(LL num, vector <LL> &primes) {
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

//2以上の約数の数え上げ   O( 素因数の数 )
//引数は素因数分解の結果
int countDivisor(map<int, int> decomposed) {
    int counter = 1;
    for (auto it = decomposed.begin(); it != decomposed.end(); it++) {
        counter *= it->second != 0 ? it->second + 1 : 1;
    }
    return counter;
}