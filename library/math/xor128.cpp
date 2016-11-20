#include <climits>
#include <random>
//メルセンヌ・ツイスタの2-3倍ほど早い乱数生成アルゴリズム
//usage: xor128 xs(seed); num=xs();
//詳細： http://kitayuta.hatenablog.com/entry/2014/11/15/230145
class xor128{
public:
    static constexpr unsigned min(){ return 0u; }//最小値
    static constexpr unsigned max(){ return UINT_MAX; }//最大値
    unsigned operator()(){ return random(); }//ファンクタ
    xor128();
    xor128(unsigned s){ w=s; }  //シード
private:
    unsigned x=123456789u,y=362436069u,z=521288629u,w;
    unsigned random();
};
xor128::xor128(){
    std::random_device rd; //ハードウェアエントロピーソースからシード生成
    w=rd();

    for(int i=0;i<10;i++){//空読み 不要かも
        random();
    }
}
unsigned xor128::random(){
    unsigned t;
    t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}