uint64_t basicFact(uint64_t n) {
    if (n > 1)
        return n * fac(n-1);
    else
        return 1;
}
uint64_t basicComb(uint64_t n, uint64_t k) {
    return basicFact(n) / (basicFact(k) * basicFact(n-k));
}
//-------------------
uint64_t goodComb(uint64_t n, uint64_t k) { //結果がuint64内ならオーバーフローしない
    uint64_t r = 1;
    for (uint64_t d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}
//--Euclid--
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
//---エラトステネスのふるい  n以下の素数を列挙---------------
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


//------UnionFind---------
struct UnionFind {
    vector<int> data;

    UnionFind(int size) : data(size, -1) {}

    bool unite(int x, int y) {   //併合
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }

    bool isSame(int x, int y) {    //同じ集合か判定
        return root(x) == root(y);
    }

    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    int size(int x) {
        return -data[root(x)];
    }
};
//--------------