#include <climits>
#include <random>
//メルセンヌ・ツイスタよりも高速な乱数生成
//C++11以上
class xor128{
public:
    static constexpr unsigned min(){ return 0u; }   // 乱数の最小値
    static constexpr unsigned max(){ return UINT_MAX; } // 乱数の最大値
    unsigned operator()(){ return random(); }
    xor128();
    xor128(unsigned s){ w=s; }  // 与えられたシードで初期化
private:
    unsigned x=123456789u,y=362436069u,z=521288629u,w;
    unsigned random();
};
xor128::xor128(){
    // シードが与えられない時は、
    // システムのハードウェアエントロピーソースからシードを生成
    std::random_device rd; 
    w=rd();

    for(int i=0;i<10;i++){  // 数回空読み(不要?)
        random();
    }
}
unsigned xor128::random(){
    unsigned t;
    t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}