//階乗
uint64_t basicFact(uint64_t n) {
    if (n > 1)
        return n * fac(n-1);
    else
        return 1;
}
//組み合わせ
uint64_t basicComb(uint64_t n, uint64_t k) {
    return basicFact(n) / (basicFact(k) * basicFact(n-k));
}
//---結果がuint64内ならオーバーフローしない組み合わせ計算----------------
uint64_t goodComb(uint64_t n, uint64_t k) { 
    uint64_t r = 1;
    for (uint64_t d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}
//素因数分解を使った組み合わせ計算.mod下でも動作する
//http://qiita.com/HirotoKagotani/items/a0ab4436116adc94ca46
LL modComb(LL n, LL k, LL mod) {

    vector<LL> primes=getPrimesEratos(n);
    vector<pair<LL,LL>> res;
    for (LL i = 0; i < primes.size(); i++) {
        LL resTmp=0;
        const LL tmpPrime=primes.at(i);
        for (LL j = tmpPrime; j <= n; j *= tmpPrime) { //ルジャンドル 　[n/(p^i)]↓　i:1~∞
            resTmp += n / j;
            if (j <= n - k) resTmp -= (n - k) / j;
            if (j <= k) resTmp -= k / j;
        }
        res.push_back(MP(tmpPrime,resTmp));
    }

    LL result = 1;
    for (LL i = 0; i < res.size(); i++) {
        LL tmpPrime=res.at(i).first;
        LL tmpNum=res.at(i).second;
        for (int j = 0; j < tmpNum; j++) {
            result *= tmpPrime;
            result %= mod;
        }
    }
    return result;
}
//------------------



